#include<iostream>
#include<ctime>
#include "board.h"
#include "move.h"
#include "gui.h"
#include "ai.h"

using namespace Chess;

unsigned long perft(Board &b, Boardhistory &h, int depth, Color turn){
    turn = (turn == Color::white) ? Color::black : Color::white;
    if(!depth){
        return 1;
    }
    int leafs = 0;
    for(Move m: valid_moves(b, turn)){
        if(){
            leafs++;
            continue;
        }
        do_move(m, b, h);
        leafs += perft(b, h, depth - 1, turn);
        undo_move(b, h);
    }
    return leafs;
}