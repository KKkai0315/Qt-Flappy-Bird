#include "pipeitem.h"

PipeItem::PipeItem() :
    apipe(new QGraphicsPixmapItem(QPixmap(":/new/prefix1/pipe.png")))
{
    addToGroup(apipe);
}
