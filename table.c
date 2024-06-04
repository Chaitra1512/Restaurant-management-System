
#include "headerfile.h"
void reserve_table() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nAvailable Tables:\n");
    for (int i = 1; i <= 10; i++) {
        if (table[i-1] == 1) {
            printf("Table %d\n", i);
        }
    }
    printf("\nEnter the table number you want to reserve (1-10): ");
    int tableno;
    scanf("%d", &tableno);
    if (tableno < 1 || tableno > 10) {
        printf("Invalid table number\n");
        return;
    }
    if (table[tableno - 1] == 0) {
        printf("Table %d is already reserved. Please choose another table\n", tableno);
    } else {
        table[tableno - 1] = 0;
        tables.tableno = tableno;
        strcpy(tables.name, name);
        printf("Table %d reserved successfully for %s.\n", tableno, name);
    }
}
