#ifndef XLSTOUSERS_CONFIGPARSER_FILEPARSER_H
#define XLSTOUSERS_CONFIGPARSER_FILEPARSER_H

#include <iostream>

#include <boost/program_options.hpp>

#include <config_parser/file_options_default_values.h>
#include <config_parser/config.h>

#include "option_value_parser.h"

namespace xlstousers { namespace config_parser 
{

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

}}  // namespace xlstousers::config_parser

#endif  // XLSTOUSERS_CONFIGPARSER_FILEPARSER_H
