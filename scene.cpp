#include "scene.h"
#include <QKeyEvent>
#include <birditem.h>
#include "ground.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent),startsign(0),gameoverbool(0),score(0)
{
    setpipetimer();
    //水管定时器 用于定时间间隔生成新水管
    startImage = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/start.png"));
    addItem(startImage);
    startImage->setPos(0,0);
    startImage->setZValue(100);//放在最顶层

    gameoverImage = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/gameover.png"));
    nankaiImage = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/nankai.png"));



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

     //如果小鸟与水管碰撞，游戏结束
     connect(pipe,&PipeItem::collidesignal,[=](){
         pipetimer->stop();
         gameover();
     });
     //如果小鸟与地板碰撞，游戏结束
     connect(bird,&birditem::collidesignal2,[=](){
         gameover();
     });
     addItem(pipe);
 });
}

void Scene::gameover()
{
    gameoverbool=1; //已结束游戏
    bird->birdstop();   //鸟停止运动
    ground->groundstop();   //地板停止运动
    showscore();

    addItem(gameoverImage);
    gameoverImage->setPos(0,0);
    gameoverImage->setZValue(100);
    addItem(nankaiImage);
    nankaiImage->setPos(138,400);
    nankaiImage->setZValue(100);
    //显示游戏结束和校徽画面

    //将画面内所有水管都停止运动
    QList<QGraphicsItem*> sceneItems = items();
        for(int i=0; i<sceneItems.size(); i++){
            PipeItem * pipe = qgraphicsitem_cast<PipeItem*>(sceneItems[i]);
            if(pipe){
                pipe->pipestop();
            }
        }
        pipetimer->stop();
        //停止水管计时器 不再生成新水管
}

void Scene::showscore()
{
    scoretext = new QGraphicsTextItem();
    QString lastscore="Your Score:" + QString::number(score);
    scoretext->setHtml(lastscore);

    //设置分数显示界面字体和颜色
    QFont font("Consolas",20,QFont::Bold);
    scoretext->setFont(font);
    QColor color(126,12,110);
    scoretext->setDefaultTextColor(color);

    //设置位置
    addItem(scoretext);
    scoretext->setPos(35 ,280);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(startsign==0)
        mainstart();
    //第一次空格将移除开始界面图片，并让小鸟，水管开始运动
    if(!gameoverbool)
    {
if(event->key()==Qt::Key_Space){
    bird->jump();
}
//若游戏已结束 则空格不再有任何作用
    }
QGraphicsScene::keyPressEvent(event);
}
