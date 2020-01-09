#ifndef FIELD_H
#define FIELD_H
#include "Figure.h"
#include <vector>

class Field
{
private:
    int width;
    int height;
    int blockedX;
    int blockedY;
public:
    std::vector<std::vector<Figure*> > matrix;

    bool side_move;

    Figure Null_class;

    Figure BLack_King;
    Figure Black_Rook1;
    Figure Black_Rook2;
    Figure Black_Knight1;
    Figure Black_Knight2;
    Figure Black_Horse1;
    Figure Black_Horse2;

    Figure White_King;
    Figure White_Rook1;
    Figure White_Rook2;
    Figure White_Knight1;
    Figure White_Knight2;
    Figure White_Horse1;
    Figure White_Horse2;

    Field(int startWidth, int startHeight, int startBlockedX, int startBlockedY);

    bool not_blockedXY(int to_x, int to_y);
    bool enemy_side(int to_x, int to_y, int x_pos, int y_pos);
};

#endif // FIELD_H
