#include "Field.h"

#define R_Horse 0
#define R_Elephant 1
#define R_Rook 2
#define R_King 3

Field::Field(int startWidth, int startHeight, int startBlockedX, int startBlockedY):
    width(startWidth), height(startHeight), blockedX(startBlockedX), blockedY(startBlockedY),

    Null_class(0, 0, false, -1),

    side_move(true),

    BLack_King(2, 12, false, 0),
    Black_Rook1(2, 9, false, 3),
    Black_Rook2(2, 10, false, 3),
    Black_Knight1(1, 11, false, 2),
    Black_Knight2(3, 11, false, 2),
    Black_Horse1(1, 10, false, 1),
    Black_Horse2(3, 10, false, 1),

    White_King(2, 0, true, 0),
    White_Rook1(2, 2, true, 3),
    White_Rook2(2, 3, true, 3),
    White_Knight1(1, 1, true, 2),
    White_Knight2(3, 1, true, 2),
    White_Horse1(1, 2, true, 1),
    White_Horse2(3, 2, true, 1)

{

    std::vector<Figure*> temp_matrx(height);

    for(int i = 0; i < height; i++){
        temp_matrx[i] = &Null_class;
    }

    for(int i = 0; i < width; i++){
        matrix.push_back(temp_matrx);
    }


    matrix[2][12] = &BLack_King;
    matrix[2][9] = &Black_Rook1;
    matrix[2][10] = &Black_Rook2;
    matrix[1][11] = &Black_Knight1;
    matrix[3][11] = &Black_Knight2;
    matrix[1][10] = &Black_Horse1;
    matrix[3][10] = &Black_Horse2;

    matrix[2][0] = &White_King;
    matrix[2][2] = &White_Rook1;
    matrix[2][3] = &White_Rook2;
    matrix[1][1] = &White_Knight1;
    matrix[3][1] = &White_Knight2;
    matrix[1][2] = &White_Horse1;
    matrix[3][2] = &White_Horse2;
}

bool Field::not_blockedXY(int to_x, int to_y){
    if(to_x == blockedX && to_y == blockedY)
        return false;
    else
        return true;
}
bool Field::enemy_side(int to_x, int to_y, int x_pos, int y_pos){
    if(matrix[to_x][to_y] != &Null_class)
        if(matrix[to_x][to_y]->get_side() != matrix[x_pos][y_pos]->get_side())
            return true;
        else
            return false;
    else
        return true;
}
