#include "board.h"

namespace Chess{
    Square::Square(Piece p, Color c){
        piece = p;
        piece_color = c;
    }

    Square::Square(){
        piece = Piece::out_of_board;
        piece_color = Color::none;
    }

    void Board::set(const size_t where, Square s){
        if(where >= board_size){
            return;
        }
        squares[where] = s;
    }
    Square Board::get(const size_t where) const{
        if(where>=board_size){
            return Square(Piece::out_of_board, Color::none);
        }
        return squares[where];
    }

    void init_classic_board(Board& b){
        for (size_t i = 0; i < 8; i++){
            b.set(31 + i, Square(Piece::pawn, Color ::black));
            b.set(81 + i, Square(Piece::pawn, Color::white));
        }
        int w = 0;

        for(auto p: {Piece::rook_castle, Piece::knight, Piece::bishop, Piece::queen}){
            b.set(21+w, Square(p,Color::black));
            b.set(28-w, Square(p,Color::black));
            b.set(91+w, Square(p, Color::white));
            b.set(98-w, Square(p, Color::white));
            w++;
        }

        b.set(25, Square(Piece::king_castle, Color::black));
        b.set(95, Square(Piece::king_castle, Color::white));

        for (int x = 0; x < 8;x++){
            for (int y = 0; y < 4;y++){
                b.set(41 + x + y * 10, Square(Piece::none, Color::none));
            }
        }
    }
}
