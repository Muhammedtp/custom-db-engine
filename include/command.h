#ifndef COMMAND_H
#define COMMAND_H

#include "table.h"
typedef enum {
    CMD_EXIT,
    CMD_SELECT,
    CMD_INSERT,
    CMD_UNKNOWN
} CommandType;

typedef enum {
    CMD_SUCCESS,
    CMD_SYNTAX_ERROR,
    CMD_TABLE_FULL,
    CMD_UNRECOGNIZED
} CommandResult;

CommandType parse_command(const char *input);
CommandResult execute_command(Table *table, CommandType cmd, const char *input);

#endif
