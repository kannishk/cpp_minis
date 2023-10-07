#include <iostream>
#include <vector>
using namespace std;
void generateRandomSudoku();
void printGrid();
bool solveSudoku();
bool findEmptyLocation(int &row, int&col);
bool isSafe(int row, int col, int num);

const int SIZE = 9;
int grid[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int main(){
    // int choice;
    // cout<<"enter choice"<<endl;
    // cin>>choice;
    // if(choice==1){
    //     generateRandomSudoku();
    // }else if(choice==2){
    //     cout<<"enter your grid(use 0 for empty cells)"<<endl;
    //     for(int i=0;i<SIZE;i++){
    //         for(int j=0;j<SIZE;j++){
    //             cin>>grid[i][j];
    //         }
    //     }
    // }else{
    //     cout<<"Invalid"<<endl;
    //     return 1;
    // }
    cout<<"Sudoku Grid"<<endl;
    printGrid();

    if(solveSudoku()){
        cout<<"Solution"<<endl;
        printGrid();
    }else{
        cout<<"No Solution"<<endl;
    }

    return 0;
}

// void generateRandomSudoku(){
//     srand(time(0));
//     for(int i=0;i<SIZE;i++){
//         for(int j=0;j<SIZE;j++){
//             grid[i][j]=rand()%SIZE+1;
//         }
//     }
// }

void printGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0)
                cout << "_ ";
            else
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveSudoku(){
    int row,col;
    if(!findEmptyLocation(row,col)){
        return true;
    }
    for(int num=0;num<=SIZE;num++){
        if(isSafe(row,col,num)){
            grid[row][col]=num;
            if(solveSudoku()){
                return true;
            }
            grid[row][col]=0; //This is the crux of the etire algo
        }
    }
    return false;
}

bool findEmptyLocation(int &row, int&col){
    for(row=0;row<SIZE;row++){
        for(col=0;col<SIZE;col++){
            if(grid[row][col]==0){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int row, int col, int num){
    for(int i=0;i<SIZE;i++){
        if(grid[row][i]==num || grid[i][col]==num){
            return false;
        }       
    }
    int startRow=row-row%3;//nice 
    int startCol=col-col%3;//nice
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+startRow][j+startCol]==num){
                return false;
            }
        }
    }
    return true;
}