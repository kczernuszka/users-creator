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

#ifndef INCLUDE_USERS_READER_USERS_READER_H_
#define INCLUDE_USERS_READER_USERS_READER_H_

#include <OpenXLSX/OpenXLSX.h>

#include <algorithm>
#include <string>
#include <vector>
#include <memory>

#include "users_reader/i_column_reader.h"

namespace users_creator {
namespace users_reader {

using ColumnsValues = std::vector<std::vector<std::string> >;

class UsersReader {
 public:
  explicit UsersReader(std::string file);
  ~UsersReader();
  ColumnsValues getColumnsValues(const std::vector<std::string> &headers);

 private:
  std::unique_ptr<IColumnReader> column_reader;
  std::string file;

  bool columnsAreTheSameLength(ColumnsValues columns_values);
};

}  // namespace users_reader
}  // namespace users_creator

#endif  // INCLUDE_USERS_READER_USERS_READER_H_
