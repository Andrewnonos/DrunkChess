#include "Figure.h"
#include <math.h>

#define T_NULL -1
#define T_KING 0
#define T_HORSE 1
#define T_KNIGHT 2
#define T_ROOK 3

#include "Figure.h"
#include "Field.h"

Figure::Figure(int x, int y, bool startSide, int startType): x_pos(x), y_pos(y), side(startSide), type(startType)
    { }

bool Figure::get_side(){
    return side;
}

int Figure::get_type(){
    return type;
}

bool Figure::moving(int to_x, int to_y, Field &field)
{
    bool obstacle;
    switch(type){
    case T_KING:
        if(field.not_blockedXY(to_x, to_y) && field.enemy_side(to_x, to_y, x_pos, y_pos)){
            if(to_x <= x_pos+1 && to_x >= x_pos-1 && to_y >= y_pos-1 && to_y <= y_pos+1){
                if(to_x == x_pos && to_y == y_pos){
                    obstacle = false;
                }
                else{
                    obstacle = true;
                }
            }
        }
        else{
            obstacle = false;
        }
        break;


    case T_HORSE:
        if(field.not_blockedXY(to_x, to_y) && field.enemy_side(to_x, to_y, x_pos, y_pos)){
            if((abs(to_x-x_pos) == 1 && abs(to_y-y_pos) == 2) || (abs(to_x-x_pos) == 2 && abs(to_y-y_pos) == 1)){
                obstacle = true;
            }
            else{
                obstacle = false;
            }
        }
        else{
            obstacle = false;
        }
        break;


    case T_KNIGHT:
        if(field.not_blockedXY(to_x, to_y) && field.enemy_side(to_x, to_y, x_pos, y_pos)){
            if(abs(to_x - x_pos) == abs(to_y - y_pos)){
                obstacle = true;
                if(to_x < x_pos && to_y < y_pos){
                    for(int i = 1; i < abs(to_x-x_pos); i++){
                        if(field.matrix[x_pos-i][y_pos-i] != &field.Null_class || !field.not_blockedXY(x_pos-1, y_pos-i))
                            obstacle = false;
                    }
                }
                else{
                    if(to_x < x_pos && to_y > y_pos){
                        for(int i = 1; i < abs(to_x-x_pos); i++){
                            if(field.matrix[x_pos-i][y_pos+i] != &field.Null_class || !field.not_blockedXY(x_pos-1, y_pos+i))
                                obstacle = false;
                        }
                    }
                    else{
                        if(to_x > x_pos && to_y < y_pos){
                            for(int i = 1; i < abs(to_x-x_pos); i++){
                                if(field.matrix[x_pos+i][y_pos-i] != &field.Null_class || !field.not_blockedXY(x_pos+1, y_pos-i))
                                    obstacle = false;
                            }
                        }
                        else{
                            if(to_x > x_pos && to_y > y_pos){
                                for(int i = 1; i < abs(to_x-x_pos); i++){
                                    if(field.matrix[x_pos+i][y_pos+i] != &field.Null_class || !field.not_blockedXY(x_pos+1, y_pos+i))
                                        obstacle = false;
                                }
                            }
                            else{
                                obstacle = false;
                            }
                        }
                    }

                }
            }
            else{
                obstacle = false;
            }
        }
        else{
            obstacle = false;
        }
        break;


    case T_ROOK:
        if(field.not_blockedXY(to_x, to_y) && field.enemy_side(to_x, to_y, x_pos, y_pos)){
            if((x_pos == to_x && y_pos != to_y) || (x_pos != to_x && y_pos == to_y)){
                obstacle = true;
                if(y_pos != to_y){
                    if(y_pos > to_y){
                        for(int i = y_pos-1; i > to_y; i--){
                            if(field.matrix[x_pos][i] != &field.Null_class || !field.not_blockedXY(x_pos, i))
                                obstacle = false;
                        }
                    }
                    else{
                        if(y_pos < to_y){
                            for(int i = to_y-1; i > y_pos; i--){
                                if(field.matrix[x_pos][i] != &field.Null_class || !field.not_blockedXY(x_pos, i))
                                    obstacle = false;
                            }
                        }
                        else{
                            obstacle = false;
                        }
                    }
                }
                else{
                    if(x_pos > to_x){
                        for(int i = x_pos-1; i > to_y; i--){
                            if(field.matrix[i][y_pos] != &field.Null_class || !field.not_blockedXY(i, y_pos))
                                obstacle = false;
                        }
                    }
                    else{
                        if(x_pos < to_x){
                            for(int i = to_x-1; i > x_pos; i--){
                                if(field.matrix[i][y_pos] != &field.Null_class || !field.not_blockedXY(i, y_pos))
                                    obstacle = false;
                            }
                        }
                        else{
                            obstacle = false;
                        }
                    }
                }
            }
        }
        else{
            obstacle = false;
        }
        break;

    case T_NULL:
        obstacle = false;
        break;
    }


    if(obstacle){
        x_pos = to_x;
        y_pos = to_y;
        mutate(field.side_move);
    }

    return obstacle;
}

void Figure::mutate(bool &side_move)
{
    side_move = !side_move;
    if(type > T_KING)
        type++;
    if(type > T_ROOK)
        type = T_HORSE;
}
