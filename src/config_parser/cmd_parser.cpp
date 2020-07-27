#include "cmd_parser.h"

namespace xlstousers {
namespace config_parser {

const char* XLSFILE_OPTION_NAME = "xls-file";

CmdParser::CmdParser(int argc, char **argv) : argc{argc}, argv{argv} {}

std::unique_ptr<ProgramSettings> CmdParser::getConfig() {
  auto desc = setOptions();
  auto vm = getVariablesMap(desc);
  if(!vm.empty())
    return getValues(vm);
  else
    return nullptr;
}

po::options_description CmdParser::setOptions() {
  po::options_description desc("Cmd options");
  desc.add_options()
      (createOptionName(CONFIG_FILE, CONFIG_FILE_SHORT).c_str(),
       po::value<std::string>()->default_value(DEFAULT_CONFIG_PATH),
       "path to config file")
      (createOptionName(INTERACTIVE, INTERACTIVE_SHORT).c_str(), 
       "interactive mode")
      (createOptionName(TEST_MODE, TEST_MODE_SHORT).c_str(), "test mode")
      (createOptionName(QUOTA, QUOTA_SHORT).c_str(), "create quota for users")
      (XLSFILE_OPTION_NAME, po::value<std::string>(), "input xls file");

  return desc;
}

po::variables_map CmdParser::getVariablesMap(po::options_description desc) {
  po::positional_options_description p;
  p.add(XLSFILE_OPTION_NAME, -1);
  po::variables_map vm;
  try {
    store(po::command_line_parser(argc, argv).options(desc).positional(p).run(),
          vm);
    notify(vm);
  }
  catch (std::exception error) {
    return nullptr;
  }
  return vm;
}

std::unique_ptr<ProgramSettings> CmdParser::getValues(po::variables_map vm) {
  auto program_settings = std::make_unique<ProgramSettings>();
  try {
    if (vm.count(XLSFILE_OPTION_NAME))
      program_settings->xls_file = vm[XLSFILE_OPTION_NAME].as<std::string>();

    program_settings->config_file = vm[CONFIG_FILE].as<std::string>();
    program_settings->interactive_mode = vm.count(INTERACTIVE);
    program_settings->test_mode = vm.count(TEST_MODE);
    program_settings->quota = vm.count(QUOTA);
  }
  catch (boost::bad_any_cast error) {
    return nullptr;
  }
  return program_settings;
}

std::string CmdParser::createOptionName(const std::string full_name,
                                        const std::string short_name) {
  std::string option = full_name + "," + short_name;
  return option;
}

}  // namespace config_parser
}  // namespace xlstousers
