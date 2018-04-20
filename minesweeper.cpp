//CPEG676 Spring II 2018
//Charles Weissman - cweissma@udel.edu
//Assignment 1 - Minesweeper
//Due April 2018

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
//#include <vector>
using namespace std;

//************************************
//********* Declaration **************
//************************************

//--Functions
int GetBoardSize(int x, int y);
int SetupInitialBoards(int BoardDim);
int OutputBoard(int BoardSize);
int PlantMines();

//--Variables
char PrivateBoard[8][8];
char PublicBoard[8][8];
char MineField[64];
int BoardDim=8;
int BoardSize = BoardDim * BoardDim;
int MineSize=21;



//************************************
//************ Main ******************
//************************************

int main() {
    cout << "BoardDim: " << BoardDim << " x " << BoardDim << endl << "# of Mines: " << MineSize << endl;
    SetupInitialBoards(BoardDim);
    
    OutputBoard(BoardDim);
    PlantMines();
    
    
    //end of program
    cout << endl << "Thank you for Playing" << endl << endl;
    return 0;
}

//************************************
//************ Functions *************
//************************************


int SetupInitialBoards(int x) {
    //Public board first
    int PublicKey = 1;
    for (int i = 0; i <= x-1; i++){
        for (int j = 0; j <= x-1; j++){
            PublicBoard[i][j] = '-';
            ++ PublicKey;
        }
    }
    //Private board next
    int PrivateKey = 1;
    for (int k = 0; k <= x-1; k++){
        for (int l = 0; l <= x-1; l++){
            PrivateBoard[k][l] = '-';
            ++ PrivateKey;
        }
    }
    
    return 0;
}

int OutputBoard(int y) {
    cout << endl << "OutputPublicBoard:" << endl << endl ;
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int k = 0; k <= y-1; k++){
        cout << k << " ";
        for (int l = 0; l <= y-1; l++){
            cout << PublicBoard[k][l]; // output cell contents
            cout << " ";
        }
        cout << endl ;
        
    }
    return 0;
}
int PlantMines(){
    srand( static_cast<unsigned int>(time(NULL))); //set a random seed
    for (int m = 0; m <= MineSize-1; m++){
        int PlaceMineAt = rand() % (BoardSize);
        MineField[PlaceMineAt] = 'X';
    }

   return 0;
}

//end
