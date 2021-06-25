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

#include "strings_builder/strings_builder.h"

namespace users_creator {
namespace strings_builder {

StringsBuilder::StringsBuilder(std::string forename, std::string surname) {
  login = forename.substr(0, 1) + "." + surname;
}

std::string StringsBuilder::getLogin() {
  return login;
}

std::string StringsBuilder::getHomeDirectory(std::string root_home) {
  return root_home + "/" + login;
}

std::string StringsBuilder::generatePassword(int password_len) {
  const char charset[] = "0123456789"
                   "abcdefghijklmnopqrstuvwxyz"
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string random_password;
  srand(time(0));
  for (int i = 0; i < password_len; i++) {
    random_password.push_back(charset[rand() % (sizeof(charset) - 1)]);
  }
  return random_password;
}

}  // namespace strings_builder
}  // namespace users_creator
