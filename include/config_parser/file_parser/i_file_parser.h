#ifndef XLSTOUSERS_FILEPARSER_IFILEPARSER_H
#define XLSTOUSERS_FILEPARSER_IFILEPARSER_H

#include <memory>

#include "config.h"

namespace xlstousers { namespace config_parser
{

class IFileParser {
 public:
  ~IFileParser() = default;
  virtual std::unique_ptr<Config> getConfig(std::string file) = 0;
};

}}  // namespace xlstousers::config_parser

#endif  // XLSTOUSERS_FILEPARSER_IFILEPARSER_H
