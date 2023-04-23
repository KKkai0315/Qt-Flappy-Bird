#include "scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    setpipetimer();
}

void Scene::setpipetimer()
{
 pipetimer = new QTimer(this);
 connect(pipetimer,&QTimer::timeout,[=](){
     PipeItem* pipe = new PipeItem;
     addItem(pipe);
 });
 pipetimer->start(1000);
}
