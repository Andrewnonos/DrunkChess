
#include <bits/stdc++.h>
#include "Field.h"
#include "Figure.h"
#include "ChessGame.h"
bool ChessGame::step(int from_x, int from_y, int to_x, int to_y, Field &field)
{
    from_x = to_x;
    from_y = to_y;
    if ((to_x == field.get_blockedX() && to_y == field.get_blockedY()) || to_x > field.get_width() || to_y > field.get_height())
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool ChessGame::isEqual(int x1, int x2, int y1, int y2)
{
    if (x1 == x2 && y1 == y2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


