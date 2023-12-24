#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void nameInput(char *name);
void nameDisplay(void);

void nameDisplay(void){
	printf("Your name : ");
}

void nameInput(char *name){
	scanf("%100[^\n]%*c", name);
}

void stringToCaps(char a[]){
	int i;
    for(i = 0; i < strlen(a); i++)
        if(a[i] > 96 && a[i] < 123)
            a[i] -= 32;
}

struct data{
	char player[100];
	int score;
};

int main(){	
	FILE *fp;
	struct data scoreData;
	
    fp = fopen("Score.txt", "w");

    if(fp == NULL){
            printf("file cannot be opened for writing\n");
            exit(1);
    }
    
	int totalPoints;
	int playerScore = 0;
    int userHand, computerHand;
    char userHandString[10], computerHandString[10];
    
    int result;
    

    int keepAsking;
    char keepPlaying = 'Y';
    
    char name[100];
    
    //Input nama
    nameDisplay();
    nameInput(&scoreData.player);
    system("@cls||clear");

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

        //Main Gamenya
        
        printf(" --- Hai %s, Welcome to the game! ---\n\n", name);

        printf("================================\n");
        printf("=   ROCK PAPER SCISSORS GAME   =\n");      
        printf("================================\n");      

        do{
            printf("\nRock, paper or scissors? : ");

            scanf("%s", userHandString);
            stringToCaps(userHandString);
            
        	printf("======================================\n");

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

        printf("\nYour hand: %s", userHandString);
        printf("\nComputer's hand: %s\n\n", computerHandString);

        result = userHand - computerHand;
                
        if(result < 0) result += 3;

        switch(result){
            case 0:
            	playerScore = playerScore + 50;
                printf("It's a draw\n");
                printf("Your score: 50\n");
                printf("======================================\n\n");
                break;
            case 1:
            	playerScore = playerScore + 100;
                printf("YOU WON YAY!\n");
                printf("Your score: 100\n");
                printf("======================================\n\n");
                break;
            case 2:
            	playerScore = playerScore + 0;
                printf("Oh, you lost.\n");
                printf("Your score: 0\n");
                printf("======================================\n\n");
                break;
            default:
            	playerScore = playerScore + 0;
                printf("Your score: 0\n");
                printf("======================================\n\n");
                break;
        }
        
        printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
        
    
	    if(result == 0 && result == 1){
	    	totalPoints = totalPoints + playerScore;
	    	printf("Total Score = %d", totalPoints);
	    	
	    	fprintf(fp, "%s - %d", scoreData.player, totalPoints);
    		fclose(fp);
    	
	       	return keepPlaying == 'y' && keepPlaying == 'Y' && keepPlaying == 'n' && keepPlaying == 'N';
	       	system("@cls||clear");
		} else if (result == 2){
			totalPoints = totalPoints + playerScore;
	   		printf("Total Score = %d", totalPoints);
	   		
	   		fprintf(fp, "%s - %d", scoreData.player, totalPoints);
    		fclose(fp);
    		
			return keepPlaying != 'y' && keepPlaying != 'Y' && keepPlaying != 'n' && keepPlaying != 'N';
			system("@cls||clear");
		    printf("  THANKS FOR PLAYING!  \n");
		    printf("=======================\n");
		}
		
	}
	
	
    
    return 0;
}
