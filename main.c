#include <stdio.h>
#include <string.h>
#include "headerfile.h"
#include "table.c"
#include "menu.c"
#include "order.c"
#include "ordersumm.c"

int main() {
    int choice;
    for (int i = 0; i < 10; i++) {
        table[i] = 1;
    }
    do {
        printf("\nWelcome to our hotel!\n");
        printf("1. Reserve a table\n");
        printf("2. Display the menu items\n");
        printf("3. Order the food\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                reserve_table();
                break;
            case 2:
                display_menu();
                break;
            case 3:
                order();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}