#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int genRandomNumber(int n) {
    time_t t1;
    srand((unsigned) time(&t1));
    return rand() % n;
}

int main() {
    printf("Welcome to Rock Paper Scissor!!\nHow many rounds would you like to play?: ");

    int rounds;

    scanf("%d", &rounds);

    char *choices[] = {"Rock", "Paper", "Scissor"};

    int playerScore, compScore;
    playerScore = compScore = 0;

    for (int i; i < (rounds+1); i++) {
        printf("\nWhat would you like to choose?\n[0] Rock\n[1] Paper\n[2] Scissor\n");

        int choice;
        while (1){
            printf("Enter the corresponding index number: ");
            scanf("%d", &choice);

            if (choice < 0 || choice > 2) {
                printf("Invalid Index! Try Again!");
                continue;
            }

            else {
                break;
            }
        }

        char playerChoice, compChoice;
        int randNum = genRandomNumber(3);

        playerChoice = *choices[choice];
        compChoice = *choices[randNum];

        if (playerChoice == compChoice) {
            printf("It's a draw!\n");
        }

        else if (playerChoice == 'P' && compChoice == 'R') {
            printf("Computer chose Rock!\nYou won this round!!");
            playerScore++;
        }
        else if (playerChoice == 'S' && compChoice == 'P') {
            printf("Computer chose Paper!\nYou won this round!!");
            playerScore++;
        }
        else if (playerChoice == 'R' && compChoice == 'S') {
            printf("Computer chose Scissor!\nYou won this round!!");
            playerScore++;
        }
        else if (compChoice == 'P' && playerChoice == 'R') {
            printf("Computer chose Rock!\nYou lost this round!!");
            compChoice++;
        }
        else if (compChoice == 'S' && playerChoice == 'P') {
            printf("Computer chose Paper!\nYou lost this round!!");
            compChoice++;
        }
        else if (compChoice == 'R' && playerChoice == 'S') {
            printf("Computer chose Scissor!\nYou lost this round!!");
            compChoice++;
        }
    }

    printf("\nYour score: %d\nComputer's Score: %d", playerScore, compScore);

    if (playerScore > compScore) {
        printf("\nYou won the game!!");
    }
    else if (compScore > playerScore) {
        printf("\nYou lost the game!!");
    }
    else {
        printf("\nIt's a draw!!");
    }

    return 0;
}