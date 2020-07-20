#include <gtest/gtest.h>

#include "../option_value_parser.h"

using namespace xlstousers::config_parser;

TEST(OptionValueParserTest, MultiValuesToVector) {
  std::string value = "name" + std::string(VALUES_DELIMITER) + "surname" +
                      std::string(VALUES_DELIMITER) + "workplace";

  auto vectorStrings = valueToVector(value);

  if(vectorStrings.size() != 3) FAIL();
  EXPECT_EQ(vectorStrings[0], "name");
  EXPECT_EQ(vectorStrings[1], "surname");
  EXPECT_EQ(vectorStrings[2], "workplace");
}