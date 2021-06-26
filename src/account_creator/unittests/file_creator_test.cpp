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

#include "account_creator/file_creator.h"

using FileCreator = users_creator::account_creator::FileCreator;
using Users = users_creator::account_creator::Users;

const char FILE_CONTENT[] = "J.Nowak vzmkBJoT\n"
    "K.Kowalski xpdrrY5m\nA.Nowak On2S9oaR\n";

class FileCreatorTest : public ::testing::Test {
 protected:
  FileCreator file_creator{FileCreator("test.txt")};
  Users users = {
      {"J.Nowak", "vzmkBJoT"},
      {"K.Kowalski", "xpdrrY5m"},
      {"A.Nowak", "On2S9oaR"}
  };

  ~FileCreatorTest() {
    remove("test.txt");
  }
};

TEST_F(FileCreatorTest, createFileWithPasswords) {
  file_creator.createFileWithPasswords(users);
  std::ifstream file("test.txt");
  std::stringstream text;
  text << file.rdbuf();

  EXPECT_EQ(text.str(), FILE_CONTENT);
}

TEST_F(FileCreatorTest, overrideFile) {
  std::ofstream wfile("test.txt");
  wfile << "Random text";
  wfile.close();

  file_creator.createFileWithPasswords(users);
  std::ifstream file("test.txt");
  std::stringstream text;
  text << file.rdbuf();

  EXPECT_EQ(text.str(), FILE_CONTENT);
}
