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

#ifndef SRC_CONFIG_PARSER_CMD_PARSER_H_
#define SRC_CONFIG_PARSER_CMD_PARSER_H_

#include <memory>
#include <string>
#include <boost/program_options.hpp>

#include <config_parser/config.h>
#include <config_parser/cmd_options.h>

namespace xlstousers {
namespace config_parser {

namespace po = boost::program_options;

class CmdParser {
 public:
  CmdParser(int argc, char **argv);
  std::unique_ptr<ProgramSettings> getConfig();
 private:
  int argc; char **argv;

  po::options_description setOptions();
  po::variables_map getVariablesMap(po::options_description desc);
  std::unique_ptr<ProgramSettings> getValues(po::variables_map vm);
  std::string createOptionName(const std::string full_name,
                               const std::string short_name);
};

}  // namespace config_parser
}  // namespace xlstousers

#endif  // SRC_CONFIG_PARSER_CMD_PARSER_H_
