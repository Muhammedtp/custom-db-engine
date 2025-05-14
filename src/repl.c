#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repl.h"

#define MAX_INPUT_SIZE 1024

void start_repl() {
    char input[MAX_INPUT_SIZE];

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

        // Check for exit command
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Echo the command (for now)
        printf("You entered: %s\n", input);
    }
}
