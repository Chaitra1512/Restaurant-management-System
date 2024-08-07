#include "header.h"
void order() {
    int itemno;
    int tot_bill = 0;
    char ordered_items[10][50];
    int quantities[10] = { 0 };
    int item_count = 0;

    printf("\nEnter the item numbers you want to order (1-9) and press 0 to stop:\n");

    while (1) {
        printf("Enter item number: ");
        if (scanf("%d", &itemno) != 1) {
            // Clear the input buffer if scanf fails
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }

        // Clear the input buffer after a valid scanf
        while (getchar() != '\n');

        if (itemno == 0) {
            break; // Exit the loop if user enters 0
        } else if (itemno >= 1 && itemno <= 9) {
            int found = 0;
            for (int i = 0; i < item_count; i++) {
                if (strcmp(ordered_items[i], menu[itemno - 1]) == 0) {
                    quantities[i]++;
                    tot_bill += prices[itemno - 1];
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(ordered_items[item_count], menu[itemno - 1]);
                quantities[item_count] = 1;
                tot_bill += prices[itemno - 1];
                item_count++;
            }
        } else {
            printf("Invalid item number. Please enter a number between 1 and 9.\n");
        }
    }

    printf("Order taken, your total bill is: Rs.%d\n", tot_bill);
    order_summary(ordered_items, quantities, item_count, tot_bill);
}
