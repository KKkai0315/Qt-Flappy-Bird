#ifndef SCENE_H
#define SCENE_H

#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <birditem.h>
#include "pipeitem.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void birddef();

signals:

private:
    void setpipetimer();
    QTimer* pipetimer;
    birditem* bird;

public slots:

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
