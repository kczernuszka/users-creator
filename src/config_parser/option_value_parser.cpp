#include "option_value_parser.h"

namespace xlstousers {
namespace config_parser {

std::vector<std::string> valueToVector(std::string value) {
  std::vector<std::string> vectorStrings;
  boost::char_separator<char> separator{VALUES_DELIMITER};
  boost::tokenizer<boost::char_separator<char>> tokenizer{value, separator};

  for (const auto &token: tokenizer) {
    vectorStrings.push_back(token);
  }
  return vectorStrings;
}

}  // namespace config_parser
}  // namespace xlstousers
