#ifndef GROUND_H
#define GROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include "birditem.h"

class groundItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal groundx READ groundx WRITE setgroundx)
    qreal m_groundx;

public:
explicit groundItem(QObject *parent = nullptr);
qreal groundx() const;
//地面当前位置
QPropertyAnimation* groundani;
//让地面从右往左进行移动

public slots:
void setgroundx(qreal groundx);
void groundstop();

signals:
};

#endif // GROUND_H
