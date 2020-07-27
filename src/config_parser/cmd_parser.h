#ifndef XLSTOUSERS_CONFIGPARSER_CMDPARSER_H
#define XLSTOUSERS_CONFIGPARSER_CMDPARSER_H

#include <memory>

#include <boost/program_options.hpp>

#include <config_parser/config.h>
#include <config_parser/cmd_options.h>

namespace xlstousers { namespace config_parser
{
namespace po = boost::program_options;

class CmdParser {
 public:
  CmdParser(int argc, char **argv);
  std::unique_ptr<ProgramSettings> getConfig();
 private:
  int argc; char **argv;

  po::options_description setOptions();
  po::variables_map getVariablesMap(po::options_description desc);
  std::unique_ptr<ProgramSettings> getValues(po::variables_map vm);
  std::string createOptionName(const std::string full_name,
                               const std::string short_name);
};

}}  // namespace xlstousers::config_parser

#endif  // XLSTOUSERS_CONFIGPARSER_CMDPARSER_H
