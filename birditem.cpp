#include "birditem.h"
#include "ground.h"
#include <QTimer>
#include <QGraphicsScene>

birditem::birditem(QPixmap pixmap, QObject *parent) : QObject(parent),
  wingdirect(0),wingpos(0),m_y(0)
{
    setPixmap(pixmap);

    //设置定时器 让鸟翅膀扇动
    QTimer* wingtimer = new QTimer(this);
    connect(wingtimer,&QTimer::timeout,[=](){wings();});
    wingtimer->start(100);

    //计算地面位置
    groundline=scenePos().y()+450;

    //设置鸟的坠落
    yani = new QPropertyAnimation(this,"y",this);
    yani->setStartValue(scenePos().y());
    yani->setEndValue(groundline);
    yani->setEasingCurve(QEasingCurve::InQuad);
    yani->setDuration(1000);

    //设置坠落时的体态——嘴朝地
    rotationani = new QPropertyAnimation(this,"rotation",this);
    rotationani->setStartValue(rotation());
    rotationani->setEndValue(90);
    rotationani->setEasingCurve(QEasingCurve::InQuad);
    rotationani->setDuration(1200);


}

//扇动翅膀函数
void birditem::wings()
{
    if(wingpos==0)
    {
        setPixmap(QPixmap(":/new/prefix1/1.png"));
        wingpos=1;
        wingdirect=0;
    }
    if(wingpos==1)
    {
        if(wingdirect==0)
        {
            setPixmap(QPixmap(":/new/prefix1/2.png"));
            wingpos=2;
        }
        else
        {
            setPixmap(QPixmap(":/new/prefix1/0.png"));
            wingpos=0;
        }
    }
    if(wingpos==2)
    {
        setPixmap(QPixmap(":/new/prefix1/1.png"));
        wingpos=1;
        wingdirect=1;
    }
}


qreal birditem::y() const
{
    return m_y;
}

qreal birditem::rotation() const
{
    return m_rotation;
}

void birditem::jump()
{
    yani->stop();
    rotationani->stop();

    //让鸟跳跃完成后自然下坠
    connect(yani,&QPropertyAnimation::finished,[=]{falling();});

    //设置鸟的跳跃动画
    yani->setStartValue(y());
    yani->setEndValue(y() - 80);
    yani->setEasingCurve(QEasingCurve::OutQuad);
    yani->setDuration(255);
    yani->start();

    //设置鸟的跳跃旋转动画
    rotationani->setStartValue(rotation());
    rotationani->setEndValue(-20);
    rotationani->setEasingCurve(QEasingCurve::InOutQuad);
    rotationani->setDuration(200);
    rotationani->start();
}

void birditem::birdstart()
{
    yani->start();
    rotationani->start();
}

void birditem::birdstop()
{
    yani->stop();
    rotationani->stop();
}

//碰撞检测函数
bool birditem::collision()
{
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
      foreach (QGraphicsItem * item , collidingItems){
          groundItem * groundtemp = dynamic_cast<groundItem*>(item);
          if(groundtemp){
              return true;
          }
      }
      return false;

}



void birditem::sety(qreal y)
{
    setPos(this->pos().x(),y);

    //若碰撞地板 则发出碰撞信号
    if(collision()){
        emit collidesignal2();
    }

    m_y = y;
}

//将旋转中心放置鸟图元中心
void birditem::setRotation(qreal rotation)
{
    m_rotation = rotation;
    QPointF temp = boundingRect().center();
    setTransformOriginPoint(temp);
    QGraphicsItem::setRotation(rotation);
}

//鸟的自然下坠
void birditem::falling()
{
    if(y()<(this->scenePos().y()+450))
    {
    rotationani->stop();

    yani->setStartValue(y());
    yani->setEndValue(groundline);
    yani->setEasingCurve(QEasingCurve::InQuad);
    yani->setDuration(1100);
    yani->start();

    rotationani->setStartValue(rotation());
    rotationani->setEndValue(90);
    rotationani->setEasingCurve(QEasingCurve::InQuad);
    rotationani->setDuration(1000);
    rotationani->start();
    }
}
