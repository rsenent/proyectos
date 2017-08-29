#include "popup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    popup w;
    w.show();

    return a.exec();
}

