// Copyright 2020 Karol Czernuszka
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

#ifndef INCLUDE_CONFIG_PARSER_CONFIG_H_
#define INCLUDE_CONFIG_PARSER_CONFIG_H_

#include <map>
#include <vector>
#include <string>

namespace users_creator {
namespace config_parser {

struct UidsRange {
  int min_uid;
  int max_uid;
};

struct User {
  UidsRange uids_range;
  int gid;
  std::string home;
  int change;
  std::string class_name;
  std::string shell;
  int expire;
};

struct Quota {
  int block_hard_limit;
  int block_soft_limit;
  int inodes_hard_limit;
  int inodes_soft_limit;
  int block_time;
  int inodes_time;
  std::string path_quota;
};

struct ProgramSettings {
  std::string xls_file;
  std::string config_file;
  bool interactive_mode;
  bool test_mode;
  bool quota;
};

struct Config {
  std::vector<std::string> columns;
  int password_lenght;
  User user;
  Quota quota;
};

}  // namespace config_parser
}  // namespace users_creator

#endif  // INCLUDE_CONFIG_PARSER_CONFIG_H_
