#ifndef GROUND_H
#define GROUND_H

#include <QObject>

class ground : public QObject
{
    Q_OBJECT
public:
    explicit ground(QObject *parent = nullptr);
    qreal groundpos;

signals:

};

#endif // GROUND_H
