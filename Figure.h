#ifndef FIGURE_H
#define FIGURE_H
#include <bits/stdc++.h>
#include "Field.h"
#include "Figure.h"
#include "ChessGame.h"

class Figure
{
private:
    int x_pos;
    int y_pos;
    bool side;
    int type;
public:
    Figure(int x, int y, bool startSide, int startType);
    bool moving(int to_x, int to_y, Field &field);
    int mutate(int type);
};

#endif // FIGURE_H
