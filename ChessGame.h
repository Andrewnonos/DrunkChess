#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <bits/stdc++.h>
#include "Field.h"
#include "Figure.h"
#include "ChessGame.h"

class Field;

class ChessGame
{
private:
    bool check;
    bool mate;
    Field* field;
    int winner;
public:
    bool step(int from_x, int from_y, int to_x, int to_y, Field &field);
    bool isEqual(int x1, int x2, int y1, int y2);
};

#endif // CHESSGAME_H
