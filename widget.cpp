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

    scene = new Scene(this);

    scene->setSceneRect(0,0,432,644);

    QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/bg.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) );
    birditem* bird = new birditem(QPixmap(":/new/prefix1/0.png"));
    scene->addItem(bird);
    groundItem* ground = new groundItem;
       scene->addItem(ground);
          ground->setZValue(10); // 设置Z值为10，放在最上面

    ui->Box->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}

