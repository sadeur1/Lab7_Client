#include "Client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client w;
    w.setMaximumHeight(655);
    w.setMaximumWidth(884);
    w.setMinimumHeight(359);
    w.setMinimumWidth(615);
    w.resize(750, 507);
    w.show();
    return a.exec();
}
