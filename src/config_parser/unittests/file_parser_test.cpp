// Copyright 2020 Karol Czernuszka
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
//

#include <gtest/gtest.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

#include "config_parser/config_parser.h"

class FileParserTest : public ::testing::Test {
 protected:
  xlstousers::config_parser::ConfigParser file_parser{0, {}};

  ~FileParserTest() {
    remove("config1.txt-test");
    remove("config2.txt-test");
    remove("config3.txt-test");
    remove("config4.txt-test");
  }
};

TEST_F(FileParserTest, DefaultValuesAreSet) {
  std::map<std::string, std::string> def_options_val = 
      xlstousers::config_parser::file_options;
  const int default_password_len = std::stoi(def_options_val[PASSWORD_LEN]);
  const std::string default_home = def_options_val[HOME];
  const int default_blocks_hard_limit = std::stoi(
      def_options_val[BLOCKS_HARD_LIMIT]);
  auto config = file_parser.getConfigFromFile("");

  if (!config) FAIL();
  EXPECT_EQ(config->password_lenght, default_password_len);
  EXPECT_EQ(config->user.home, default_home);
  EXPECT_EQ(config->quota.block_hard_limit, default_blocks_hard_limit);
}

TEST_F(FileParserTest, ParseFileWithValidOptionsAndValues) {
  std::ofstream file{"config1.txt-test"};
  file << USER_GID << "=10" << std::endl << PASSWORD_LEN << "=12"
       << std::endl << HOME << "=/home";
  file.close();

  auto config = file_parser.getConfigFromFile("config1.txt-test");

  if (!config) FAIL();
  EXPECT_EQ(config->user.gid, 10);
  EXPECT_EQ(config->password_lenght, 12);
  EXPECT_EQ(config->user.home, "/home");
}

TEST_F(FileParserTest, ParseFileWithIncorrectOption) {
  std::ofstream file{"config2.txt-test"};
  file << MIN_UID << "=2100" << std::endl << "wrongParameter=12" << std::endl
       << MAX_UID << "=7777";
  file.close();

  auto config = file_parser.getConfigFromFile("config2.txt-test");

  EXPECT_FALSE(config);
}

TEST_F(FileParserTest, ParseFileWithWrongFormat) {
  std::ofstream file{"config4.txt-test"};
  file << "arararararararar,rarara. arararara" << std::endl;
  file.close();

  auto config = file_parser.getConfigFromFile("config4.txt-test");

  EXPECT_FALSE(config);
}

TEST_F(FileParserTest, HandleNonExistentFile) {
  auto config = file_parser.getConfigFromFile("NonExistentFile");

  EXPECT_TRUE(config);
}

TEST_F(FileParserTest, ParseFileWithIncorrectValue) {
  std::ofstream file{"config3.txt-test"};
  file << "password_length=wrongValue";
  file.close();

  auto config = file_parser.getConfigFromFile("config3.txt-test");

  EXPECT_FALSE(config);
}
