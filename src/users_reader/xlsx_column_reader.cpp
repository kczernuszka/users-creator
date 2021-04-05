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

#include "users_reader/xlsx_column_reader.h"
#include <iostream>

namespace users_creator {
namespace users_reader {

XlsxColumnReader::~XlsxColumnReader() {
  document.CloseDocument();
}

bool XlsxColumnReader::openFile(std::string file) {
  try {
    document.OpenDocument(file);
    auto name_worksheet = document.Workbook().Sheet(1).Name();
    worksheet = std::make_unique<OpenXLSX::XLWorksheet>(
        document.Workbook().Worksheet(name_worksheet));
  } catch(std::exception error) {
    return false;
  }
  return true;
}

void XlsxColumnReader::closeFile() {
  worksheet.release();
  document.CloseDocument();
}

std::vector<std::string> XlsxColumnReader::getColumn(std::string header) {
  std::vector<std::string> column;
  auto cell = getHeaderLocation(header);
  if (cell.Address() != "") {
    while (cell.Row() != worksheet->LastCell().Row()) {
      cell.SetRow(cell.Row()+1);
      auto cell_value = worksheet->Cell(cell.Address()).Value().AsString();
      if (cell_value != "")
        column.push_back(cell_value);
      else
        break;
    }
  }
  return column;
}

OpenXLSX::XLCellReference XlsxColumnReader::getHeaderLocation(
    std::string header) {
  auto cells_range = worksheet->Range();
    for (auto xl_cell_it = cells_range.begin(); xl_cell_it != cells_range.end();
        ++xl_cell_it) {
      if (xl_cell_it->Value().AsString() == header)
        return xl_cell_it->CellReference();
    }
  return OpenXLSX::XLCellReference(0, 0);
}

}  // namespace users_reader
}  // namespace users_creator
