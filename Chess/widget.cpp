#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include<QIcon>

#define _PATH C:/Users/Andrewnon/Desktop/Sprites

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), layout(this), Game(5, 13, 2, 6), Null_Class1(0, 0, false, -1), temp_text(false)

{
    ui->setupUi(this);


    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            layout.addWidget(&buttons[i][j], i, j, 1, 1);

            redraw();
            buttons[i][j].setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            connect(&buttons[i][j], SIGNAL(clicked()), this, SLOT(process_press()));
        }
    }

    this->setLayout(&layout);
    recycle_temp_text();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::redraw()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 13; j++)
        {

            if(Game.field.matrix[i][j] != &Game.field.Null_class){
                if(Game.field.matrix[i][j]->get_side()){
                    if(Game.field.matrix[i][j]->get_type() == 0){
                        buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/White_King.png")));
                        buttons[i][j].setIconSize(QSize(65, 65));
                    }
                    else{
                        if(Game.field.matrix[i][j]->get_type() == 1){
                            buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/White_Horse.png")));
                            buttons[i][j].setIconSize(QSize(65, 65));
                        }
                        else{
                            if(Game.field.matrix[i][j]->get_type() == 2){
                                buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/White_Knight.png")));
                                buttons[i][j].setIconSize(QSize(65, 65));
                            }
                            else{
                                if(Game.field.matrix[i][j]->get_type() == 3){
                                    buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/White_Rook.png")));
                                    buttons[i][j].setIconSize(QSize(65, 65));
                                }
                            }
                        }
                    }
                }
                else{
                    if(Game.field.matrix[i][j]->get_type() == 0){
                        buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/Black_King.png")));
                        buttons[i][j].setIconSize(QSize(65, 65));
                    }
                    else{
                        if(Game.field.matrix[i][j]->get_type() == 1){
                            buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/Black_Horse.png")));
                            buttons[i][j].setIconSize(QSize(65, 65));
                        }
                        else{
                            if(Game.field.matrix[i][j]->get_type() == 2){
                                buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/Black_Knight.png")));
                                buttons[i][j].setIconSize(QSize(65, 65));
                            }
                            else{
                                if(Game.field.matrix[i][j]->get_type() == 3){
                                    buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/Black_Rook.png")));
                                    buttons[i][j].setIconSize(QSize(65, 65));
                                }
                            }
                        }
                    }
                }
            }
            else{
                if(!Game.field.not_blockedXY(i, j)){
                    buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/BLOCKED.png")));
                    buttons[i][j].setIconSize(QSize(65, 65));
                }
                else{
                    buttons[i][j].setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/SPACE.png")));
                    buttons[i][j].setIconSize(QSize(65, 65));
                }
            }
        }
    }
}

void Widget::recycle_temp_text()
{
    temp_text = !temp_text;
}

void Widget::process_press()
{
    QPushButton * button = (QPushButton *)sender();
    if(temp_text){
        temp_text = !temp_text;
        temp_button = button;
        temp_icon = QIcon(button->icon());
    }
    else{
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 13; j++){
                if(temp_button == &buttons[i][j]){
                    from_x = i;
                    from_y = j;
                }
                else if(button == &buttons[i][j]){
                    to_x = i;
                    to_y = j;
                }
            }
        }
        if(!Game.step(from_x, from_y, to_x, to_y) || Game.field.matrix[from_x][from_y] == &Game.field.Null_class)
        {
            recycle_temp_text();
        }
        else
        {
            Game.field.matrix[to_x][to_y] = Game.field.matrix[from_x][from_y];
            Game.field.matrix[from_x][from_y] = &Game.field.Null_class;
            temp_button->setIcon(QIcon(QPixmap("C:/Users/Andrewnon/Desktop/Sprites/SPACE.png")));
            temp_button->setIconSize(QSize(65, 65));
            button->setIcon(temp_icon);
            button->setIconSize(QSize(65, 65));
            recycle_temp_text();
            redraw();
        }
    }
}
