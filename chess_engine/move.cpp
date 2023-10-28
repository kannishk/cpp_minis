#include<iostream>
#include "move.h"

namespace Chess{
    Move::Move(ssize_t _from, ssize_t _to){
        from = _from;
        to = _to;
    }

    Move::Move(){}

    void undo_move(Board& b, Boardhistory& ml){
        if(!ml.size()){
            return;
        }
        if(ml.back().where == move_done){
            ml.pop_back();
        }

        while(ml.size() && ml.back().where != move_done){
            b.set(ml.back().where, ml.bakc().old_square);
            ml.pop_back();
        }
    }

    static void do_change(Board& b, Boardhistory& bh, size_t where, Square new_square){
        BoardChange change;
        change.old_square = b.get(where);
        change.where = where;
        bh.push_back(change);
        b.set(where, new_square);
    }

    void do_move(Move m, Board& b, Boardhistory& bh, Piece pawn_promotion){
        
    }
}

