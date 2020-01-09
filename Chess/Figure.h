#ifndef FIGURE_H
#define FIGURE_H

class Field;
class ChessGame;

class Figure
{
private:
    int x_pos;
    int y_pos;
    bool side;
    Figure *King1;
    Figure *King2;
    int type;

public:
    Figure(int x, int y, bool startSide, int startType);
    bool get_side();
    bool moving(int to_x, int to_y, Field &field);
    void mutate(bool &side_move);
    int get_type();
};

#endif // FIGURE_H
