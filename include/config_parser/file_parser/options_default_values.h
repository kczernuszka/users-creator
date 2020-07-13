#ifndef XLSTOUSERS_FILEPARSER_OPTIONSDEFAULTVALUES_H
#define XLSTOUSERS_FILEPARSER_OPTIONSDEFAULTVALUES_H

#include <map>

#include "options.h"

namespace 
{

// options names with default values
std::map<std::string, std::string> CONFIG_OPTIONS {
    { COLUMNS, "imie,nazwisko" }, 
    { PASSWORD_LEN, "8" }, 
    { MIN_UID, "1001" }, 
    { MAX_UID, "10000" },
    { USER_GID, "10" },
    { HOME, "/home" }, 
    { TIME, "0" },
    { USER_CLASS, "staff" },
    { USER_SHELL, "/bin/ksh" },
    { EXPIRE, "0" },
    { BLOCKS_HARD_LIMIT, "0" },
    { BLOCKS_SOFT_LIMIT, "0" },
    { INODES_HARD_LIMIT, "0" },
    { INODES_SOFT_LIMIT, "0" },
    { BLOCKS_TIME, "0" },
    { INODES_TIME, "0" },
    { PATH_QUOTA, "/home" },
};

}  // namespace

#endif  // XLSTOUSERS_FILEPARSER_OPTIONSDEFAULTVALUES_H
