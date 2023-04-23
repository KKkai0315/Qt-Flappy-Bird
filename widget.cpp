#include "widget.h"
#include "ui_widget.h"
#include "pipeitem.h"
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

    PipeItem* pipe = new PipeItem;
    scene->addItem(pipe);

    ui->Box->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}

