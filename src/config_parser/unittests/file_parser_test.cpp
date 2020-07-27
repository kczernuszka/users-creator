#include <gtest/gtest.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

#include "../file_parser.h"

class FileParserTest : public ::testing::Test {
 protected:
  xlstousers::config_parser::FileParser parser;

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
  auto config = parser.getConfig("");

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

  auto config = parser.getConfig("config1.txt-test");

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

  auto config = parser.getConfig("config2.txt-test");

  EXPECT_FALSE(config);
}

TEST_F(FileParserTest, ParseFileWithWrongFormat) {
  std::ofstream file{"config4.txt-test"};
  file << "arararararararar,rarara. arararara" << std::endl;
  file.close();

  auto config = parser.getConfig("config4.txt-test");

  EXPECT_FALSE(config);
}

TEST_F(FileParserTest, HandleNonExistentFile) {
  auto config = parser.getConfig("NonExistentFile");

  EXPECT_TRUE(config);
}

TEST_F(FileParserTest, ParseFileWithIncorrectValue) {
  std::ofstream file{"config3.txt-test"};
  file << "password_length=wrongValue";
  file.close();

  auto config = parser.getConfig("config3.txt-test");

  EXPECT_FALSE(config);
}
