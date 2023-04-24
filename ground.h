#ifndef GROUND_H
#define GROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>

class groundItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal groundx READ groundx WRITE setgroundx)
    qreal m_groundx;

public:
explicit groundItem(QObject *parent = nullptr);
qreal groundx() const;
public slots:
void setgroundx(qreal groundx);
};

#endif // GROUND_H
