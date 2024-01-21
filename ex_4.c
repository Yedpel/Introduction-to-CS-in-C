/******************************************
* Student name: Yedidya Peles
* Student: 322638354
* Exercise name: ex_4
******************************************/

#include <stdio.h>

#define SIZE 4
#define Full_BOARD 64
#define BIGGEST_INDEX 3
#define NUM_PLAYERS 2
#define PLAYER_ONE 1

/************************************************************************
* function name: printBoard *
* The Input: char board[SIZE][SIZE][SIZE] *
* The output: void *
* The Function operation: print the board she recived *
*************************************************************************/
void printBoard(char board[SIZE][SIZE][SIZE]) {
    //for to print tables - t
    for (int t = 0; t < SIZE; ++t) {
        //for to print rows - r
        for (int r = 0; r < SIZE; ++r) {
            //print inedxes
            printf("(%d %d %d) (%d %d %d) (%d %d %d) (%d %d %d)"
                   , t, r, 0, t, r, 1, t, r, 2, t, r, 3);
            //for to print columns - c
            for (int c = 0; c < SIZE; ++c) {
                //print row
                printf(" %c", board[t][r][c]);
            }
            //print space and down line
            printf(" \n");
        }
        //if not last table - print down two lines
        printf("\n");
    }
    //end of print board
}

/************************************************************************
* function name: cleanTurns *
* The Input: () *
* The output: void *
* The Function operation: clean the turns that didnt played in the game
*************************************************************************/
void cleanTurns() {
    char isEmpty = (char) getchar();
    while (isEmpty != '\n')
        isEmpty = (char) getchar();
}

/************************************************************************
* function name: newBoard *
* The Input: char board[SIZE][SIZE][SIZE] *
* The output: void *
* The Function operation: fill all the new board with '*'
*************************************************************************/
void newBoard(char board[SIZE][SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                board[i][j][k] = '*';
            }
        }
    }
}

