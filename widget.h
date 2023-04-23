#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Scene* scene;

};
#endif // WIDGET_H
