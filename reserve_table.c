void reserve_table() {
    char name[50];
    int valid_name = 0; // Flag to indicate if the name is valid

    while (!valid_name) {
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character

        // Validate name: Check if it contains only letters and spaces
        int is_valid = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i]) && !isspace(name[i])) {
                is_valid = 0;
                break;
            }
        }

        if (!is_valid) {
            printf("Invalid name. Please enter a valid name.\n");
        } else {
            valid_name = 1; // Exit the loop if the name is valid
        }
    }

    printf("\nAvailable Tables:\n");
    int available = 0;
    for (int i = 1; i <= MAX_TABLES; i++) {
        if (table[i - 1] == 1) {
            printf("Table %d\n", i);
            available = 1;
        }
    }
    if (!available) {
        printf("No tables are available.\n");
        return; // Exit the function if no tables are available
    }

    int tableno;
    int valid_table = 0; // Flag to indicate if the table number is valid

    while (!valid_table) {
        char buffer[10];
        printf("\nEnter the table number you want to reserve (1-10): ");
        fgets(buffer, sizeof(buffer), stdin);

        // Check if the input is a valid integer
        if (sscanf(buffer, "%d", &tableno) != 1) {
            printf("Invalid input. Please enter a number between 1 and 10.\n");
            continue;
        }

        if (tableno < 1 || tableno > MAX_TABLES) {
            printf("Invalid table number. Please enter a number between 1 and 10.\n");
        } else if (table[tableno - 1] == 0) {
            printf("Table %d is already reserved. Please choose another table.\n", tableno);
        } else {
            valid_table = 1; // Exit the loop if the table number is valid
            table[tableno - 1] = 0; // Mark the table as reserved
            reservations[tableno - 1].tableno = tableno;
            strcpy(reservations[tableno - 1].name, name);
            printf("Table %d reserved successfully for %s.\n", tableno, name);
        }
    }
}
