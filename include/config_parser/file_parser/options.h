#ifndef XLSTOUSERS_FILEPARSER_OPTIONSFILE_H
#define XLSTOUSERS_FILEPARSER_OPTIONSFILE_H

#include <string>

namespace 
{

const std::string COLUMNS = "columns_headers";
const std::string PASSWORD_LEN = "password_length";
const std::string MIN_UID = "initial_uid";
const std::string MAX_UID = "final_uid";
const std::string USER_GID = "gid";
const std::string HOME = "home_directory";
const std::string TIME = "time_to_password_change";
const std::string USER_CLASS = "class";
const std::string USER_SHELL = "shell";
const std::string EXPIRE = "account_expire";
const std::string BLOCKS_HARD_LIMIT = "block_hard_limit";
const std::string BLOCKS_SOFT_LIMIT = "block_soft_limit";
const std::string INODES_HARD_LIMIT = "inodes_hard_limit";
const std::string INODES_SOFT_LIMIT = "inodes_soft_limit";
const std::string BLOCKS_TIME = "block_time";
const std::string INODES_TIME = "inodes_time";
const std::string PATH_QUOTA = "path_quota";

}  // namespace

#endif  // XLSTOUSERS_FILEPARSER_OPTIONSFILE_H
