#include "birditem.h"
#include <QTimer>

birditem::birditem(QPixmap pixmap, QObject *parent) : QObject(parent),
  wingdirect(0)
{
    setPixmap(pixmap);
    QTimer* wingtimer = new QTimer(this);
    connect(wingtimer,&QTimer::timeout,[=](){wings();});
    wingtimer->start(100);
}

void birditem::wings()
{
    if(wingpos==0)
    {
        setPixmap(QPixmap(":/new/prefix1/1.png"));
        wingpos=1;
        wingdirect=0;
    }
    if(wingpos==1)
    {
        if(wingdirect==0)
        {
            setPixmap(QPixmap(":/new/prefix1/2.png"));
            wingpos=2;
        }
        else
        {
            setPixmap(QPixmap(":/new/prefix1/0.png"));
            wingpos=0;
        }
    }
    if(wingpos==2)
    {
        setPixmap(QPixmap(":/new/prefix1/1.png"));
        wingpos=1;
        wingdirect=1;
    }
}

