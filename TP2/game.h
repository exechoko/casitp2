#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <personaje.h>
#include <enemigo.h>
#include <QTimer>


class game: public QGraphicsView
{
public:
    game(QWidget *parent = nullptr);
    QGraphicsScene * escena;
    personaje *P;
    enemigo *E;
    QTimer *tiempo_generar;
    //QTimer *tiempo_movi;
};

#endif // GAME_H
