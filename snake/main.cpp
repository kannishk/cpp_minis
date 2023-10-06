//Snake Game
#include<iostream>
#include<string>
#include<unistd.h>
#include<ncurses.h>
using namespace std;

bool gameOver;

const int width = 20;
const int height = 20;

int x,y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int nTail;

string fruit = "*";

enum eDirections
{
    STOP=0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

eDirections dir;

void setup(){
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX = rand()%width +1;
    fruitY = rand()%height +1;
    score=0;
}

void draw(){
    system("clear");
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<=height;i++){
        for(int j=0;j<=width+1;j++){
            if(j==1 || j==width+1){
                cout<<"#";
            }
            if(i==y && j==x){
                cout<<"0";
            }else if(j==fruitX && i==fruitY){
                cout<<fruit;
            }else{
                bool print = false;
                for(int k=0;k<nTail;k++){
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print){
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++){
        cout<<"#";
    }   
    cout<<endl;
    cout<<"Score"<<score<<endl;
}

void logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=0;i<nTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }
    if((x>width || x<0) || (y>height || y<0)){
        cout<<"Game Over"<<endl;
        cout<<"You hit the wall";
        gameOver=true;
    }
    for(int i=0;i<nTail;i++){
        if(tailX[i]==x && tailY[i]==y){
        cout<<"Game Over"<<endl;
        cout<<"You hit the tail";
        gameOver=true;
        }
    }
    if(x==fruitX && y==fruitY){
        score+=10;
        nTail++;
        fruitX=rand()%width+1;
        fruitY=rand()%height+1;
    }
}

void input(){
    if(!(getch()==ERR)){
       switch(getch()){
        case'a':
            dir=LEFT;
            break;
        case'd':
            dir=RIGHT;
            break;
        case'w':
            dir=UP;
            break;
        case's':
            dir=DOWN;
            break;
        case'x':
            gameOver=true;
            break;
       } 
    }
}


int main(){
    setup();
    while(!gameOver){
        draw();
        input();
        logic();
        sleep(150);
    }
    cout<<fruitX<<" "<<fruitY;
    return 0;
}


