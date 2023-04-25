#ifndef SCENE_H
#define SCENE_H

#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <birditem.h>
#include "pipeitem.h"
#include "ground.h"
#include <QGraphicsPixmapItem>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void birddef();
    void mainstart();

signals:

private:
    void setpipetimer();
    QTimer* pipetimer;
    birditem* bird;
    QGraphicsPixmapItem* startImage;
    bool startsign;
    void gameover();
    groundItem* ground;

public slots:

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
