#include "config_parser.h"

namespace xlstousers {
namespace config_parser {

ConfigParser::ConfigParser(CmdParser *cmd_parser, FileParser *file_parser)
    : file_parser{file_parser}, cmd_parser{cmd_parser} {}

std::unique_ptr<Config> ConfigParser::getConfigFromFile(std::string file) {
  return file_parser->getConfig(file);
}

std::unique_ptr<ProgramSettings> ConfigParser::getConfigFromCmd() {
  return cmd_parser->getConfig();
}

}  // namespace config_parser
}  // namespace xlstousers
