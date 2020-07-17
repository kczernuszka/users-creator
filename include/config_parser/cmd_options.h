#ifndef XLSTOUSERS_CONFIGPARSER_CMDOPTIONS_H
#define XLSTOUSERS_CONFIGPARSER_CMDOPTIONS_H

#include <utility>

const auto CONFIG_FILE = std::make_pair("config_file", "c");
const auto INTERACTIVE = std::make_pair("interactive", "i");
const auto TEST_MODE = std::make_pair("test", "t");
const auto QUOTA = std::make_pair("quota", "q");

#endif  // XLSTOUSERS_CONFIGPARSER_CMDOPTIONS_H
