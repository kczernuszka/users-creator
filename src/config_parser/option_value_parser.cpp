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

#include "config_parser/option_value_parser.h"

namespace users_creator {
namespace config_parser {

std::vector<std::string> valueToVector(std::string value) {
  std::vector<std::string> vectorStrings;
  boost::char_separator<char> separator{VALUES_DELIMITER};
  boost::tokenizer<boost::char_separator<char>> tokenizer{value, separator};

  for (const auto &token : tokenizer) {
    vectorStrings.push_back(token);
  }
  return vectorStrings;
}

}  // namespace config_parser
}  // namespace users_creator
