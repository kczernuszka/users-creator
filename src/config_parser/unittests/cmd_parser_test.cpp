#include <gtest/gtest.h>

#include "../cmd_parser.h"

class CmdParserTest : public ::testing::Test {
 protected:
  const char FULL_OPT_PREFIX[3] = "--";
  const char SHORT_OPT_PREFIX[2] = "-";
};

TEST_F(CmdParserTest, DefaultValuesAreSet) {
  char **argv = {}; int argc = 0;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  if (!settings) FAIL();
  EXPECT_EQ(settings->config_file, DEFAULT_CONFIG_PATH);
}

TEST_F(CmdParserTest, ParseCmdParameterWithValue) {
  char arg0[] = "xlstousers";
  std::string arg1 = FULL_OPT_PREFIX + std::string(CONFIG_FILE);
  char arg2[] =  "test";
  char *argv[] = {arg0, &arg1[0], arg2}; int argc = 3;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  if (!settings) FAIL();
  EXPECT_EQ(settings->config_file, "test");
}

TEST_F(CmdParserTest, ParseShortNameCmdParameters) {
  char arg0[] = "xlstousers";
  std::string arg1 = SHORT_OPT_PREFIX + std::string(INTERACTIVE_SHORT);
  std::string arg2 = SHORT_OPT_PREFIX + std::string(TEST_MODE_SHORT);
  char *argv[] = {arg0, &arg1[0], &arg2[0]}; int argc = 3;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

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
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  if (!settings) FAIL();
  EXPECT_TRUE(settings->interactive_mode);
  EXPECT_TRUE(settings->test_mode);
  EXPECT_FALSE(settings->quota);
}

TEST_F(CmdParserTest, ParseUnknownCmdParameter) {
  char arg0[] = "xlstousers";
  char arg1[] = "--asdf";
  char *argv[] = {arg0, arg1}; int argc = 2;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  EXPECT_FALSE(settings);
}

TEST_F(CmdParserTest, ParseCmdParameterWithoutMandatoryValue) {
  char arg0[] = "xlstousers";
  std::string arg1 = FULL_OPT_PREFIX + std::string(CONFIG_FILE);
  char *argv[] = {arg0, &arg1[0]}; int argc = 2;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  EXPECT_FALSE(settings);
}

TEST_F(CmdParserTest, ParseValueWithoutOption) {
  char arg0[] = "xlstousers";
  char arg1[] = "test.xls";
  char *argv[] = {arg0, arg1}; int argc = 2;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  if (!settings) FAIL();
  EXPECT_EQ(settings->xls_file, "test.xls");
}
