#include "scene.h"
#include <QKeyEvent>
#include <birditem.h>

Scene::Scene(QObject *parent) : QGraphicsScene(parent),startsign(0)
{
    setpipetimer();
    startImage = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/start.png"));
    addItem(startImage);
    startImage->setPos(0,0);
    startImage->setZValue(100);
}

void Scene::birddef()
{
    bird = new birditem(QPixmap(":/new/prefix1/0.png"));
    addItem(bird);
    bird->setZValue(20);
}

void Scene::mainstart()
{
    startsign=1;
    removeItem(startImage);
        delete startImage;
bird->birdstart();
if(!pipetimer->isActive()){
    pipetimer->start(2000);
}
}

void Scene::setpipetimer()
{
 pipetimer = new QTimer(this);
 connect(pipetimer,&QTimer::timeout,[=](){
     PipeItem* pipe = new PipeItem;
     addItem(pipe);
 });
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(startsign==0)
        mainstart();
if(event->key()==Qt::Key_Space){
    bird->jump();
}
QGraphicsScene::keyPressEvent(event);
}
