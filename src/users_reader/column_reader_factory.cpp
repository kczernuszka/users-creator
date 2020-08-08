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

#include "users_reader/column_reader_factory.h"

namespace users_creator {
namespace users_reader {

std::unique_ptr<IColumnReader> ColumnReader::getColumnReader(std::string file) {
  std::string extension = getFileExtension(file);
  if (extension == "xlsx")
    return std::make_unique<XlsxColumnReader>();
  else
    return nullptr;
}

std::string ColumnReader::getFileExtension(std::string file) {
  std::size_t found = file.find(".");
  return file.substr(found+1);
}

}  // namespace users_reader
}  // namespace users_creator
