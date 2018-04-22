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

//--Declare Functions
int GetBoardSize(int x, int y);
int SetupInitialBoards(int BoardDim);
int OutputPublicBoard();
int OutputPrivateBoard();
int PlantMines();
int MakeAMove();
int ProcessMove();
int PressEnter();
void OutputStatus(bool here);
int ProcessAdjacencies(int xMove, int yMove);

//--Declare Variables
char PrivateBoard[8][8];
char PublicBoard[8][8];
char MineField[64];
int BoardDim=8;
int BoardSize = BoardDim * BoardDim;
int NumOfMines=21;
bool StillPlaying = true;
int xMove=0;
int yMove=0;
int NeighbourMines=0;

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
    for (int m = 0; m <= NumOfMines-1; m++){
        int PlaceMineAt = rand() % (BoardSize);
        MineField[PlaceMineAt] = 'X';
        cout << PlaceMineAt << " " ;
    }
    cout << endl;
    int PrivateKey = 0;
    for (int k = 0; k <= BoardDim-1; k++){
            for (int l = 0; l <= BoardDim-1; l++){
                /* used for debug
                cout << PrivateKey << ": " << k << "," << l << endl;
                */
                if (MineField[PrivateKey] == 'X'){
                    PrivateBoard[k][l] = 'X';
                    /* used for debug
                    cout << "Mine Position: " << PrivateKey << endl;
                    cout << "Mine Placed at: " << k << "." << l << endl;
                    */
                 }
                ++PrivateKey;
            }
    }
    return 0;
}


int MakeAMove(){
    cout << "Make A Move (x - then enter)";
    cin >> xMove;
    cout << "Make A Move (y - then enter)";
    cin >> yMove;
    return 0;
}


int OutputPublicBoard() {
    cout << endl << "Public Board:" << endl << endl ;
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int k = 0; k <= BoardDim-1; k++){
        cout << k << " ";
        for (int l = 0; l <= BoardDim-1; l++){
            cout << PublicBoard[k][l]; // output cell contents
            cout << " ";
        }
        cout << endl;
        
    }
    cout << endl;
    return 0;
}

// used for debug and test
int OutputPrivateBoard() {
    cout << endl << "Private Board:" << endl << endl ;
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int k = 0; k <= BoardDim-1; k++){
        cout << k << " ";
        for (int l = 0; l <= BoardDim-1; l++){
            cout << PrivateBoard[k][l]; // output cell contents
            cout << " ";
        }
        cout << endl ;
        
    }
    return 0;
}

int PressEnter() {
    cout << "Press q then Enter to quit";
    char waitforit;
    cin >> waitforit;
    return 0;
}

void OutputStatus(bool here) {
    if (here == true) {
        cout << "STILL PLAYING" << endl;
    }
    else {
        cout << "YOU LOST" << endl;
    }
}

int ProcessMove(){
    cout << "you chose x: " << xMove << " and y: " << yMove << endl;
    if (PrivateBoard[xMove][yMove] == 'X'){
        cout << endl;
        cout << "********************" << endl;
        cout << "Mine Found at " << xMove << "," << yMove << "!" << endl;
        cout << "YOU LOSE!" << endl;
        cout << "********************" << endl << endl;
        StillPlaying = false;
    }
    else {
        ProcessAdjacencies(xMove,yMove);

    }
    return 0;
    
}

int ProcessAdjacencies(int x, int y){
    NeighbourMines=0;
    //Run counterclockwise around the chosen cell and calculate the number of adjacent mines
    
    //case 1: North x-1 and y
    if (x > 0){
        if (PrivateBoard[x-1][y]=='X'){
            NeighbourMines++;
        }
    }
    //case 2: NorthWest x-1 and y-1
    if (x > 0 && y > 0){
        if (PrivateBoard[x-1][y-1]=='X'){
            NeighbourMines++;
        }
    }
    //case 3: West x and y-1
    if (x > 0){
        if (PrivateBoard[x][y-1]=='X'){
            NeighbourMines++;
        }
    }
    //case 4: SouthWest x+1 and y-1
    if (x < 7 && y > 0){
        if (PrivateBoard[x+1][y-1]=='X'){
            NeighbourMines++;
        }
    }
    //case 5: South x+1 and y
    if (x < 7 ){
        if (PrivateBoard[x+1][y]=='X'){
            NeighbourMines++;
        }
    }
    //case 6: SouthEast x+1 and y+1
    if (x < 7 && y < 7){
        if (PrivateBoard[x+1][y+1]=='X'){
            NeighbourMines++;
        }
    }
    //case 7: East x and y+1
    if (y < 7){
        if (PrivateBoard[x][y+1]=='X'){
            NeighbourMines++;
        }
    }
    //case 8: NorthEast x+1 and y+1
    if (y < 7){
        if (PrivateBoard[x-1][y+1]=='X'){
            NeighbourMines++;
        }
    }
    
    cout << "you have " << NeighbourMines << " Mines nearby - watch out" << endl;
    char NumberOfMines = NeighbourMines+'0';
    PublicBoard[x][y]=NumberOfMines;
   
    return 0;
}


//************************************
//************ Main ******************
//************************************

int main() {
    cout << "BoardDim: " << BoardDim << " x " << BoardDim << endl << "# of Mines: " << NumOfMines << endl;
    SetupInitialBoards(BoardDim);
    PlantMines();
    OutputPrivateBoard(); //uncomment for debugging or cheating
    
    StillPlaying = true;
    OutputStatus(StillPlaying);
    
    while (StillPlaying) {
        OutputPublicBoard();
        MakeAMove();
        ProcessMove();
    }
    PressEnter();
    

    
    //end of program
    cout << endl << "Thank you for Playing" << endl << endl;
    return 0;
}

//
//end
//
