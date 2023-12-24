#include <stdio.h>
#include <stdlib.h>
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

void searchPlayer(void) {
    FILE *fp;
    struct data scoreData;
    char searchName[100];

    printf("Enter the name to search: ");
    scanf("%100[^\n]%*c", searchName);

    fp = fopen("Score.txt", "a+");

    if (fp == NULL) {
        printf("File cannot be opened for reading\n");
        exit(1);
    }

    int found = 0;
    while (fscanf(fp, "%s - %d", scoreData.player, &scoreData.score) != EOF) {
        if (strcmp(searchName, scoreData.player) == 0) {
            printf("%s's score: %d\n", scoreData.player, scoreData.score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%s not found in the records.\n", searchName);
    }

    fclose(fp);
}

void sortScores(struct data *scoreArray, int totalPoints) {
	int i, j;
	for (i = 0; i < totalPoints - 1; i++) {
        for (j = 0; j < totalPoints - i - 1; j++) {
            if (scoreArray[j].score < scoreArray[j + 1].score) {
                struct data temp = scoreArray[j];
                scoreArray[j] = scoreArray[j + 1];
                scoreArray[j + 1] = temp;
            }
        }
    }
}

int main(){	
	FILE *fp;
	struct data scoreData;
	
    fp = fopen("Score.txt", "a+");

    if(fp == NULL){
            printf("file cannot be opened for writing\n");
            exit(1);
    }
    
    int i;
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
    nameInput(scoreData.player);
    system("@cls||clear");

    srand(time(NULL));

    while (keepPlaying == 'Y' || keepPlaying == 'y') {
    	printf(" --- Hai %s, Welcome to the game! ---\n\n", name);  
        printf("================================\n");
        printf("=   ROCK PAPER SCISSORS GAME   =\n");
        printf("================================\n");

        int choice;
        do {
            printf("1. Play Game\n");
            printf("2. Scoreboard\n");
            printf("3. Search Player Score\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
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
					
					        do{
								printf("\nLet's start the game!");
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
						    	
						    	fprintf(fp, "%s - %d\n", scoreData.player, totalPoints);
					    		fclose(fp);
					    	
						       	return keepPlaying == 'y' && keepPlaying == 'Y' && keepPlaying == 'n' && keepPlaying == 'N';
						       	system("@cls||clear");
							} else if (result == 2){
								totalPoints = totalPoints + playerScore;
						   		printf("Total Score = %d", totalPoints);
						   		
						   		fprintf(fp, "%s - %d\n", scoreData.player, totalPoints);
					    		fclose(fp);
					    		
								return keepPlaying != 'y' && keepPlaying != 'Y' && keepPlaying != 'n' && keepPlaying != 'N';
								system("@cls||clear");
							    printf("  THANKS FOR PLAYING!  \n");
							    printf("=======================\n");
							}
							
						}                   
                    break;
                case 2:
                    sortScores(&scoreData, totalPoints);
                    printf("\nScoreboard:\n");
                    for (i = 0; i < totalPoints; i++) {
                        printf("%s - %d\n", scoreData.player, scoreData.score);
                    }
                    printf("======================================\n\n");
                    break;
                case 3:
                    searchPlayer();
                    break;
                case 4:
                    printf("Thanks for playing!\n");
                    fclose(fp);
                    exit(0);
                default:
                    printf("Invalid choice. Please enter again.\n");
                    break;
            }
        } while (choice != 3);
    }
	
	
    
    return 0;
}
