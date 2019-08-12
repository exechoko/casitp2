#include <mirectangulo.h>
#include <QApplication>
#include <game.h>

extern game *g = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g = new game();
    g->show();

    return a.exec();
}
