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

#include "account_creator/strings_builder.h"

using StringsBuilder = users_creator::account_creator::StringsBuilder;

class StringsBuilderTest : public ::testing::Test {
 protected:
  StringsBuilder strings_builder{StringsBuilder("Jan", "Nowak")};
};

TEST_F(StringsBuilderTest, GetLogin) {
  EXPECT_EQ(strings_builder.getLogin(), "J.Nowak");
}

TEST_F(StringsBuilderTest, ChangeLogin) {
  strings_builder.changeLogin();
  EXPECT_EQ(strings_builder.getLogin(), "J.Nowak2");
  strings_builder.changeLogin();
  EXPECT_EQ(strings_builder.getLogin(), "J.Nowak23");
}

TEST_F(StringsBuilderTest, GetHomeDirectory) {
  EXPECT_EQ(strings_builder.getHomeDirectory("/home"), "/home/J.Nowak");
}
