#ifndef XLSTOUSERS_FILEPARSER_FILEOPTIONSDEFAULTVALUES_H
#define XLSTOUSERS_FILEPARSER_FILEOPTIONSDEFAULTVALUES_H

#include <map>
#include <string>

#include "file_options.h"

namespace {

// options names with default values
std::map<std::string, std::string> FILE_OPTIONS {
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

}  // namespace

#endif  // XLSTOUSERS_FILEPARSER_FILEOPTIONSDEFAULTVALUES_H
