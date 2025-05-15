#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

Table *new_table() {
    Table *table = (Table *)malloc(sizeof(Table));
    if (table == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for table.\n");
        exit(EXIT_FAILURE);
    }
    table->num_rows = 0;
    return table;
}

void free_table(Table *table) {
    free(table);
}

void insert_row(Table *table, Row row) {
    table->rows[table->num_rows++] = row;
}

void print_rows(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        Row *row = &table->rows[i];
        printf("(%d, %s, %s)\n", row->id, row->username, row->email);
    }
}
