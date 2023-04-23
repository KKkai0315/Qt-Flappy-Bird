#ifndef PIPEITEM_H
#define PIPEITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>

class PipeItem : public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
public:
    explicit PipeItem();

signals:

private slots:

private:
    QGraphicsPixmapItem* apipe;
};

#endif // PIPEITEM_H
