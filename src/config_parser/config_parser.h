#ifndef SRC_CONFIG_PARSER_CONFIG_PARSER_H_
#define SRC_CONFIG_PARSER_CONFIG_PARSER_H_

#include <string>
#include <memory>

#include "file_parser.h"
#include "cmd_parser.h"

namespace xlstousers {
namespace config_parser {

class ConfigParser {
 public:
  ConfigParser(CmdParser *cmd_parser, FileParser *file_parser);
  ~ConfigParser() = default;
  std::unique_ptr<Config> getConfigFromFile(std::string file);
  std::unique_ptr<ProgramSettings> getConfigFromCmd();

 private:
  std::unique_ptr<FileParser> file_parser;
  std::unique_ptr<CmdParser> cmd_parser;
};

}  // namespace config_parser
}  // namespace xlstousers

#endif  // SRC_CONFIG_PARSER_CONFIG_PARSER_H_
