#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), layout(this), field_main(5, 13, 2, 6)
{
    ui->setupUi(this);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            buttons[i][j].setText(" ");
            buttons[i][j].setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            buttons[i][j].setProperty("text", buttons[i][j].text());
            layout.addWidget(&buttons[i][j], i, j, 1, 1);

           connect(&buttons[i][j], SIGNAL(clicked()), this, SLOT(process_press()));
        }
    }
    buttons[2][0].setText("King");
    buttons[2][12].setText("King");
    buttons[2][2].setText("Rook");
    buttons[2][3].setText("Rook");
    buttons[2][9].setText("Rook");
    buttons[2][10].setText("Rook");
    buttons[1][1].setText("Knight");
    buttons[1][11].setText("Knight");
    buttons[3][1].setText("Knight");
    buttons[3][11].setText("Knight");
    buttons[1][2].setText("Horse");
    buttons[1][10].setText("Horse");
    buttons[3][2].setText("Horse");
    buttons[3][10].setText("Horse");
    buttons[2][6].setText("NULL");


    this->setLayout(&layout);
    recycle_temp_text();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::recycle_temp_text()
{
    temp_text = "null";
}

void Widget::process_press()
{
    QPushButton * button = (QPushButton *)sender();
    if(temp_text == "null"){
        temp_text = button->text();
        temp_button = button;
    }
    else{
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 13; j++){
                if(button == &buttons[i][j]){
                    from_x = i;
                    from_y = j;
                }
                else if(temp_button == &buttons[i][j]){
                    to_x = i;
                    to_y = j;
                }
            }
        if ((to_x == field_main.get_blockedX() && to_y == field_main.get_blockedY())
                || to_x > field_main.get_width() || to_y > field_main.get_height())
        {
            recycle_temp_text();
        }
        else
        {
            field_main.Figures[to_x][to_y] = field_main.Figures[from_x][from_y];
            field_main.Figures[from_x][from_y] = NULL;
            temp_button->setText(" ");
            button->setText(temp_text);
            recycle_temp_text();
        }
    }
}
