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

#include "config_parser/config_parser.h"
#include "users_reader/users_reader.h"

int main(int argc, char *argv[]) {
  users_creator::config_parser::ConfigParser config_parser{argc, argv};
  auto program_settings = config_parser.getConfigFromCmd();
  auto config = config_parser.getConfigFromFile(program_settings->config_file);
  users_creator::users_reader::UsersReader
      users_reader{"test.xlsx"};
  auto columns_values = users_reader.getColumnsValues(config->columns);
  return 0;
}
