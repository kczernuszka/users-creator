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

#ifndef SRC_CONFIG_PARSER_FILE_PARSER_H_
#define SRC_CONFIG_PARSER_FILE_PARSER_H_

#include <map>
#include <memory>
#include <iostream>
#include <string>
#include <boost/program_options.hpp>

#include <config_parser/file_options.h>
#include <config_parser/config.h>

#include "option_value_parser.h"

namespace xlstousers {
namespace config_parser {

namespace po = boost::program_options;

class FileParser {
 public:
  std::unique_ptr<Config> getConfig(std::string file);

 private:
  po::variables_map getVariablesMap(po::options_description desc,
                                    std::string file);
  po::options_description setOptions(std::map<std::string, std::string> values);
  std::unique_ptr<Config> getValues(po::variables_map vm);
};

}  // namespace config_parser
}  // namespace xlstousers

#endif  // SRC_CONFIG_PARSER_FILE_PARSER_H_
