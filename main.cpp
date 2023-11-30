#include "bomberman_windows.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BomberMan_Windows w;
    w.show();
    return a.exec();
}
