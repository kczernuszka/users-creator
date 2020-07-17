#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <stdio.h>

#include "../file_parser.h"

class ConfigParserTest : public ::testing::Test {
 protected:
  xlstousers::config_parser::FileParser parser;

  ~ConfigParserTest() {
    remove("config1.txt-test");
    remove("config2.txt-test");
    remove("config3.txt-test");
    remove("config4.txt-test");
  }
};

TEST_F(ConfigParserTest, DefaultValuesAreSet) {
  auto config = parser.getConfig("");

  EXPECT_EQ(config->password_lenght, std::stoi(FILE_OPTIONS[PASSWORD_LEN]));
  EXPECT_EQ(config->user.home, FILE_OPTIONS[HOME]);
  EXPECT_EQ(config->quota.block_hard_limit, 
            std::stoi(FILE_OPTIONS[BLOCKS_HARD_LIMIT]));
}

TEST_F(ConfigParserTest, ParseFileWithValidOptionsAndValues) {
  std::ofstream file{"config1.txt-test"};
  file << "gid=10" << std::endl << "password_length=12" << std::endl 
       << "home_directory=/home";
  file.close();

  auto config = parser.getConfig("config1.txt-test");

  EXPECT_EQ(config->user.gid, 10);
  EXPECT_EQ(config->password_lenght, 12);
  EXPECT_EQ(config->user.home, "/home");
}

TEST_F(ConfigParserTest, ParseFileWithIncorrectOption) {
  std::ofstream file{"config2.txt-test"};
  file << "initial_uid=2100" << std::endl << "wrongParameter=12" << std::endl 
       << "final_uid=7777";
  file.close();

  auto config = parser.getConfig("config2.txt-test");

  EXPECT_FALSE(config);
}

TEST_F(ConfigParserTest, ParseFileWithWrongFormat) {
  std::ofstream file{"config4.txt-test"};
  file << "arararararararar,rarara. arararara" << std::endl;
  file.close();

  auto config = parser.getConfig("config4.txt-test");

  EXPECT_FALSE(config);
}

TEST_F(ConfigParserTest, HandleNonExistentFile) {
  auto config = parser.getConfig("NonExistentFile");

  EXPECT_TRUE(config);
}

TEST_F(ConfigParserTest, ParseFileWithIncorrectValue) {
  std::ofstream file{"config3.txt-test"};
  file << "password_length=wrongValue";
  file.close();

  auto config = parser.getConfig("config3.txt-test");

  EXPECT_FALSE(config);
}
