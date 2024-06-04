#ifndef APPLICATION_H_INCLUDED //if not defined
#define APPLICATION_H_INCLUDED


#include <stdio.h>
#include <string.h>
int table[10];
char menu[10][50]={"burger","pizza","sandwich","pasta","noodles","momos","fried chicken","popcorn","french fries"};
int prices[10] = {150, 200, 100, 90, 120, 70, 180, 50, 75};
struct reserve{
    int tableno;
    char name[50];
};
struct reserve tables;
// Function prototypes
void reserve_table();
void display_menu();
void order();
void order_summary(char ordered_items[][50],int quantities[],int item_count,int total_bill);

#endif
