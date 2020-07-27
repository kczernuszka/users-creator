#ifndef XLSTOUSERS_CONFIGPARSER_CMDOPTIONS_H
#define XLSTOUSERS_CONFIGPARSER_CMDOPTIONS_H

#include <string>

const char CONFIG_FILE[] = "config";
const char INTERACTIVE[] = "interactive";
const char TEST_MODE[] = "test";
const char QUOTA[] = "quota";

const char CONFIG_FILE_SHORT[] = "c";
const char INTERACTIVE_SHORT[] = "i";
const char TEST_MODE_SHORT[] = "t";
const char QUOTA_SHORT[] = "q";

const char DEFAULT_CONFIG_PATH[] = "/etc/xlstousers/";
const bool DEFAULT_INTERACTIVE = false;
const bool DEFAULT_TEST = false;
const bool DEFAULT_QUOTA = false;

#endif  // XLSTOUSERS_CONFIGPARSER_CMDOPTIONS_H
