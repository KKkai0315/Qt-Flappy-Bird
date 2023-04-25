#include "pipeitem.h"
#include <birditem.h>
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

void PipeItem::pipestop()
{
    xani->stop();
}

void PipeItem::setX(qreal x)
{
    m_x = x;
    if(collision()){
        emit collidesignal();
    }
    setPos(x,ramy);
}

bool PipeItem::collision()
{
    QList<QGraphicsItem*> collidingItems = apipe->collidingItems();
      foreach (QGraphicsItem * item , collidingItems){
          birditem * birdie = dynamic_cast<birditem*>(item);
          if(birdie){
              return true;
          }
      }
      return false;
}
