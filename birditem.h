#ifndef BIRDITEM_H
#define BIRDITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class birditem : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal y READ y WRITE sety)
public:
    explicit birditem(QPixmap pixmap,QObject *parent = nullptr);
    void wings();

    qreal y() const;

public slots:

    void sety(qreal y);

private:
    bool wingdirect;//0 down 1 up
    int wingpos;//0 up 1 middle 2 down
    qreal m_y;
    QPropertyAnimation* yani;

signals:
};

#endif // BIRDITEM_H
