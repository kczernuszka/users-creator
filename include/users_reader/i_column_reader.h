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

#ifndef INCLUDE_USERS_READER_I_COLUMN_READER_H_
#define INCLUDE_USERS_READER_I_COLUMN_READER_H_

#include <vector>
#include <string>

namespace xlstousers {
namespace users_reader {

class IColumnReader {
 public:
  virtual bool openFile(std::string file) = 0;
  virtual void closeFile() = 0;
  virtual std::vector<std::string> getColumn(std::string header) = 0;
};

}  // namespace users_reader
}  // namespace xlstousers

#endif  // INCLUDE_USERS_READER_I_COLUMN_READER_H_
