#include "pipeitem.h"
#include <QPointF>

PipeItem::PipeItem() :
    apipe(new QGraphicsPixmapItem(QPixmap(":/new/prefix1/pipe.png")))
{
    apipe->setPos(QPointF(0,0)+QPointF(300,-500));
    addToGroup(apipe);
}
