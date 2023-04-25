#include "widget.h"
#include "ui_widget.h"
#include "pipeitem.h"
#include "birditem.h"
#include "ground.h"
#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("FlappyBird");

    scene = new Scene(this);

    scene->setSceneRect(0,0,432,644);
    //设置场景矩形大小

    QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/bg.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) );
    //游戏背景载入

    scene->birddef();
    //新建小鸟对象

    ui->Box->setScene(scene);
}
Widget::~Widget()
{
    delete ui;
}

