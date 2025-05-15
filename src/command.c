#include <string.h>
#include "command.h"

CommandType parse_command(const char *input) {
    if (strncmp(input, "exit", 4) == 0) {
        return CMD_EXIT;
    } else if (strncmp(input, "select", 6) == 0) {
        return CMD_SELECT;
    } else if (strncmp(input, "insert", 6) == 0) {
        return CMD_INSERT;
    } else {
        return CMD_UNKNOWN;
    }
}
