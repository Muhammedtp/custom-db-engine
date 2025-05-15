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

CommandResult execute_command(Table *table, CommandType cmd, const char *input) {
    if (cmd == CMD_INSERT) {
        Row row;
        int args = sscanf(input, "insert %d %31s %254s", &row.id, row.username, row.email);
        
        // Validate the input format
        if (args < 3) {
            return CMD_SYNTAX_ERROR;
        }

        // Check if the table is full
        if (table->num_rows >= TABLE_MAX_ROWS) {
            return CMD_TABLE_FULL;
        }

        // Insert the row
        insert_row(table, row);
        return CMD_SUCCESS;
    } else if (cmd == CMD_SELECT) {
        print_rows(table);
        return CMD_SUCCESS;
    } else {
        return CMD_UNRECOGNIZED;
    }
}