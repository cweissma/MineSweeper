//CPEG676 Spring II 2018
//Charles Weissman - cweissma@udel.edu
//Assignment 1 - Minesweeper
//Due April 2018

#include <string>
#include <iostream>
#include <iomanip>
//#include <vector>
using namespace std;

//************************************
//********* Declaration **************
//************************************

//--Functions
int GetBoardSize(int x);
int SetupInitialBoard(int BoardSize, int BombSize);
int OutputBoard(int BoardSize);

//--Variables
int BoardSize = 1;
int BombSize = 1;
char Board[10][10];

//************************************
//************ Main ******************
//************************************

int main() {
    BoardSize = GetBoardSize(BoardSize);
    BombSize = BoardSize / 3;
    SetupInitialBoard(BoardSize,BombSize);
    
    OutputBoard(BoardSize);
    cout << endl << "Thank you for Playing" << endl << endl;
}

//************************************
//************ Functions *************
//************************************

int GetBoardSize(int x) {
    // cout << "Please Enter Board Size: "; cin >> x;
    x = 8;
    return x;
}

int SetupInitialBoard(int x, int y) {
    int cummulator = 1;
    
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= x; j++){
            Board[i][j] = cummulator + '0';
            ++ cummulator;
        }
    }
    return 0;
}

int OutputBoard(int y) {
    cout << endl << "OutputBoard:" << endl ;
    int kmax = y,lmax = y;
    for (int k = 1; k <= kmax; k++){
        cout << " | ";
        for (int l = 1; l <= lmax; l++){
            cout << Board[k][l] << " | ";
        }
        cout << endl ;
        
    }
    return 0;
}
