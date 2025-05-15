#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "repl.h"
#include "table.h"

#define MAX_INPUT_SIZE 1024

void start_repl() {
    char input[MAX_INPUT_SIZE];
    Table *table = new_table();

    printf("Welcome to the Custom Database Engine! Type 'exit' to quit.\n");

    while (1) {
        // Prompt
        printf("MyDB> ");
        fflush(stdout);

        // Read user input
        if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
            printf("\nExiting...\n");
            break;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

    
        // Echo the command (for now)
        //printf("You entered: %s\n", input);

        CommandType cmd = parse_command(input);
        switch (cmd) {
            case CMD_EXIT:
                printf("Goodbye!\n");
                return;
            case CMD_SELECT:
                printf("Executing SELECT command...\n");
                break;
            case CMD_INSERT:
                printf("Executing INSERT command...\n");
                break;
            default:
                printf("Unknown command: %s\n", input);
        }

        execute_command(table,cmd,input);
    }

    free_table(table);
}
