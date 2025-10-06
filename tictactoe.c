#include <stdio.h>
#include <stdlib.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
char checkWinner();
void printWinner(char);

int main() {
    char winner = ' ';
    char response;
    
    do {
        winner = ' ';
        response = ' ';
        resetBoard();
        
        while(winner == ' ' && checkFreeSpaces() != 0) {
            printBoard();
            
            player1Move();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }
            
            printBoard();
            
            player2Move();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0) {
                break;
            }
        }
        
        printBoard();
        printWinner(winner);
        
        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        
    } while(response == 'Y' || response == 'y');
    
    printf("Thanks for playing!\n");   
    return 0;
}
void resetBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");}

int checkFreeSpaces() {
    int freeSpaces = 9;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void player1Move() {
    int x, y;
    
    do {
        printf("Player 1 (X) - Enter row (1-3) and column (1-3): ");
        scanf("%d %d", &x, &y);
        x--;
        y--;       
        if(x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid move! Please enter numbers between 1 and 3.\n");
        } else if(board[x][y] != ' ') {
            printf("That spot is already taken!\n");
        } else {
            board[x][y] = PLAYER1;
            break;
        }
    } while(board[x][y] != ' ');
}
void player2Move() {
    int x, y;
    do {
        printf("Player 2 (O) - Enter row (1-3) and column (1-3): ");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        
        if(x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid move! Please enter numbers between 1 and 3.\n");
        } else if(board[x][y] != ' ') {
            printf("That spot is already taken!\n");
        } else {
            board[x][y] = PLAYER2;
            break;
        }
    } while(board[x][y] != ' ');
}

char checkWinner() {
    // check rows.
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    
    // checks columns.
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    
    // check diagonals.
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    
    return ' ';
}

void printWinner(char winner) {
    if(winner == PLAYER1) {
        printf("PLAYER 1 (X) WINS!\n");
    } else if(winner == PLAYER2) {
        printf("PLAYER 2 (O) WINS!\n");
    } else {
        printf("IT'S A TIE!\n");
    }
}
