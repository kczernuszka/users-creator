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

#include "src/config_parser/config_parser.h"
#include "src/config_parser/file_parser.h"
#include "src/config_parser/cmd_parser.h"

int main(int argc, char *argv[]) {
  xlstousers::config_parser::ConfigParser config_parser{argc, argv};
  auto program_settings = config_parser.getConfigFromCmd();
  auto config = config_parser.getConfigFromFile(program_settings->config_file);
  return 0;
}
