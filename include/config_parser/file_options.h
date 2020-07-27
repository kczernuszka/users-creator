#ifndef XLSTOUSERS_FILEPARSER_FILEOPTIONS_H
#define XLSTOUSERS_FILEPARSER_FILEOPTIONS_H

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

#endif  // XLSTOUSERS_FILEPARSER_FILEOPTIONS_H
