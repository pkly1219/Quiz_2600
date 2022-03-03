/*
    Declare library
    Declare the struc Game which contian information about the count, win, lose, totalguess
    In main function
    Declare neccessary variable
    Loop Menu contain 3 choice
    Check if the choice entered is valid or not
    Choice 1: Play game
        Random number in(1-10)
        Prompt the user to enter the value until they win
        If they enter 'q', quit the game and comback to the menu
    Choice 2: Change the max value
        Prompt the user to enter the max value in range(1-10)
        Check if their value is valid or not
    Choice 3: Quit the game
        Print the struct Game to show all game result
        Thank you and exit the program
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

struct Game {
    int count;
    int win;
    int lose;
    int totalguess;
};

int main(){
    struct Game result[1000];
    int i = 0;
    int numberToGuess;
    int choice;
    char guessNum[100];
    char quit;
    time_t t;
    srand((unsigned) time(&t));
    int changeValue;
    int count = 0;
    int max = 10;
    result[i].count = 0;
    FILE *fptr;
    fptr = fopen("save_user_max.txt","w+");
    fscanf(fptr,"%d", &max);
    fclose(fptr);
    
do
{
    printf("Number guessing game\n Press 1 to play a game\n Press 2 to change the max value\n Press 3 to quit\n");
    printf("Enter a choice: ");
    scanf("%d", &choice);
   
        if(choice == 1)
        {

            printf("Enter a number between 1-10 to play the game ");
            numberToGuess = 1 + rand()%(max);
            result[i].count ++;
            i ++;
            result[i].win = 0;
            result[i].lose = 0;
            result[i].totalguess = 0;
            do
            {
                scanf("%s", guessNum);
                if(*guessNum == 'q')
                {
                    result[i].lose ++;
                    break;
                }
                
                else
                {
                
                    if(atoi(guessNum) > numberToGuess)
                    {   
                        if(atoi(guessNum) > max)
                        {
                            printf("The number is out of range. Enter again ");
                        }
                        else
                        printf("The number is too high. Enter again ");
                        
                        result[i].totalguess++;
                    }

                    else if(atoi(guessNum) < numberToGuess)
                    {
                        if(atoi(guessNum) < 1)
                        {
                            printf("The number is out of range. Enter again ");
                        }
                        else
                        printf("The number is too low. Enter again ");
                        
                        result[i].totalguess++;
                
                    }
                    
                    else if (atoi(guessNum) == numberToGuess)
                    {
                        printf("The number is right. You win!\n");
                        result[i].win ++;
                        result[i].totalguess++;
                        break;
                        
                    }
                
                }  
            } while(quit != 'q');       
        }
    
        else if (choice == 2)
        { 
            printf("Enter the max value you want to change.");
            scanf("%d", &changeValue);
            fopen("save_user_max.txt", "w+");
            fscanf(fptr,"%d", &max);
            fclose(fptr);

            while(changeValue > 10 || changeValue <= 1)
            {            
                printf("/nInvalid value. The max value must be in rang (1,10). Please enter again.");
                scanf("%d", &changeValue);
            }
            max = changeValue;
            fopen("save_user_max.txt", "w+");
            fprintf(fptr,"%d", max);
            fclose(fptr);

        }

        else if(choice == 3)
        {
            printf("\nThank you for playing");
            
            for(int j = 1; j <= i; j++)
            {
                printf("\nGame: %d", j);
                if(result[j].win > result[j].lose)
                {
                    printf("\nResult: win\n");
                }    
                else
                    printf("\nResult: Lose\n");
                printf("Total time guess: %d", result[j].totalguess);
            
            }
        }
    
    else
     printf("Invalid input. Please enter agian\n");  
    

} while(choice != 3);

    return 0;
}