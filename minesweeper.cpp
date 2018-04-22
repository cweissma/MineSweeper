//CPEG676 Spring II 2018
//Charles Weissman - cweissma@udel.edu
//Assignment 1 - Minesweeper
//Due April 2018


#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//************************************
//********* Declaration **************
//************************************

//--Functions
int GetBoardSize(int x, int y);
int SetupInitialBoards(int BoardDim);
int OutputBoard();
int PlantMines();
int MakeAMove();
int ProcessMove();

//--Variables
char PrivateBoard[8][8];
char PublicBoard[8][8];
char MineField[64];
int BoardDim=8;
int BoardSize = BoardDim * BoardDim;
int MineSize=21;
int xMove=0;
int yMove=0;




//************************************
//************ Main ******************
//************************************

int main() {
    cout << "BoardDim: " << BoardDim << " x " << BoardDim << endl << "# of Mines: " << MineSize << endl;
    SetupInitialBoards(BoardDim);
    
    OutputBoard();
    PlantMines();
    enum Status {Active, Won, Lost};
    Status Alive = Active;
    switch(Alive) {
        case Active  : cout << "Your Status is - Active" << endl << endl;  break;
        case Won : std::cout << "You Won :-) \n"; break;
        case Lost : std::cout << "You Lost :-( t\n";  break;
    }

    MakeAMove();
    ProcessMove();
    
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



int PlantMines(){
    srand( static_cast<unsigned int>(time(NULL))); //set a random seed
    for (int m = 0; m <= MineSize-1; m++){
        int PlaceMineAt = rand() % (BoardSize);
        MineField[PlaceMineAt] = 'X';
    }
    
    return 0;
}


int MakeAMove(){
    cout << "Make A Move (x - then enter)";
    cin >> xMove;
    cout << "Make A Move (y - then enter)";
    cin >> yMove;
/*    cout << "Press q to quit";
    char waitforit;
    cin >> waitforit; */
    return 0;
}

    
int ProcessMove(){
    cout << "you chose x:" << xMove << "and y: " << yMove << endl;
    PublicBoard[xMove][yMove] = '#';
    OutputBoard();
    
    return 0;
    
}

int OutputBoard() {
    cout << endl << "OutputPublicBoard:" << endl << endl ;
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int k = 0; k <= BoardDim-1; k++){
        cout << k << " ";
        for (int l = 0; l <= BoardDim-1; l++){
            cout << PublicBoard[k][l]; // output cell contents
            cout << " ";
        }
        cout << endl ;
        
    }
    return 0;
}

//
//end
//
