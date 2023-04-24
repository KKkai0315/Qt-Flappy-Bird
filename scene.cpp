#include "scene.h"
#include <QKeyEvent>
#include <birditem.h>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setpipetimer();


}

void Scene::birddef()
{
    bird = new birditem(QPixmap(":/new/prefix1/0.png"));
    addItem(bird);
    bird->setZValue(20);
}

void Scene::setpipetimer()
{
 pipetimer = new QTimer(this);
 connect(pipetimer,&QTimer::timeout,[=](){
     PipeItem* pipe = new PipeItem;
     addItem(pipe);
 });
 pipetimer->start(2000);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
if(event->key()==Qt::Key_Space){
    bird->jump();
}
QGraphicsScene::keyPressEvent(event);
}
