#include "header.h"
void display_menu() {
    printf("Menu:\n");
    printf("+----+-----------------------+--------+\n");
    printf("| No | Item                  | Price  |\n");
    printf("+----+-----------------------+--------+\n");
    for (int i = 0; i < MAX_MENU_ITEMS; i++) {
        printf("| %2d | %-21s | %6d |\n", i + 1, menu[i], prices[i]);
    }
    printf("+----+-----------------------+--------+\n");
}