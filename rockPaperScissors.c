#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void nameInput(char *name);
void nameDisplay(void);

//module nampilin your name (tinggal panggil)
void nameDisplay(void){
	printf("Your name : ");
}

//module input name (tinggal panggil)
void nameInput(char *name){
	scanf("%100[^\n]", name);
}

//biar capslock hurufnya
void stringToCaps(char a[]){
	int i;
    for(i = 0; i < strlen(a); i++)
        if(a[i] > 96 && a[i] < 123)
            a[i] -= 32;
}

//struct buat data player
struct data{
    char player[100];
    int score;
    int totalPoints;
};

//module utk search player
void searchPlayer(struct data *scoreArray, int *totalPlayers) {
    char playerName[100];
    int found = 0;
    int i;
    
    printf("\nEnter the player's name to search for: ");
    scanf("%s", playerName);

    for (i = 0; i < totalPlayers; i++) {
        if (strcmp(playerName, scoreArray[i].player) == 0) {
            printf("\nPlayer: %s\nScore: %d\n", scoreArray[i].player, scoreArray[i].totalPoints);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nPlayer not found in the scoreboard.\n");
    }
}


//module utk urutkan score si player dari yang terbesar sampai yang terkecil. (Bubble)
void sortScoresFromFile(struct data *scoreArray, int *totalPlayers) {
    FILE *fp = fopen("Score.txt", "r");

    if (fp == NULL) {
        printf("File cannot be opened for reading\n");
        exit(1);
    }

    *totalPlayers = 0;

    while (fscanf(fp, "%99[^-]-%d\n", scoreArray[*totalPlayers].player, &scoreArray[*totalPlayers].totalPoints) != EOF) {
        (*totalPlayers)++;
    }

    fclose(fp);

    int i, j;
    for (i = 0; i < *totalPlayers - 1; i++) {
        for (j = 0; j < *totalPlayers - i - 1; j++) {
            if (scoreArray[j].totalPoints < scoreArray[j + 1].totalPoints) {
                struct data buffer = scoreArray[j];
                scoreArray[j] = scoreArray[j + 1];
                scoreArray[j + 1] = buffer;
            }
        }
    }

    for(i = 0; i < *totalPlayers; i++){
        printf("%s-%d\n", scoreArray[i].player, scoreArray[i].totalPoints);
    }
}

int main(){	
	FILE *fp;
	struct data scoreData[1000];
	
    fp = fopen("Score.txt", "a+");

    if(fp == NULL){
        printf("file cannot be opened for writing\n");
        exit(1);
    }
    
    int i;
	int playerScore = 0;
    int userHand, computerHand;
    char userHandString[10], computerHandString[10];
    
    int result;
    
    int keepAsking;
    char keepPlaying = 'Y';
    char back;
    
    char *name;
    
    int totalPlayers = 0;

    while (keepPlaying == 'Y' || keepPlaying == 'y') {
        printf("================================\n");
        printf("=   ROCK PAPER SCISSORS GAME   =\n");
        printf("================================\n");

        int choice;
        do {
			printf("MENU\n");
		    printf("1. Play Game\n");
		    printf("2. Scoreboard\n");
	        printf("3. Search Player Score\n");
	        printf("4. Exit\n");
	   	    printf("Enter your choice: ");
		    scanf("%d", &choice);
		    getchar();
			
            switch (choice) {
                case 1:
                	printf("\nLet's start the game!\n");	
    				//Input nama
    				nameDisplay();
    				nameInput(scoreData[totalPlayers].player);
    				
					while(keepPlaying == 'Y' || keepPlaying == 'y'){
						srand(time(NULL));
						int totalPoints = 0;
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
						    	totalPoints = scoreData[totalPlayers].score;
                            	totalPoints = totalPoints + playerScore;
                            	scoreData[totalPlayers].totalPoints = totalPoints;
						    	printf("Total Score = %d", totalPoints);
						    	
						    	fprintf(fp, "%s-%d\n", scoreData[totalPlayers].player, totalPoints);
					    		fclose(fp);
					    	
						       	return keepPlaying == 'y' && keepPlaying == 'Y' && keepPlaying == 'n' && keepPlaying == 'N';
							} else if (result == 2){
								totalPoints = scoreData[totalPlayers].score;
                            	totalPoints = totalPoints + playerScore;
                            	scoreData[totalPlayers].totalPoints = totalPoints;
						    	printf("Total Score = %d\n\n", totalPoints);
						    	
						    	printf("=======================\n");
								printf("  THANKS FOR PLAYING!  \n");
								printf("=======================\n");
								
								fprintf(fp, "%s-%d\n", scoreData[totalPlayers].player, totalPoints);
						    	fclose(fp);
						    	
								return keepPlaying != 'y' && keepPlaying != 'Y' && keepPlaying != 'n' && keepPlaying != 'N';
							}
						} 
                    break;
                case 2:
				    printf("\nScoreboard:\n");
				    sortScoresFromFile(scoreData, &totalPlayers);
				    printf("======================================\n\n");
				    break;
                case 3:
				    searchPlayer(scoreData, totalPlayers);
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
}
