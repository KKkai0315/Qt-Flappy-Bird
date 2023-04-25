#include "scene.h"
#include <QKeyEvent>
#include <birditem.h>
#include "ground.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent),startsign(0),gameoverbool(0),score(0)
{
    setpipetimer();
    startImage = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/start.png"));
    addItem(startImage);
    startImage->setPos(0,0);
    startImage->setZValue(100);

    gameoverImage = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/gameover.png"));



    ground = new groundItem;
       addItem(ground);
          ground->setZValue(10); // 设置Z值为10，放在最上面
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

void Scene::Scoreadd()
{
    score++;
}

void Scene::setpipetimer()
{
 pipetimer = new QTimer(this);
 connect(pipetimer,&QTimer::timeout,[=](){
     PipeItem* pipe = new PipeItem;
     connect(pipe,&PipeItem::collidesignal,[=](){
         pipetimer->stop();
         gameover();
     });
     connect(bird,&birditem::collidesignal2,[=](){
         gameover();
     });
     addItem(pipe);
 });
}

void Scene::gameover()
{
    gameoverbool=1;
    bird->birdstop();
    ground->groundstop();
    showscore();
    addItem(gameoverImage);
    gameoverImage->setPos(0,0);
    gameoverImage->setZValue(100);
    QList<QGraphicsItem*> sceneItems = items();
        for(int i=0; i<sceneItems.size(); i++){
            PipeItem * pipe = qgraphicsitem_cast<PipeItem*>(sceneItems[i]);
            if(pipe){
                pipe->pipestop();
            }
        }
        pipetimer->stop();
}

void Scene::showscore()
{
    scoretext = new QGraphicsTextItem();
    QString lastscore="Your Score:" + QString::number(score);
    scoretext->setHtml(lastscore);
    QFont font("Consolas",20,QFont::Bold);
    scoretext->setFont(font);
    QColor color(126,12,110);
    scoretext->setDefaultTextColor(color);
    addItem(scoretext);
    scoretext->setPos(35 ,280);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(startsign==0)
        mainstart();
    if(!gameoverbool){
if(event->key()==Qt::Key_Space){
    bird->jump();
}
    }
QGraphicsScene::keyPressEvent(event);
}
