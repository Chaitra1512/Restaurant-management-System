#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX_TABLES 10
#define MAX_MENU_ITEMS 9

typedef struct {
    int tableno;
    char name[50];
} TableReservation;

int table[MAX_TABLES];
TableReservation reservations[MAX_TABLES];

char menu[MAX_MENU_ITEMS][50] = {
    "Fried Chicken",
    "Chicken Nuggets",
    "Chicken Fried Rice",
    "Grilled Chicken Wings",
    "Chicken Biryani",
    "Noodles",
    "Fish Fry",
    "Prawn Fry",
    "Kebab"
};

int prices[MAX_MENU_ITEMS] = { 250, 200, 150, 300, 350, 275, 175, 225, 100 };


void reserve_table();
void order();
void order_summary();
void display_menu();



#endif

