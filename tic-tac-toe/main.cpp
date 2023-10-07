//tictactoe
#include<iostream>
using namespace std;
bool check_winner();

char board[3][3] = {{' ', ' ', ' '},
                   {' ', ' ', ' '},
                   {' ', ' ', ' '}};
    char current_player='X';

void drawBoard() {
    cout << "  0 1 2" << endl;
    for(int i = 0; i < 3; i++) {
        cout << i << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "  -----" << endl;
    }
}



bool isBoardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    while(true){
        drawBoard();
        cout<<"Enter your move"<<endl;
        int row,column;
        cin>>row>>column;

        if(row < 0 || row > 2 || column < 0 || column > 2 || board[row][column] != ' '){
            cout<<"invalid"<<endl;
            continue;
        }

        board[row][column]=current_player;

        if(check_winner()){
            drawBoard();
            cout<<"Player "<<current_player<<" wins"<<endl;
            return 0;
        }
        if(isBoardFull()) {
            drawBoard();
            cout << "It's a draw!" << endl;
            return 0;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

bool check_winner(){
    for(int i=0;i<3;i++){
        if(board[i][0] == current_player && board[i][1] == current_player && board[i][2]==current_player){
            return true;
        }
        if(board[0][i] == current_player && board[1][i] == current_player && board[2][i]==current_player){
            return true;
        }
    }
    if(board[0][0] == current_player && board[1][1] == current_player && board[2][2]==current_player){
        return true;
    }
    if(board[0][2] == current_player && board[1][1] == current_player && board[2][0]==current_player){
        return true;
    }

    return false;
}