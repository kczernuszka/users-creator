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

#ifndef SRC_ACCOUNT_CREATOR_STRINGS_BUILDER_H_
#define SRC_ACCOUNT_CREATOR_STRINGS_BUILDER_H_

#include <string>

namespace users_creator {
namespace account_creator {

class StringsBuilder {
 public:
  StringsBuilder(std::string forename, std::string surname);
  std::string getLogin();
  std::string getHomeDirectory(std::string root_home);
  std::string generatePassword(int password_len = 8);
  void changeLogin();

 private:
  std::string login;
  int sufix;
};

}  // namespace account_creator
}  // namespace users_creator

#endif  // SRC_ACCOUNT_CREATOR_STRINGS_BUILDER_H_
