#include <bits/stdc++.h>
#include "Field.h"
#include "Figure.h"
#include "ChessGame.h"
#define Horse 0
#define Elephant 1
#define Rook 2
#define King 3

Field::Field(int startWidth, int startHeight, int startBlockedX, int startBlockedY):
    width(startWidth), height(startHeight), blockedX(startBlockedX), blockedY(startBlockedY)
{
    Figure BLack_King(2, 0, false, 3);
    Figure Black_Rook1(2, 2, false, 2);
    Figure BLack_Rook2(2, 3, false, 2);
    Figure BLack_Knight1(1, 1, false, 1);
    Figure BLack_Knight2(3, 1, false, 1);
    Figure BLack_Horse1(1, 2, false, 0);
    Figure BLack_Horse2(3, 2, false, 0);

    Figure White_King(2, 12, true, 3);
    Figure White_Rook1(2, 9, true, 2);
    Figure White_Rook2(2, 10, true, 2);
    Figure White_Knight1(1, 11, true, 1);
    Figure White_Knight2(3, 11, true, 1);
    Figure White_Horse1(1, 10, true, 0);
    Figure White_Horse2(3, 10, true, 0);
}
int Field::get_width()
{
    return width;
}
int Field::get_height()
{
    return height;
}
int Field::get_blockedX()
{
    return blockedX;
}
int Field::get_blockedY()
{
    return blockedY;
}
int Field::get_type()
{
    return type;
}
int Field::checkX()
{
    return x;
}
int Field::checkY()
{
    return y;
}
bool Field::updateCheck()
{
    for (int i = 0; i < (int)Figures.size() - 1; i++) {
        int CoordinateKingX, CoordinateKingY;
        if (i == King)
        {
            CoordinateKingX = checkX();
            CoordinateKingY = checkY();
            return false;
        }
        if (i == Horse)
        {
            if (abs(CoordinateKingX - x) == 1 && abs(CoordinateKingY - y) == 2)
            {
                return true;
            }
            else if (abs(CoordinateKingX - x) == 2 && abs(CoordinateKingY - y) == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (i == Elephant)
        {
            if (abs(CoordinateKingX - x) == abs(CoordinateKingY - y))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (i == Rook)
        {
            if (x == CoordinateKingX || y == CoordinateKingY)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
   }
}
bool Field::updateMate()
{
    Field temp_field = *this;
    updateCheck();
    if (updateCheck())
    {
        for(int i = 0; i < (int)Figures.size(); i++) {
            for (int j = 0; j < (int)Figures.size(); j++)
            {

                Figures[i][j]->moving(x, y, temp_field);
                updateCheck();
                if(updateCheck())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }
}
