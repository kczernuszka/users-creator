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

#include "users_reader/users_reader.h"

namespace xlstousers {
namespace users_reader {

UsersReader::UsersReader(std::string file) :
    column_reader{ColumnReader::getColumnReader(file)} {}

ColumnsValues UsersReader::getColumnsValues(
    const std::vector<std::string> &headers) {
  ColumnsValues columns_values;
  for (auto &header : headers)
    columns_values.push_back(column_reader->getColumn(header));
  if (columnsAreTheSameLength(columns_values))
    return columns_values;
  else
    return ColumnsValues();
}

bool UsersReader::columnsAreTheSameLength(ColumnsValues columns_values) {
  auto size_first_column = columns_values.front().size();
  if (std::all_of(columns_values.begin(), columns_values.end(),
      [size_first_column](const std::vector<std::string> column)
      {return column.size() == size_first_column;}))
    return true;
  else
    return false;
}

}  // namespace users_reader
}  // namespace xlstousers
