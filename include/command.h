#ifndef COMMAND_H
#define COMMAND_H

#include "table.h"
typedef enum {
    CMD_EXIT,
    CMD_SELECT,
    CMD_INSERT,
    CMD_UNKNOWN
} CommandType;

CommandType parse_command(const char *input);
void execute_command(Table *table, CommandType cmd, const char *input);

#endif
