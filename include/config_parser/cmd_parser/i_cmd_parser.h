#ifndef XLSTOUSERS_CMDPARSER_ICMDPARSER_H
#define XLSTOUSERS_CMDPARSER_ICMDPARSER_H

#include <memory>

#include "cmd_arguments.h"

namespace xlstousers { namespace config_parser
{

class ICmdParser {
 public:
  ~ICmdParser() = default;
  virtual std::unique_ptr<CmdArguments> getConfig(char **argv) = 0;
};

}}  // namespace xlstousers::config_parser

#endif  // XLSTOUSERS_CMDPARSER_ICMDPARSER_H
