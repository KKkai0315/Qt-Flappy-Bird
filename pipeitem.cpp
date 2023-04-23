#include "pipeitem.h"
#include <QPointF>

PipeItem::PipeItem() :
    apipe(new QGraphicsPixmapItem(QPixmap(":/new/prefix1/pipe.png")))
{
    apipe->setPos(QPointF(0,0) - QPointF(apipe->boundingRect().width(),apipe->boundingRect().height()-260));
    addToGroup(apipe);
}
