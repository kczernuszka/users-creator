#ifndef XLSTOUSERS_CMDPARSER_CMDARGUMENTS_H
#define XLSTOUSERS_CMDPARSER_CMDARGUMENTS_H

#include <string>

namespace xlstousers { namespace config_parser 
{ 

struct CmdArguments {
  std::string config_file;
  std::string passwd_file;
  bool interactive_mode;
  bool test_mode;
  bool quota;
};

}}  // namespace xlstousers::config_parser

#endif  // XLSTOUSERS_CMDPARSER_CMDARGUMENTS_H