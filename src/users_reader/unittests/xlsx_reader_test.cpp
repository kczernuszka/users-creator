// Copyright 2020, Karol Czernuszka
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

#include <fstream>

#include "users_reader/users_reader.h"

class XlsReaderTest : public ::testing::Test {
 protected:
  std::string file{"test.xlsx"};
  std::vector<std::string> headers{"name", "surname"};
  OpenXLSX::XLDocument doc;

  XlsReaderTest() {
    doc.CreateDocument(file);
    auto wks = doc.Workbook().Worksheet("Sheet1");
    wks.Cell("A1").Value() = "name";
    wks.Cell("A2").Value() = "nameValue1";
    wks.Cell("A3").Value() = "nameValue2";
    wks.Cell("B1").Value() = "surname";
    wks.Cell("B2").Value() = "surnameValue1";
    wks.Cell("B3").Value() = "surnameValue2";
    doc.SaveDocument();
    doc.CloseDocument();
  }

  ~XlsReaderTest() {
    remove("test.xlsx");
    remove("test2.xlsx");
    remove("test3.xlsx");
  }

  void copyDocument(std::string srcFile, std::string dstFile) {
    std::ifstream src(srcFile, std::ios::binary);
    std::ofstream dst(dstFile, std::ios::binary);
    dst << src.rdbuf();
  }

  void clearCell(std::string file, std::string address) {
    doc.OpenDocument(file);
    auto wks = doc.Workbook().Worksheet("Sheet1");
    wks.Cell(address).Value().Clear();
    doc.SaveDocument();
    doc.CloseDocument();
  }
};

TEST_F(XlsReaderTest, GetColumnsValues) {
  auto xls_reader = xlstousers::users_reader::UsersReader{file};

  auto columns_values = xls_reader.getColumnsValues(headers);

  if(columns_values.empty()) FAIL();
  EXPECT_EQ(columns_values[0][0], "nameValue1");
  EXPECT_EQ(columns_values[0][1], "nameValue2");
  EXPECT_EQ(columns_values[1][0], "surnameValue1");
  EXPECT_EQ(columns_values[1][1], "surnameValue2");
  EXPECT_TRUE(columns_values[2].empty());
}

TEST_F(XlsReaderTest, GetColumnsValuesIfIsMissingHeader) {
  copyDocument("test.xlsx", "test2.xlsx");
  clearCell("test2.xlsx", "B1");
  auto xls_reader = xlstousers::users_reader::
      UsersReader("test2.xlsx");

  auto columns_values = xls_reader.getColumnsValues(headers);

  EXPECT_TRUE(columns_values.empty());
}

TEST_F(XlsReaderTest, GetValuesFromNotEqualLengthColumns) {
  copyDocument("test.xlsx", "test3.xlsx");
  clearCell("test3.xlsx", "B3");
  auto xls_reader = xlstousers::users_reader::
      UsersReader{"test3.xlsx"};

  auto columns_values = xls_reader.getColumnsValues(headers);

  EXPECT_TRUE(columns_values.empty());
}
