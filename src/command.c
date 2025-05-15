#include <string.h>
#include <stdio.h>
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

void execute_command(Table *table, CommandType cmd, const char *input) {
    if (cmd == CMD_INSERT) {
        Row row;
        int args = sscanf(input, "insert %d %31s %254s", &row.id, row.username, row.email);
        if (args < 3) {
            printf("Error: Invalid INSERT syntax. Use: insert <id> <username> <email>\n");
            return;
        }
        insert_row(table, row);
        printf("Row inserted.\n");
    } else if (cmd == CMD_SELECT) {
        print_rows(table);
    } else {
        printf("Unknown command: %s\n", input);
    }
}