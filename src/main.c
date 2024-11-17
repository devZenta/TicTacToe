#include <stdio.h>

/*
 * 0 : loose
 * 1 : win
*/

//Fonction vérification de la victoire
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

//Fonction affichage du tableau
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

int main(void) {

    printf("----------------- Configuration -----------------");
    printf("\n");

    //Création du tableau
    char gameBoard[3][3];

    //Initialisation du tableau
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gameBoard[i][j] = '.';
        }
    }

    int nbPlayers = 2;

    //Création d'une liste pour stock le pseudo des joueurs
    char usernames[nbPlayers][50];

    //Récupération des pseudos avec ajout dans la liste
    for (int i = 0; i < nbPlayers; i++) {
        printf("Username of player %d ?", i + 1);
        printf("\n");
        scanf("%49s", usernames[i]);
    }

    printf("\n");
    printf("------------------ Game Start -------------------");

    printf("\n");
    displayGameBoard(gameBoard);



    return 0;
}
