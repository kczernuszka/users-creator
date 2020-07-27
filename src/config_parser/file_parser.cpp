#include "file_parser.h"

namespace xlstousers {
namespace config_parser {

std::unique_ptr<Config> FileParser::getConfig(std::string file) {
  auto desc = setOptions(file_options);
  auto vm = getVariablesMap(desc, file);
  if (!vm.empty())
    return getValues(vm);
  else
    return nullptr;
}

po::options_description
FileParser::setOptions(std::map<std::string, std::string> options) {
  po::options_description desc("File options");

  for (auto it = options.begin(); it != options.end(); it++) {
    if (std::all_of(it->second.begin(), it->second.end(), ::isdigit))
      desc.add_options()
      (it->first.c_str(),
       po::value<int>()->default_value(std::stoi(it->second)));
    else
      desc.add_options()
      (it->first.c_str(), po::value<std::string>()->default_value(it->second));
  }
  return desc;
}

po::variables_map FileParser::getVariablesMap(
    po::options_description desc, std::string file) {
  po::variables_map vm;
  char **argv;

  try {
    store(parse_config_file(file.c_str(), desc), vm);
  }
  catch (boost::program_options::reading_file error) {
    store(parse_command_line(0, argv, desc), vm);
  }
  catch (std::exception& error) {
    std::cout << error.what() << std::endl;
    return nullptr;
  }
  notify(vm);
  return vm;
}

std::unique_ptr<Config> FileParser::getValues(po::variables_map vm) {
  auto config = std::make_unique<Config>();
  try {
    config->columns = valueToVector(
        vm[COLUMNS].as<std::string>());
    config->password_lenght = vm[PASSWORD_LEN].as<int>();
    config->user.uids_range.min_uid = vm[MIN_UID].as<int>();
    config->user.uids_range.max_uid = vm[MAX_UID].as<int>();
    config->user.gid = vm[USER_GID].as<int>();
    config->user.home = vm[HOME].as<std::string>();
    config->user.change =  vm[TIME].as<int>();
    config->user.class_name =  vm[USER_CLASS].as<std::string>();
    config->user.shell = vm[USER_SHELL].as<std::string>();
    config->user.expire = vm[EXPIRE].as<int>();
    config->quota.block_hard_limit = vm[BLOCKS_HARD_LIMIT].as<int>();
    config->quota.block_soft_limit = vm[BLOCKS_SOFT_LIMIT].as<int>();
    config->quota.inodes_hard_limit = vm[INODES_HARD_LIMIT].as<int>();
    config->quota.inodes_soft_limit = vm[INODES_SOFT_LIMIT].as<int>();
    config->quota.block_time = vm[BLOCKS_TIME].as<int>();
    config->quota.inodes_time = vm[INODES_TIME].as<int>();
    config->quota.path_quota = vm[PATH_QUOTA].as<std::string>();
  }
  catch (boost::bad_any_cast error) {
    return nullptr;
  }
  return config;
}

}  // namespace config_parser
}  // namespace xlstousers
