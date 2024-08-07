void order_summary(char ordered_items[][50], int quantities[], int item_count, int total_bill) {
    FILE *file = fopen("order_summary.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Print to terminal
    printf("\nOrder Summary:\n");

    int reservation_index = -1;
    for (int i = 0; i < MAX_TABLES; i++) {
        if (table[i] == 0) { // Reserved table found
            reservation_index = i;
            break;
        }
    }

    if (reservation_index == -1) {
        printf("No table reserved.\n");
        fprintf(file, "No table reserved.\n");
    } else {
        printf("Table Number: %d\n", reservations[reservation_index].tableno);
        fprintf(file, "Table Number: %d\n", reservations[reservation_index].tableno);
        
        printf("Customer Name: %s\n", reservations[reservation_index].name);
        fprintf(file, "Customer Name: %s\n", reservations[reservation_index].name);
    }

    printf("+----+-----------------------+--------+\n");
    fprintf(file, "+----+-----------------------+--------+\n");
    
    printf("| No | Item                  | Qty    |\n");
    fprintf(file, "| No | Item                  | Qty    |\n");
    
    printf("+----+-----------------------+--------+\n");
    fprintf(file, "+----+-----------------------+--------+\n");

    // Print order details to terminal and file
    for (int i = 0; i < item_count; i++) {
        printf("| %2d | %-21s | %6d |\n", i + 1, ordered_items[i], quantities[i]);
        fprintf(file, "| %2d | %-21s | %6d |\n", i + 1, ordered_items[i], quantities[i]);
    }

    printf("+----+-----------------------+--------+\n");
    fprintf(file, "+----+-----------------------+--------+\n");
    
    printf("Total Bill: Rs.%d\n", total_bill);
    fprintf(file, "Total Bill: Rs.%d\n", total_bill);

    fclose(file);
    printf("Order summary written to order_summary.txt\n");
}
