/*
Declare the library

The main function:
The program has accept the argument from the command line
Declare some neccessary variable to represent the menu
Check if the input is valid or not
Use random function to choose the meal from the menu
Choice = 0
Calculate the tip, tax and total based on the price of salad
Choice = 1
Calculate the tip, tax and total based on the price of soup
Choice = 2
Calculate the tip, tax and total based on the price of sanwich
Choice = 3
Calculate the tip, tax and total based on the price of pizza
Print out the meal, tip, tax and total to the screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
int main(int argc, char*argv[]){
    double salad = 9.95;
    double soup = 4.55;
    double sandwich = 13.25;
    double pizza = 22.35;
    double total;
    int choice;
    time_t t;
    srand((unsigned) time(&t));
    choice = rand()%4;
    printf (" The menu cost:\n Salad: $9.95\n Soup: $4.55\n Sandwich: $13.25\n Pizza: $22.35 \n");
    
    double tax = atof(argv[1]);
    double tip = atof(argv[2]);
        if(tax >= 0 && tax <= 1 && tip >= 0 && tip <= 1)
        {
             if (choice == 0)
             {
                tax = tax*9.95;
                tip = tip*9.95;
                total = tax + tip + 9.95;
                printf(" Salad ($9.95), tax: $ %.2f", tax );
                printf(", tip: $ %.2f", tip);
                printf(", total: $ %.2f",total);
             }

             else if(choice == 1)
             {
                tax = tax*4.55;
                tip = tip*4.55;
                total = tax + tip + 4.55;
                printf("Soup ($4.55), tax: $ %.2f", tax);
                printf(", tip: $ %.2f", tip);
                printf(", total: $ %.2f",total);
            }

            else if(choice == 2)
            {
                tax = tax*13.25;
                tip = tip*13.25;
                total = tax + tip + 13.25;
                printf("Sandwich ($13.25), tax: $ %.2f", tax);
                printf(", tip: $ %.2f", tip);
                printf(", total: $ %.2f",total);
            }
            else 
            {
                tax = tax*22.35;
                tip = tip*22.35;
               total = tax + tip + 22.35;
                printf("Pizza ($22.35), tax: $ %.2f", tax);
             printf(", tip: $ %.2f", tip);
        printf(", total: $ %.2f",total);
          }
        }
    
    else{
    printf(" Invalid input. Tax and tip are percentage, so tax and tip are equal or greater than to 0 and equal or less than 1. Please try again");
        }
    
    

    return 0;
}