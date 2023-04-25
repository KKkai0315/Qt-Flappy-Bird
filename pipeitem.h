#ifndef PIPEITEM_H
#define PIPEITEM_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class PipeItem : public QObject , public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit PipeItem();
        ~PipeItem();

    qreal x() const;

    void pipestop();

public slots:
    void setX(qreal x);

signals:
    void collidesignal();

private slots:

private:
    bool collision();
    QGraphicsPixmapItem* apipe;
    qreal m_x;
    QPropertyAnimation* xani;
    int ramy;
};

#endif // PIPEITEM_H
