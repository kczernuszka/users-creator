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

#ifndef SRC_ACCOUNT_CREATOR_FILE_CREATOR_H_
#define SRC_ACCOUNT_CREATOR_FILE_CREATOR_H_

#include <fstream>
#include <string>
#include <vector>
#include <tuple>

namespace users_creator {
namespace account_creator {

using Users = std::vector<std::tuple<std::string, std::string> >;

const int LOGIN = 0;
const int PASSWORD = 1;

class FileCreator {
 public:
  explicit FileCreator(std::string file);
  ~FileCreator();
  bool createFileWithPasswords(Users users);
 private:
  std::ofstream file;
};

}  // namespace account_creator
}  // namespace users_creator

#endif  // SRC_ACCOUNT_CREATOR_FILE_CREATOR_H_
