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

#ifndef SRC_CONFIG_PARSER_OPTION_VALUE_PARSER_H_
#define SRC_CONFIG_PARSER_OPTION_VALUE_PARSER_H_

#include <fstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

const char* const VALUES_DELIMITER = ",";

namespace users_creator {
namespace config_parser {

std::vector<std::string> valueToVector(std::string value);

}  // namespace config_parser
}  // namespace users_creator

#endif  // SRC_CONFIG_PARSER_OPTION_VALUE_PARSER_H_
