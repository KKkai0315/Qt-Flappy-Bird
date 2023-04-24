#ifndef BIRDITEM_H
#define BIRDITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class birditem : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit birditem(QPixmap pixmap,QObject *parent = nullptr);
    void wings();
private:
    bool wingdirect;//0 down 1 up
    bool wingpos;//0 up 1 middle 2 down
signals:
};

#endif // BIRDITEM_H
