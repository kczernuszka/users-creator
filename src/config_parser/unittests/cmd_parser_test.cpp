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

#include "config_parser/config_parser.h"

class CmdParserTest : public ::testing::Test {
 protected:
  const char FULL_OPT_PREFIX[3] = "--";
  const char SHORT_OPT_PREFIX[2] = "-";
};

TEST_F(CmdParserTest, DefaultValuesAreSet) {
  char **argv = {}; int argc = 0;
  xlstousers::config_parser::ConfigParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfigFromCmd();

  if (!settings) FAIL();
  EXPECT_EQ(settings->config_file, DEFAULT_CONFIG_PATH);
}

TEST_F(CmdParserTest, ParseCmdParameterWithValue) {
  char arg0[] = "xlstousers";
  std::string arg1 = FULL_OPT_PREFIX + std::string(CONFIG_FILE);
  char arg2[] =  "test";
  char *argv[] = {arg0, &arg1[0], arg2}; int argc = 3;
  xlstousers::config_parser::ConfigParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfigFromCmd();

  if (!settings) FAIL();
  EXPECT_EQ(settings->config_file, "test");
}

TEST_F(CmdParserTest, ParseShortNameCmdParameters) {
  char arg0[] = "xlstousers";
  std::string arg1 = SHORT_OPT_PREFIX + std::string(INTERACTIVE_SHORT);
  std::string arg2 = SHORT_OPT_PREFIX + std::string(TEST_MODE_SHORT);
  char *argv[] = {arg0, &arg1[0], &arg2[0]}; int argc = 3;
  xlstousers::config_parser::ConfigParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfigFromCmd();

  if (!settings) FAIL();
  EXPECT_TRUE(settings->interactive_mode);
  EXPECT_TRUE(settings->test_mode);
  EXPECT_FALSE(settings->quota);
}

TEST_F(CmdParserTest, ParseFullNameCmdParameters) {
  char arg0[] = "xlstousers";
  std::string arg1 = FULL_OPT_PREFIX + std::string(INTERACTIVE);
  std::string arg2 = FULL_OPT_PREFIX + std::string(TEST_MODE);
  char *argv[] = {arg0, &arg1[0], &arg2[0]}; int argc = 3;
  xlstousers::config_parser::ConfigParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfigFromCmd();

  if (!settings) FAIL();
  EXPECT_TRUE(settings->interactive_mode);
  EXPECT_TRUE(settings->test_mode);
  EXPECT_FALSE(settings->quota);
}

TEST_F(CmdParserTest, ParseUnknownCmdParameter) {
  char arg0[] = "xlstousers";
  char arg1[] = "--asdf";
  char *argv[] = {arg0, arg1}; int argc = 2;
  xlstousers::config_parser::ConfigParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfigFromCmd();

  EXPECT_FALSE(settings);
}

TEST_F(CmdParserTest, ParseCmdParameterWithoutMandatoryValue) {
  char arg0[] = "xlstousers";
  std::string arg1 = FULL_OPT_PREFIX + std::string(CONFIG_FILE);
  char *argv[] = {arg0, &arg1[0]}; int argc = 2;
  xlstousers::config_parser::ConfigParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfigFromCmd();

  EXPECT_FALSE(settings);
}

TEST_F(CmdParserTest, ParseValueWithoutOption) {
  char arg0[] = "xlstousers";
  char arg1[] = "test.xls";
  char *argv[] = {arg0, arg1}; int argc = 2;
  xlstousers::config_parser::ConfigParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfigFromCmd();

  if (!settings) FAIL();
  EXPECT_EQ(settings->xls_file, "test.xls");
}
