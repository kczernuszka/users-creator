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

#include "config_parser/config_parser.h"
#include "config_parser/config.h"

namespace users_creator {
namespace config_parser {

ConfigParser::ConfigParser(int argc, char **argv) :
    file_parser{new FileParser}, cmd_parser{new CmdParser{argc, argv}} {}

std::unique_ptr<Config> ConfigParser::getConfigFromFile(std::string file) {
  return file_parser->getConfig(file);
}

std::unique_ptr<ProgramSettings> ConfigParser::getConfigFromCmd() {
  return cmd_parser->getConfig();
}

}  // namespace config_parser
}  // namespace users_creator
