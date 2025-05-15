#ifndef COMMAND_H
#define COMMAND_H

typedef enum {
    CMD_EXIT,
    CMD_SELECT,
    CMD_INSERT,
    CMD_UNKNOWN
} CommandType;

CommandType parse_command(const char *input);

#endif
