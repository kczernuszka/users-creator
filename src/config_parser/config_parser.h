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

#ifndef SRC_CONFIG_PARSER_CONFIG_PARSER_H_
#define SRC_CONFIG_PARSER_CONFIG_PARSER_H_

#include <string>
#include <memory>

#include "file_parser.h"
#include "cmd_parser.h"

namespace xlstousers {
namespace config_parser {

class ConfigParser {
 public:
  ConfigParser(int argc, char **argv);
  ~ConfigParser() = default;
  std::unique_ptr<Config> getConfigFromFile(std::string file);
  std::unique_ptr<ProgramSettings> getConfigFromCmd();

 private:
  std::unique_ptr<FileParser> file_parser;
  std::unique_ptr<CmdParser> cmd_parser;
};

}  // namespace config_parser
}  // namespace xlstousers

#endif  // SRC_CONFIG_PARSER_CONFIG_PARSER_H_
