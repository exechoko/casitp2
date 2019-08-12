#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <jugador.h>
#include <score.h>
#include <vidas.h>

class game: public QGraphicsView
{
public:
    game(QWidget * parent = nullptr);

    QGraphicsScene * scene;
    jugador *J;
    score *marcador;
    vidas *V;
};

#endif // GAME_H
