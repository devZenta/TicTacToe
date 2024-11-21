#include <stdio.h>

/*
 * 0 : loose
 * 1 : win
*/

int victoryCheck(char gameBoard[3][3]) {
    int result = 0;

    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != '.') {
            result = 1;
            return result;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j] && gameBoard[0][j] != '.') {
            result = 1;
            return result;
        }
    }

    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != '.') {
        result = 1;
        return result;
    }

    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != '.') {
        result = 1;
        return result;
    }

    return result;
}

/*
 * 0 : non null
 * 1 : null
*/

int checkNull(char gameBoard[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameBoard[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

void displayGameBoard(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c", tab[i][j]);
            if (j < 2) {
                printf(" | ");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-------------\n");
        }
    }
    printf("\n");
}

void play(char gameBoard[3][3], char users[2][50]) {
    int nbTurns = 0;
    int player = 0;
    int line;
    int column;
    char currentPlayer;

    while (1) {

        currentPlayer = (player == 0) ? 'X' : 'O';

        printf("-------------------------------------------------");
        printf("\n");
        printf("              %s it's your turn", users[player]);
        printf("\n");
        printf("-------------------------------------------------");
        printf("\n");
        displayGameBoard(gameBoard);

        while (1) {

            printf("\n");
            printf("Which line ?");
            printf("\n");
            scanf("%d", &line);
            printf("which column ");
            printf("\n");
            scanf("%d", &column);
            printf("\n");

            if (line < 1 || line > 3 || column < 1 || column > 3) {
                printf("Invalid position! Please choose a line and column between 1 and 3.\n");
                continue;
            }

            line--;
            column--;

            if (gameBoard[line][column] != '.') {
                printf("This cell is already occupied! Try again.\n");
                continue;
            }

            gameBoard[line][column] = currentPlayer;
            break;
        }

        if (victoryCheck(gameBoard)) {
            displayGameBoard(gameBoard);
            printf("Congratulations %s, you won!\n", users[player]);
            break;
        }

        if (checkNull(gameBoard)) {
            displayGameBoard(gameBoard);
            printf("It's a null! No winner this time.\n");
            break;
        }

        player = (player == 0) ? 1 : 0;
    }
}

int main(void) {

    int playAgain = 1;

    while (playAgain) {

        printf("----------------- Configuration -----------------");
        printf("\n");

        char gameBoard[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                gameBoard[i][j] = '.';
            }
        }

        int nbPlayers = 2;

        char usernames[nbPlayers][50];

        for (int i = 0; i < nbPlayers; i++) {
            printf("Username of player %d ?", i + 1);
            printf("\n");
            scanf("%49s", usernames[i]);
        }

        printf("\n");
        printf("------------------ Game Start -------------------");

        printf("\n");
        displayGameBoard(gameBoard);
        play(gameBoard, usernames);

        printf("Do you want to play again? (1 = Yes, 0 = No): ");
        scanf("%d", &playAgain);
    }

    return 0;
}
