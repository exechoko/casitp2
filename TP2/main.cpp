#include <QApplication>
#include <game.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game *g = new game (nullptr);
    g->show();

    return a.exec();
}
