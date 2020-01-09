#include "ChessGame.h"

ChessGame::ChessGame(int startWidth, int startHeight, int startBlockedX, int startBlockedY) :
                    field(startWidth, startHeight, startBlockedX, startBlockedY), Side_Movement(true)
    { }

bool ChessGame::step(int x_pos, int y_pos, int to_x, int to_y){
    if(field.side_move != field.matrix[x_pos][y_pos]->get_side()){
        return false;
    }
    else
        return field.matrix[x_pos][y_pos]->moving(to_x, to_y, field);
}


