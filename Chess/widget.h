#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QString>

#include "ChessGame.h"
#include "Field.h"
#include "Figure.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QGridLayout layout;
    QPushButton buttons[5][13];

    Field field_main;

    QPushButton * temp_button;
    QString temp_text ="null";

    int from_x;
    int from_y;
    int to_x;
    int to_y;

    void recycle_temp_text();

private:
    Ui::Widget *ui;


public slots:
    void process_press();
};
#endif // WIDGET_H
