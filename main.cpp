#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <random>
#ifdef _WIN32 || _WIN64
#define clear() system("cls")
//define clear function for windows
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
define clear()
// Other oprating systems are not supported
#endif

using namespace std;
enum Win_state{CPU,Player,Draw,None};

Win_state is_winning(char board[3][3]){ // checking to see who is winner
    //CPU
        if((board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') ||
           (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') ||
           (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') ||
           (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') ||
           (board[2][0] == 'x' && board[1][1] == 'x' && board[0][2] == 'x') ||
           (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') ||
           (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') ||
           (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x')) return CPU;
    //Player
        else if((board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') ||
                (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') ||
                (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') ||
                (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') ||
                (board[2][0] == 'o' && board[1][1] == 'o' && board[0][2] == 'o') ||
                (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') ||
                (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') ||
                (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o')) return Player;
    else { // game is still not completed
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' '){
                    return None;
                }
            }
        }
        return Draw;//no one is winner
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
            if((y <= 3 || x <= 3) && (y >= 1 || x >= 1)){ //Checking to see if the Cell is Empty or not
                if(brd[y - 1][x - 1] == ' '){
                brd[y - 1][x - 1] = 'o';//Putting O in board
                break;//Exit from prompt loop
                } else{
                    cout << "The Cell is full";
                    continue;
                }
            }
            else{
                cout << "you entered a number greaterthan 3 or less than 1" << endl;
                continue;
            }
        }
        Win_state win = is_winning(brd);//Who is won
        if (win == CPU) cout << "Computer won!";
        else if (win == Player) cout << "You won!";
        else if (win == Draw) cout << "Draw!";
        if(win != None){
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

    }
    return 0;
}