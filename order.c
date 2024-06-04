#include "headerfile.h"
void order()
{
    int itemno;
    int tot_bill = 0;
    char ordered_items[10][50];
    int quantities[10] = {0};
    int item_count = 0;
    printf("\nEnter the item numbers you want to order (1-9) and press 0 to stop: ");
    do {
        scanf("%d", &itemno);
        if (itemno>=1&&itemno<=9)
        {
            strcpy(ordered_items[item_count],menu[itemno-1]);
            quantities[item_count]++;
            tot_bill+=prices[itemno - 1];
            item_count++;
        }
        else if (itemno!=0)
        {
            printf("Invalid item number. Please try again.\n");
        }
    } while(itemno!=0);
    printf("Order taken, your total bill is: Rs.%d\n", tot_bill);
    order_summary(ordered_items, quantities, item_count, tot_bill);
}