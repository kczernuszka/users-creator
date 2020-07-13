#ifndef XLSTOUSERS_CONFIGPARSER_FILEPARSER_CONFIG_H
#define XLSTOUSERS_CONFIGPARSER_FILEPARSER_CONFIG_H

#include <map>
#include <vector>
#include <string>

const std::string DEFAULT_VALUES_FILE = "defaultValues";

namespace xlstousers { namespace config_parser
{

struct UidsRange {
  int min_uid;
  int max_uid;
};

struct User {
  UidsRange uids_range;
  int gid;
  std::string home;
  int change;
  std::string class_name;
  std::string shell;
  int expire;
};

struct Quota {
  int block_hard_limit;
  int block_soft_limit;
  int inodes_hard_limit;
  int inodes_soft_limit;
  int block_time;
  int inodes_time;
  std::string path_quota;
};

struct Config {
  std::vector<std::string> columns;
  int password_lenght;
  User user;
  Quota quota;
};

}}  // namespace xlstousers::config_parser

#endif  // XLSTOUSERS_CONFIGPARSER_FILEPARSER_CONFIG_H
