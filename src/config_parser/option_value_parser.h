#ifndef SRC_CONFIG_PARSER_OPTION_VALUE_PARSER_H_
#define SRC_CONFIG_PARSER_OPTION_VALUE_PARSER_H_

#include <fstream>

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

const char* const VALUES_DELIMITER = ",";

namespace xlstousers { namespace config_parser
{

std::vector<std::string> valueToVector(std::string value);

}}  // namespace xlstousers::config_parser

#endif  // SRC_CONFIG_PARSER_OPTION_VALUE_PARSER_H_
