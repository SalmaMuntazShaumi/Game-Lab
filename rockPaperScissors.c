#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(){
    int userHand, computerHand;
    char userHandString[10], computerHandString[10];
    
    int result;

    int keepAsking;
    char keepPlaying = 'Y';

    srand(time(NULL));

    while(keepPlaying == 'Y' || keepPlaying == 'y'){
        computerHand = rand() % 3;

        switch(computerHand){
            case 0:
                strcpy(computerHandString, "ROCK");
                break;
            case 1:
                strcpy(computerHandString, "PAPER");
                break;
            case 2:
                strcpy(computerHandString, "SCISSORS");
                break;
            default:
                break;
        }

        /*Game*/
        printf("  ROCK PAPER SCISSORS GAME  \n");      
        printf("============================\n");      

        do{
            printf("\nRock, paper or scissors ?: ");

            scanf("%s", userHandString);
            stringToCaps(userHandString);

            keepAsking = 0;

            if(strcmp(userHandString, "ROCK") == 0)
                userHand = 0;
            else if(strcmp(userHandString, "PAPER") == 0)
                userHand = 1;
            else if(strcmp(userHandString, "SCISSORS") == 0)
                userHand = 2;
            else
                keepAsking = 1;
        }while(keepAsking == 1);

        printf("\n\nYour hand: %s", userHandString);
        printf("\nComputer's hand: %s\n\n", computerHandString);

        result = userHand - computerHand;
        if(result < 0)
            result += 3;

        switch(result){
            case 0:
                printf("It's a draw, gg\n\n");
                break;
            case 1:
                printf("YOU WON YAY!\n\n");
                break;
            case 2:
                printf("Oh, you lost. GG EZ NOOB\n\n");
                break;
            default:
                break;
        }
               
        do{
            printf("Do you want to keep playing? [Y/N]: ");
            fflush(stdin);
            scanf("%c",&keepPlaying);
        }while(keepPlaying != 'y' && keepPlaying != 'Y'&& keepPlaying != 'n' && keepPlaying != 'N');
        
        //buat clear layar
        system("@cls||clear");
    }

    printf("  THANKS FOR PLAYING!  \n");
    printf("=======================\n");

    return 0;
}

void stringToCaps(char a[]){
	int i;
    for(i = 0; i < strlen(a); i++)
        if(a[i] > 96 && a[i] < 123)
            a[i] -= 32;
}
