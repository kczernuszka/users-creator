#include "src/config_parser/config_parser.h"
#include "src/config_parser/file_parser.h"
#include "src/config_parser/cmd_parser.h"

int main(int argc, char *argv[]) {
  xlstousers::config_parser::ConfigParser config_parser{
      new xlstousers::config_parser::CmdParser{argc, argv},
      new xlstousers::config_parser::FileParser};
  auto program_settings = config_parser.getConfigFromCmd();
  auto config = config_parser.getConfigFromFile(program_settings->config_file);
  return 0;
}
