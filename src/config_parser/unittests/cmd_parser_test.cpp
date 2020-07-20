#include <gtest/gtest.h>

#include "../cmd_parser.h"

class CmdParserTest : public ::testing::Test {

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
  char arg1[] = "--config";
  char arg2[] =  "test";
  char *argv[] = {arg0, arg1, arg2}; int argc = 3;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  if (!settings) FAIL();
  EXPECT_EQ(settings->config_file, "test");
}

TEST_F(CmdParserTest, ParseShortNameCmdParameters) {
  char arg0[] = "xlstousers";
  char arg1[] = "-i";
  char arg2[] = "-t";
  char *argv[] = {arg0, arg1, arg2}; int argc = 3;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  if (!settings) FAIL();
  EXPECT_TRUE(settings->interactive_mode);
  EXPECT_TRUE(settings->test_mode);
  EXPECT_FALSE(settings->quota);  
}

TEST_F(CmdParserTest, ParseFullNameCmdParameters) {
  char arg0[] = "xlstousers";
  char arg1[] = "--interactive";
  char arg2[] = "--test";
  char *argv[] = {arg0, arg1, arg2}; int argc = 3;
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

TEST_F(CmdParserTest, ParseFlagCmdParameterWithValue) {
  char arg0[] = "xlstousers";
  char arg1[] = "-i unecessaryValue";
  char *argv[] = {arg0, arg1}; int argc = 2;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  EXPECT_FALSE(settings);
}

TEST_F(CmdParserTest, ParseCmdParameterWithoutMandatoryValue) {
  char arg0[] = "xlstousers";
  char arg1[] = "-c";
  char *argv[] = {arg0, arg1}; int argc = 2;
  xlstousers::config_parser::CmdParser cmd_parser{argc, argv};

  auto settings = cmd_parser.getConfig();

  EXPECT_FALSE(settings);
}
