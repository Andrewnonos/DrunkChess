#ifndef FIELD_H
#define FIELD_H
#include <bits/stdc++.h>
#include "Field.h"
#include "Figure.h"
#include "ChessGame.h"

class Field
{
private:
    int width;
    int height;
    int blockedX;
    int blockedY;
    std::vector<std::vector<Figure*> > Figures;
    int type;
    int x;
    int y;
public:
    Field(int startWidth, int startHeight, int startBlockedX, int startBlockedY);
    int get_width();
    int get_height();
    int get_type();
    int get_blockedX();
    int get_blockedY();
    int checkX();
    int checkY();
    bool updateCheck();
    bool updateMate();
};

#endif // FIELD_H