/************************************************************************
* function name: isWin *
* The Input: char board[SIZE][SIZE][SIZE] *
* The output: int (1==win, 0==not yet)*
* The Function operation: fill all the new board with '*'
*************************************************************************/
int isWin(char board[SIZE][SIZE][SIZE]) {
    for (int t = 0; t < SIZE; ++t) {
        //check win in one table
        int sumXCross1 = 0;
        int sumOCross1 = 0;
        int sumXCross2 = 0;
        int sumOCross2 = 0;
        for (int i = 0; i < SIZE; ++i) {
            //check win in column
            int sumXCol = 0;
            int sumOCul = 0;
            //count X/O in the column
            for (int j = 0; j < SIZE; ++j) {
                if (board[t][i][j] == 'X')
                    sumXCol++;
                else if (board[t][i][j] == 'O')
                    sumOCul++;
                //check if the count x/o 4 - win
                if (sumXCol == SIZE) {
                    printf("X is the winner.\n");
                    printBoard(board);
                    return 1;
                } else if (sumOCul == SIZE) {
                    printf("O is the winner.\n");
                    printBoard(board);
                    return 1;
                }
                //end check win in column
            }
            //check win in row
            int sumXRow = 0;
            int sumORow = 0;
            //count X/O in the row
            for (int j = 0; j < SIZE; ++j) {
                if (board[t][j][i] == 'X')
                    sumXRow++;
                else if (board[t][j][i] == 'O')
                    sumORow++;
                //check if the count x/o 4 - win
                if (sumXRow == SIZE) {
                    printf("X is the winner.\n");
                    printBoard(board);
                    return 1;
                } else if (sumORow == SIZE) {
                    printf("O is the winner.\n");
                    printBoard(board);
                    return 1;
                }
                //end check win in row
            }
            //check win in crosses
            for (int j = 0; j < SIZE; ++j) {
                //count X/O in the croses
                if (i == j) {
                    if (board[t][i][j] == 'X')
                        sumXCross1++;
                    else if (board[t][i][j] == 'O')
                        sumOCross1++;
                    if (board[t][i][(BIGGEST_INDEX - j)] == 'X')
                        sumXCross2++;
                    else if (board[t][i][(BIGGEST_INDEX - j)] == 'O')
                        sumOCross2++;
                    //check if the count x/o 4 - win
                    if (sumXCross1 == SIZE || sumXCross2 == SIZE) {
                        printf("X is the winner.\n");
                        printBoard(board);
                        return 1;
                    } else if (sumOCross1 == SIZE || sumOCross2 == SIZE) {
                        printf("O is the winner.\n");
                        printBoard(board);
                        return 1;
                    }
                    //end if index are on the cross
                }
                //end of for loop
            }
            //end check win in crosses
        }
        //end check win in one table
    }

    //check plumbs
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int sumXPlumb = 0;
            int sumOPlumb = 0;
            //count X/O in the Plumb
            for (int t = 0; t < SIZE; ++t) {
                if (board[t][i][j] == 'X')
                    sumXPlumb++;
                else if (board[t][i][j] == 'O')
                    sumOPlumb++;
                //check if the count x/o 4 - win
                if (sumXPlumb == SIZE) {
                    printf("X is the winner.\n");
                    printBoard(board);
                    return 1;
                } else if (sumOPlumb == SIZE) {
                    printf("O is the winner.\n");
                    printBoard(board);
                    return 1;
                }
                //end of count X/O in the Plumb
            }
            //end of for loop
        }
        //end of check plumbs
    }

    //check plumb croses
    int sumXCrossPlumb1 = 0;
    int sumOCrossPlumb1 = 0;
    int sumXCrossPlumb2 = 0;
    int sumOCrossPlumb2 = 0;
    int sumXCrossPlumb3 = 0;
    int sumOCrossPlumb3 = 0;
    int sumXCrossPlumb4 = 0;
    int sumOCrossPlumb4 = 0;
    for (int i = 0; i < SIZE; ++i) {
        //check crossplumb1 (000--333)
        if (board[i][i][i] == 'X')
            sumXCrossPlumb1++;
        else if (board[i][i][i] == 'O')
            sumOCrossPlumb1++;
        //check if the count x/o 4 - win
        if (sumXCrossPlumb1 == SIZE) {
            printf("X is the winner.\n");
            printBoard(board);
            return 1;
        } else if (sumOCrossPlumb1 == SIZE) {
            printf("O is the winner.\n");
            printBoard(board);
            return 1;
            //end check crossplumb1
        }
        //check crossplumb2 (003--330)
        if (board[i][i][(BIGGEST_INDEX - i)] == 'X')
            sumXCrossPlumb2++;
        else if (board[i][i][(BIGGEST_INDEX - i)] == 'O')
            sumOCrossPlumb2++;
        //check if the count x/o 4 - win
        if (sumXCrossPlumb2 == SIZE) {
            printf("X is the winner.\n");
            printBoard(board);
            return 1;
        } else if (sumOCrossPlumb2 == SIZE) {
            printf("O is the winner.\n");
            printBoard(board);
            return 1;
            //end check crossplumb2
        }
        //check crossplumb3 (030--303)
        if (board[i][(BIGGEST_INDEX - i)][i] == 'X')
            sumXCrossPlumb3++;
        else if (board[i][(BIGGEST_INDEX - i)][i] == 'O')
            sumOCrossPlumb3++;
        //check if the count x/o 4 - win
        if (sumXCrossPlumb3 == SIZE) {
            printf("X is the winner.\n");
            printBoard(board);
            return 1;
        } else if (sumOCrossPlumb3 == SIZE) {
            printf("O is the winner.\n");
            printBoard(board);
            return 1;
            //end check crossplumb3
        }
        //check crossplumb4 (030--303)
        if (board[(BIGGEST_INDEX - i)][i][i] == 'X')
            sumXCrossPlumb4++;
        else if (board[(BIGGEST_INDEX - i)][i][i] == 'O')
            sumOCrossPlumb4++;
        //check if the count x/o 4 - win
        if (sumXCrossPlumb4 == SIZE) {
            printf("X is the winner.\n");
            printBoard(board);
            return 1;
        } else if (sumOCrossPlumb4 == SIZE) {
            printf("O is the winner.\n");
            printBoard(board);
            return 1;
        }
        //end of check croses plumbes
    }
//there is no win
    return 0;
//end of isWin
}

/************************************************************************
* function name: game *
* The Input: char start (y/n) *
* The output: char start (y/n) *
* The Function operation: play one game, and ask if to continue *
*************************************************************************/
char game(char start) {
    char board[SIZE][SIZE][SIZE];
    int turn = 0;
    newBoard(board);
    printf("Please enter your game sequence.\n");
    //play until victory/tie/incorrect input
    while (turn < Full_BOARD) {
        turn++;
        //play the turn
        int table;
        int row;
        int column;
        scanf(" %d %d %d", &table, &row, &column);
        //if incorrect input
        if (table < 0 || table >= SIZE || row < 0 ||
            row >= SIZE || column < 0 || column >= SIZE) {
            printf("Input incorrect.\n");
            break;
        }
        // if location is not empty
        if (board[table][row][column] != '*') {
            printf("Input incorrect.\n");
            break;
        }
        //enter X\O to the location
        if (turn % NUM_PLAYERS == PLAYER_ONE)
            board[table][row][column] = 'X';
        else board[table][row][column] = 'O';
        //check if there is a victory now
        if (isWin(board) == 1) { break; }
        //check if tie
        if (turn == Full_BOARD) {
            printf("Tie.\n");
            printBoard(board);
        }
        //end play the turn
    }
    cleanTurns();
    printf("Would you like to continue? (y/n)\n");
    scanf(" %c", &start);
    return start;
//end of play this game
}

int main() {
    //print want to play ? - y==yes, n==no
    char start;
    printf("Would you like to start? (y/n)\n");
    scanf(" %c", &start);
    //start new game until we received n
    while (start != 'n') {
        start = game(start);
    }
    //we received n - end the game
    printf("YEET");
    //end of program
    return 0;
}
