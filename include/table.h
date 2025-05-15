#ifndef TABLE_H
#define TABLE_H

#include "db.h"

typedef struct {
    Row rows[TABLE_MAX_ROWS];
    int num_rows;
} Table;

Table *new_table();
void free_table(Table *table);
void insert_row(Table *table, Row row);
void print_rows(Table *table);

#endif
