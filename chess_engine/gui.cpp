#include<iostream>
#include<cctype>
#include<map>
#include "gui.h"

namespace Chess{
    using namespace std;

    static const std::map<Piece, char> sprites = { 
        { Piece::pawn,      'A' },
        { Piece::pawn_en_passant,   'P' },
        { Piece::rook,      'H' },
        { Piece::rook_castle,   'H' },
        { Piece::knight,        'F' },
        { Piece::bishop,        'I' },
        { Piece::king,      'K' },
        { Piece::king_castle,   'K' },
        { Piece::none,      '+' },
        { Piece::out_of_board,      '#' },
        { Piece::queen,         'Q' }
    };

    void print_board(const Board& b, Move last_game){
        cout << "\n   1 2 3 4 5 6 7 8";
        for (ssize_t i = 20; i < (ssize_t)board_size; i++){
            if(i%10==9){
                continue;
            }
            if(i/10==10){
                break;
            }
            if(i%10==0){
                cout << "\n " << i / 10 << " ";
                continue;
            }
            char s = sprites.at()
        }
    }
}

