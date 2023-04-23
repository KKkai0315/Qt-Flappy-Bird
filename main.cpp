#include "widget.h"
#include <time.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    srand((unsigned)time(NULL));
    w.show();
    return a.exec();
}
