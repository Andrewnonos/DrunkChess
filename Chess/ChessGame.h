#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Field.h"
#include "Figure.h"

class ChessGame
{
private:

    bool check;
    bool mate;


public:

    Field field;
    bool Side_Movement;

    ChessGame(int startWidth, int startHeight, int startBlockedX, int startBlockedY);
    bool step(int x_pos, int y_pos, int to_x, int to_y);
    bool first_check();

};

#endif // CHESSGAME_H
