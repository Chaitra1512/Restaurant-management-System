#include "headerfile.h"
void order_summary(char ordered_items[][50], int quantities[], int item_count, int total_bill)
{
    FILE *file = fopen("order_summary.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Order Summary:\n");
    fprintf(file, "Table Number: %d\n", tables.tableno);
    fprintf(file, "Customer Name: %s\n", tables.name);
    fprintf(file, "\t%s \t%s\n", "Item", "Quantity");
    for (int i = 0; i < item_count; i++) {
        fprintf(file, "\t%s \t%d\n", ordered_items[i], quantities[i]);
    }
    fprintf(file, "Total Bill: Rs.%d\n", total_bill);

    fclose(file);
    printf("Order summary written to order_summary.txt\n");
}
