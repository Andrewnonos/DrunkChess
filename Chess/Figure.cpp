#include <bits/stdc++.h>
#include "Field.h"
#include "Figure.h"
#include "ChessGame.h"
#define Horse 0
#define Elephant 1
#define Rook 2
#define King 3
Figure::Figure(int x, int y, bool startSide, int startType): x_pos(x), y_pos(y), side(startSide), type(startType)
{ }
bool Figure::moving(int to_x, int to_y, Field &field)
{
    x_pos = to_x;
    y_pos = to_y;
    if(x_pos > field.get_width() || y_pos > field.get_height() || (x_pos == field.get_blockedX() && y_pos == field.get_blockedY()))
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Figure::mutate(int type)
{
    type++;
    if (type > Rook)
    {
        type = Horse;
    }
    if (type == Horse)
    {
        type = Elephant;
    }
    if (type == Elephant)
    {
        type = Rook;
    }
    return type;
}

