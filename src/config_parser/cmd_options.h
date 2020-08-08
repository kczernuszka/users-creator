// Copyright 2020 Karol Czernuszka
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
//

#ifndef INCLUDE_CONFIG_PARSER_CMD_OPTIONS_H_
#define INCLUDE_CONFIG_PARSER_CMD_OPTIONS_H_

#include <string>

const char CONFIG_FILE[] = "config";
const char INTERACTIVE[] = "interactive";
const char TEST_MODE[] = "test";
const char QUOTA[] = "quota";

const char CONFIG_FILE_SHORT[] = "c";
const char INTERACTIVE_SHORT[] = "i";
const char TEST_MODE_SHORT[] = "t";
const char QUOTA_SHORT[] = "q";

const char DEFAULT_CONFIG_PATH[] = "/etc/users_creator/";
const bool DEFAULT_INTERACTIVE = false;
const bool DEFAULT_TEST = false;
const bool DEFAULT_QUOTA = false;

#endif  // INCLUDE_CONFIG_PARSER_CMD_OPTIONS_H_
