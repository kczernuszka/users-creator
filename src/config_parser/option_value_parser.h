#ifndef XLSTOUSERS_CONFIGPARSER_OPTIONVALUEPARSER_H
#define XLSTOUSERS_CONFIGPARSER_OPTIONVALUEPARSER_H

#include <fstream>

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

namespace xlstousers { namespace config_parser
{

std::vector<std::string> valueToVector(std::string value);

}}  // namespace xlstousers::config_parser

#endif  // XLSTOUSERS_CONFIGPARSER_OPTIONVALUEPARSER_H
