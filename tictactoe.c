#include <stdio.h>
#define ROW 3  // row and column for 2d array
#define COL 3

int isboardfull(int[ROW][COL]);
void generatecomputerchoice(int[ROW][COL]);
int haswinningpattern(int, int[ROW][COL]);
void printboard(int[ROW][COL]);
int getxcoordinate();
int getycoordinate();

int main() {
        int board[ROW][COL] = {{1,1,1}, //initializes a 2d array with 1's in all cells signifying the array is empty
                               {1,1,1},
                               {1,1,1}};

        //get user name and print welcome message
        char player[15];
        int x,y;
        printf("\nWelcome to Tic Tac Toe. \n\nWhat is your name?(only 13 characters allowed)  ");
        fgets(player, 15, stdin);
        int c;
        while ((c = getchar()) != EOF && c != '\n'); //clears input buffer
        printf("\nHello %sLets have fun!\n", player);
        printf("You = X || Computer = 0\n");
        printf("To play, enter your choice as coordinates. 0,0 is the first cell, just like an array.");
        printf("You will be asked to enter the x-coordinate first, and then the y-coordinate.\n");
        printf("Lets begin!\n");

        printboard(board); //prints the empty board
        printf("\n");

        while(1){
                if(isboardfull(board)){  //if the board is full then there is no winner
                        printf("Game ended. No winner.\n");
                        break;
                }

                //gets x and y coordinates from user seperately
                int x,y;
                x = getxcoordinate();
                y = getycoordinate();


                //if x and y coordinate user enters is taken, the user is prompted to enter new coordinates until a valid option is entered
                while(board[x][y] == 88 || board[x][y] == 0){
                        printf("\nThe coordinates (%d,%d) are taken. Please enter new coordinates: \n", x,y);
                        x = getxcoordinate();
                        y = getycoordinate();

                        if(board[x][y] != 88 && board[x][y] != 0){
                                break;
                        }
                }

                board[x][y] = 88; //sets x and y coordinate from user to 88 (will be converted to X when board is printed)

                //if the user has a winning pattern prints a congratulatory message and ends the game
                if(haswinningpattern(88, board)){
                        printf("You won. Congrats %s", player);
                        printf("\n");
                        printboard(board);
                        printf("\n");
                        break;
                }

                generatecomputerchoice(board); //generates computer choice and puts in the board

                //if the computer has a winning pattern, prints a message and ends the game
                if(haswinningpattern(0, board)){
                        printf("Computer won. Better luck next time %s", player);
                        printf("\n");
                        printboard(board);
                        printf("\n");
                        break;
                }
                printboard(board); //prints the board with both user's and computer's choices
                printf("\n");
        }
}


//checks if player (0 or 88) has a winning pattern
int haswinningpattern(int player, int arr[ROW][COL]){
        if(arr[0][0] == player && arr[1][1] == player && arr[2][2] == player){
                return 1;
        }
        if(arr[0][0] == player && arr[0][1] == player && arr[0][2] == player){
                return 1;
        }
        if(arr[0][0] == player && arr[1][0] == player && arr[2][0] == player){
                return 1;
        }
        if(arr[0][1] == player && arr[1][1] == player && arr[2][1] == player){
                return 1;
        }
        if(arr[0][2] == player && arr[1][2] == player && arr[2][2] == player){
                return 1;
        }
        if(arr[0][2] == player && arr[1][1] == player && arr[2][0] == player){
                return 1;
        }
        if(arr[1][0] == player && arr[1][1] == player && arr[1][2] == player){
                return 1;
        }
        if(arr[2][0] == player && arr[2][1] == player && arr[2][2] == player){
                return 1;
        }

        return 0;
}

//generates simple computer choice
void generatecomputerchoice(int arr[ROW][COL]){
        int i,j;
        for(i = 0; i < ROW; i++){
                for(j = 0; j < COL; j++){
                        if(arr[i][j] != 88 && arr[i][j] != 0){
                                arr[i][j] = 0;
                                return;
                        }
                }
        }
}

//checks if board is full. If any cell equals 1, board is not full else board is full
int isboardfull(int board[ROW][COL]){
        int i,j;
        for(i = 0; i < ROW; i++){
                for(j = 0; j < COL; j++){
                        if(board[i][j] == 1){
                                return 0;
                        }
                }
        }

        return 1;
}

//prints the board
void printboard(int board[ROW][COL]){
        int i, j;
        for(i = 0; i < ROW; i++){
                for(j = 0; j < COL; j++){
                        if(j == 2 && board[i][j] == 0){
                                printf(" %d ", board[i][j]);
                        }
                        else if(board[i][j] == 0){
                                printf(" %d |", board[i][j]);
                        }
                        if(j == 2 && board[i][j] == 88){
                                printf(" %c ", board[i][j]);
                        }
                        else if(board[i][j] == 88){
                                printf(" %c |", board[i][j]);
                        }
                        if(j == 2 && board[i][j] == 1){
                                printf("   ");
                        }
                        else if(board[i][j] == 1){
                                printf("   |");
                        }
                }
                if(i == 0 || i == 1){
                        printf("\n---|---|---\n");
                }
        }
}

//gets a valid integer x coordinate from the user
int getxcoordinate(){
        int x;
        char input[5];
        int validinput = 0;

        while(!validinput){
                printf("Enter the x-coordinate (has to be in between 0 and 2 inclusive): ");
                fgets(input, 5, stdin);
                int c;
                while ((c = getchar()) != EOF && c != '\n'); //clears input buffer

                int i = 0;
                while(input[i] != '\0'){
                        if(input[i] == '\n'){
                                break;
                        }
                        if(!isdigit(input[i])){
                                printf("Invalid entry. Please enter a valid integer. \n");
                                break;
                        }
                        i++;
                }
                i++;

                if(input[i] == '\0'){
                        x = atoi(input);
                        if(x >= 0 && x <= 2){
                                validinput = 1;
                        }
                        else{
                                printf("The x-coordinate is out of bounds. \n");
                        }
                }
        }

        return x;
}

//gets a valid integer y coordinate from the user
int getycoordinate(){
        int y;
        char input[32];
        int validinput = 0;

        while(!validinput){
                printf("Enter the y-coordinate (has to be in between 0 and 2 inclusive): ");
                fgets(input, 32, stdin);
                int c;
                while ((c = getchar()) != EOF && c != '\n'); //clears input buffer

                int i = 0;
                while(input[i] != '\0'){
                        if(input[i] == '\n'){
                                break;
                        }
                        if(!isdigit(input[i])){
                                printf("Invalid entry. Please enter a valid integer. \n");
                                break;
                        }
                        i++;
                }
                i++;

                if(input[i] == '\0'){
                        y = atoi(input);
                        if(y >= 0 && y <= 2){
                                validinput = 1;
                        }
                        else{
                                printf("The y-coordinate is out of bounds. \n");
                        }
                }
        }

        return y;
}

