
#include "headerfile.h"
void display_menu()
{
    printf("Please choose the menu from the below list: \n");
    for (int i=0;i<9;i++)
    {
        printf("%d. %s : Rs.%d\n",i+1,menu[i],prices[i]);
    }
}
