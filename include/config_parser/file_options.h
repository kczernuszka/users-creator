#ifndef INCLUDE_CONFIG_PARSER_FILE_OPTIONS_H_
#define INCLUDE_CONFIG_PARSER_FILE_OPTIONS_H_

#include <map>
#include <string>

const char COLUMNS[] = "columns_headers";
const char PASSWORD_LEN[] = "password_length";
const char MIN_UID[] = "initial_uid";
const char MAX_UID[] = "final_uid";
const char USER_GID[] = "gid";
const char HOME[] = "home_directory";
const char TIME[] = "time_to_password_change";
const char USER_CLASS[] = "class";
const char USER_SHELL[] = "shell";
const char EXPIRE[] = "account_expire";
const char BLOCKS_HARD_LIMIT[] = "block_hard_limit";
const char BLOCKS_SOFT_LIMIT[] = "block_soft_limit";
const char INODES_HARD_LIMIT[] = "inodes_hard_limit";
const char INODES_SOFT_LIMIT[] = "inodes_soft_limit";
const char BLOCKS_TIME[] = "block_time";
const char INODES_TIME[] = "inodes_time";
const char PATH_QUOTA[] = "path_quota";

namespace xlstousers {
namespace config_parser {

std::map<std::string, std::string> file_options {
    { std::string(COLUMNS), "imie,nazwisko" },
    { std::string(PASSWORD_LEN), "8" },
    { std::string(MIN_UID), "1001" },
    { std::string(MAX_UID), "10000" },
    { std::string(USER_GID), "10" },
    { std::string(HOME), "/home" },
    { std::string(TIME), "0" },
    { std::string(USER_CLASS), "staff" },
    { std::string(USER_SHELL), "/bin/ksh" },
    { std::string(EXPIRE), "0" },
    { std::string(BLOCKS_HARD_LIMIT), "0" },
    { std::string(BLOCKS_SOFT_LIMIT), "0" },
    { std::string(INODES_HARD_LIMIT), "0" },
    { std::string(INODES_SOFT_LIMIT), "0" },
    { std::string(BLOCKS_TIME), "0" },
    { std::string(INODES_TIME), "0" },
    { std::string(PATH_QUOTA), "/home" },
};

}  // namespace config_parser
}  // namespace xlstousers

#endif  // INCLUDE_CONFIG_PARSER_FILE_OPTIONS_H_
