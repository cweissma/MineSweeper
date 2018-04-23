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
int Winner();

//--Declare Variables
int BoardDim=8; //static size of the playing field
char PrivateBoard[8][8]; //board for keeping track of mines
char PublicBoard[8][8]; // board for the player to see
char MineField[64]; //total number of cells (8x8)
int BoardSize = BoardDim * BoardDim;
int NumOfMines=21; //for a board of 8x8, an average difficulty
int NumOfSafeSpaces= BoardSize-NumOfMines; //64 - 21 = number of safe spaces
bool StillPlaying = true;
int xMove=0;
int yMove=0;
int MoveNumber=0;
int NeighbourMines=0;


//************************************
//************ Functions *************
//************************************

// this will set up the boards and put dashes in the public board and private board
int SetupInitialBoards(int x) {
     cout << "BoardDim: " << BoardDim << " x " << BoardDim << endl << "# of Mines: " << NumOfMines << endl;
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

// this will create an array of 64, randomly place mines, and then loop through the private board placing mines
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

                if (MineField[PrivateKey] == 'X'){
                    PrivateBoard[k][l] = 'X';
                 }
                ++PrivateKey;
            }
    }
    return 0;
}

//this accepts an x,y input from the player and validate that x and y are between 0 and 7
int MakeAMove(){
    bool ValidXMove = false;
    bool ValidYMove = false;
    while (!ValidXMove){
        cout << "Make A Move (x - then enter): ";
        cin >> xMove;
        if (xMove < 0 || xMove > 7) {
            cout << "Invalid Move, try again: " << endl;
        }
        else {
            ValidXMove = true;
        }
    }
    // check that Y is valid, also check that the space wasnt used before by checking if it has a number (not a '-')
    while (!ValidYMove){
        cout << "Make A Move (y - then enter): ";
        cin >> yMove;
        if (yMove < 0 || yMove > 7) {
            cout << "Invalid Move, outside of range (0-7)! Try again: " << endl;
        }
        if (PublicBoard[xMove][yMove] != '-') {
            cout << "Invalid Move, space already used! Try again: " << endl;
        }
        else {
            ValidYMove = true;
        }
    }
    return 0;
}

//this will output the players board
int OutputPublicBoard() {
    cout << endl << "Public Board: Move Number: " << MoveNumber << " " << endl << endl;
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

// used for debug and test - and cheating. to remove, comment out the call to it in main()
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

//simple function to wait for the users input
int PressEnter() {
    cout << "Press q then Enter to quit" ; // it's a lie. you can press any letter to quit
    char waitforit;
    cin >> waitforit;
    return 0;
}

// shows your status
void OutputStatus(bool here) {
    if (here == true) {
        cout << "STILL PLAYING" << endl;
    }
    else {
        cout << "YOU LOST" << endl;
    }
}

// process here if you are a winner
int Winner() {
    cout << endl;
    cout << "********************" << endl;
    cout << "YOU WIN! YOU AVIODED ALL THE MINES!" << endl;
    cout << "NICE JOB!" << endl;
    cout << "********************" << endl << endl;
    StillPlaying = false;
    return 0;
}

//take the input from the player and checks for a mine in that position. if not, call the function to process adjacencies
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

// go through each of the 8 adjacencies and count the number of neighbours with mines
// then place that number back into the public board
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
    //write out the number of mines to the chosen cell in the public board
    cout << "you have " << NeighbourMines << " Mines nearby - watch out" << endl;
    char NumberOfMines = NeighbourMines+'0';
    PublicBoard[x][y]=NumberOfMines;
    return 0;
}


//************************************
//************ Main ******************
//************************************

int main() {
    SetupInitialBoards(BoardDim);
    PlantMines();
    OutputPrivateBoard(); //uncomment for debugging or cheating
    
    StillPlaying = true;
    OutputStatus(StillPlaying);
    
    while (StillPlaying && MoveNumber < NumOfSafeSpaces) {
        OutputPublicBoard();
        MakeAMove();
        ProcessMove();
        MoveNumber++;
    }
    if (MoveNumber == NumOfSafeSpaces){
        Winner();
    }
  
    PressEnter();
    
    //end of program
    cout << endl << "Thank you for Playing" << endl << endl;
    return 0;
}
// the end

