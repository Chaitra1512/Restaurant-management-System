#include "header.h"
#include "reserve_table.c"
#include "order.c"
#include "order_summary.c"
#include "display_menu.c"

int main() {
    int choice;
    int flag = 1;
    char input[10];

    for (int i = 0; i < MAX_TABLES; i++) {
        table[i] = 1; // 1 indicates available
    }

    while (flag) {
        printf("\nWelcome to THE CHEF'S CORNER!\n");
        printf("1. Reserve a table\n");
        printf("2. Display the menu items\n");
        printf("3. Order the food\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);

        // Check if input is valid
        int is_valid = 1;
        for (int i = 0; i < strlen(input) - 1; i++) {
            if (!isdigit(input[i])) {
                is_valid = 0;
                break;
            }
        }
        if (is_valid) {
            choice = atoi(input); // Convert string to integer
        } else {
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            continue;
        }

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
            case 4:
                printf("Thank you for visiting! Goodbye.\n");
                flag = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}