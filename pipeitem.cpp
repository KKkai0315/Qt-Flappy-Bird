#include "pipeitem.h"
#include <QPointF>
#include <time.h>
PipeItem::PipeItem() :
    apipe(new QGraphicsPixmapItem(QPixmap(":/new/prefix1/pipe.png")))
{
    ramy=-(200+rand()%(480-200+1));
    apipe->setPos(500,ramy);
    xani = new QPropertyAnimation(this,"x",this);
    xani->setStartValue(480);
    xani->setEndValue(-200);
    xani->setEasingCurve(QEasingCurve::Linear);
    xani->setDuration(3000);
    connect(xani, &QPropertyAnimation::finished, [=](){
        scene()->removeItem(this);
        delete this;
    });
    xani->start();
    addToGroup(apipe);
}

PipeItem::~PipeItem()
{
}

qreal PipeItem::x() const
{
    return m_x;
}

void PipeItem::setX(qreal x)
{
    m_x = x;
    setPos(x,ramy);
}
