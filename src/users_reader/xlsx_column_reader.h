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

#ifndef SRC_USERS_READER_XLSX_COLUMN_READER_H_
#define SRC_USERS_READER_XLSX_COLUMN_READER_H_

#include <OpenXLSX/OpenXLSX.h>

#include <memory>
#include <vector>
#include <string>

#include "users_reader/i_column_reader.h"

namespace xlstousers {
namespace users_reader {

class XlsxColumnReader : public IColumnReader {
 public:
  XlsxColumnReader() = default;
  ~XlsxColumnReader();
  bool openFile(std::string file) override;
  void closeFile() override;
  std::vector<std::string> getColumn(std::string header) override;
 private:
  std::unique_ptr<OpenXLSX::XLWorksheet> worksheet;
  OpenXLSX::XLDocument document;

  OpenXLSX::XLCellReference getHeaderLocation(std::string header);
};

}  // namespace users_reader
}  // namespace xlstousers

#endif  // SRC_USERS_READER_XLSX_COLUMN_READER_H_
