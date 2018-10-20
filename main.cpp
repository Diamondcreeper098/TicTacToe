#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <random>
#ifdef _WIN32
#define clear() system("cls")
//define clear function for windows 32 bit
#elif _WIN64
#define clear() system("cls")
//define clear function for windows 64 bit
#elif __unix || __unix__
#define clear() system("clear")
//define clear function for UNIX
#elif __APPLE__ || __MACH__
#define clear() system("clear")
//define clear function for Mac OS
#elif __linux__
#define clear() system("clear")
//define clear function for Linux
#elif __FreeBSD__
#define clear() system("clear")
//define clear function for FreeBSD
#else
//other operating systems sre not supported
#endif

using namespace std;

char * is_winning(char board[3][3]){ // checking to see who is winner
    //CPU
        //Horizontal Checking for X
        if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') return "cpu";
        else if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') return "cpu";
        else if(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') return "cpu";
        //Cross Checking for X
        else if(board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') return "cpu";
        else if(board[2][0] == 'x' && board[1][1] == 'x' && board[0][2] == 'x') return "cpu";
        //Vertical Checking for X
        else if(board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') return "cpu";
        else if(board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') return "cpu";
        else if(board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x') return "cpu";
    //Player
        //Horizontal Checking for O
        else if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') return "ply";
        else if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') return "ply";
        else if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') return "ply";
        //Cross Checking for O
        else if(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') return "ply";
        else if(board[2][0] == 'o' && board[1][1] == 'o' && board[0][2] == 'o') return "ply";
        //Vertical Checking for O
        else if(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') return "ply";
        else if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') return "ply";
    else if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') return "ply";
    else { // game is still not completed
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' '){
                    return "None";
                }
            }
        }
        return "Draw";//no one is winner
    }
}

int main() {
    char brd[3][3] = {{' ',' ',' '},
                      {' ',' ',' '},
                              {' ',' ',' '}}; //Board
    srand(time(0));// Initializing Random function
    while(true){
        int x,y;//Row and Column
        char prompt;//Prompt for Y / N
        clear();// Clear screen
        for (auto &&item : brd) { //Printing Board
            for (auto &&item2 : item) {
                cout << '|' << item2 << '|' << " ";
            }
            cout << endl << "-----------" << endl;
        }
        while(true){
            cout << "Enter row: "; //Prompt for Row
            cin >> x;
            cout << "Enter column: ";//Prompt for Column
            cin >> y;
            if(brd[y - 1][x - 1] != 'x' && brd[y - 1][x - 1] != 'o'){ //Checking to see if the Cell is Empty or not
                if(y > 3 || x > 3)
                {
                    cout << "Enter a number between 1 and 3" << endl;
                    continue; // Continue to getting prompt if user entered number more than 3
                }
                else brd[y - 1][x - 1] = 'o';//Putting O in board
                break;//Exit from prompt loop
            }
            else{
                cout << "Cell is full" << endl;
                continue;
            }
        }
        while(true){
            x = (rand() % 3) + 1;//getting random number between 1 and 3
            y = (rand() % 3) + 1;//getting random number between 1 and 3
            if(brd[y - 1][x - 1] != 'o' && brd[y - 1][x - 1] != 'x'){
                brd[y - 1][x - 1] = 'x';
                break; //Back to game itself
            }
            else{
                continue; //Continue to getting random number if Cell is full
            }
        }
        char* win = is_winning(brd);//Who is won
        if (win == "cpu")
        {
            cout << "Computer won!";
        }
        else if (win == "ply"){
            cout << "You won!";
        }
        else if (win == "Draw"){
            cout << "Draw!";
        }
        else{
            continue;
        }
        if(win != "None"){
            cout << "Do You want to play again? (Y/N) ";
            cin >> prompt;
            if(tolower(prompt) == 'y'){
                clear();//Clear screen
                for (int i = 0; i < 3; ++i) { //Clearing board
                    for (int j = 0; j < 3; ++j) {
                        brd[i][j] = ' ';
                    }
                }
                continue;//Continue the game loop
            }
            else{
                break;//Break the game loop
            }
        }
    }
    return 0;
}