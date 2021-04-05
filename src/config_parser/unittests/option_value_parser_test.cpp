// Copyright 2020-2021, Karol Czernuszka
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

#include "config_parser/option_value_parser.h"

TEST(OptionValueParserTest, MultiValuesToVector) {
  std::string value = "name" + std::string(VALUES_DELIMITER) + "surname" +
                      std::string(VALUES_DELIMITER) + "workplace";

  auto vectorStrings = users_creator::config_parser::valueToVector(value);

  if (vectorStrings.size() != 3) FAIL();
  EXPECT_EQ(vectorStrings[0], "name");
  EXPECT_EQ(vectorStrings[1], "surname");
  EXPECT_EQ(vectorStrings[2], "workplace");
}
