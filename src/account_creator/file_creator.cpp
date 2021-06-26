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

#include "account_creator/file_creator.h"

namespace users_creator {
namespace account_creator {

FileCreator::FileCreator(std::string file_name) {
  file.open(file_name);
}

FileCreator::~FileCreator() {
  file.close();
}

bool FileCreator::createFileWithPasswords(Users users) {
  if(file.is_open()) {
    for (auto &user : users) {
      file << std::get<LOGIN>(user) << " " <<  std::get<PASSWORD>(user)
          << std::endl;
    }
    return true;
  }
  else {
    return false;
  }
}

}  // namespace account_creator
}  // namespace users_creator
