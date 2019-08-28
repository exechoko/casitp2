#ifndef GAME_H
#define GAME_H

#include <celda.h>
#include <enemigo.h>
#include <personaje.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QWidget>

class game : public QGraphicsView
{
private:
    //game(QWidget *parent = nullptr);
    QGraphicsScene * escena;
    personaje *P;
    enemigo *E;
    celda ***C;
    //celda *casillero;
    //mapa *M;
    QTimer *tiempo_generar;
    QTimer *tiempo;

public:
    game(QWidget *parent = nullptr);
    void inicializar();
    int getValorMatriz(int i, int j);
    bool validar_paso(int band);
    /*
public slots:
    void keyPressEvent(QKeyEvent *movimiento);*/
};

#endif // GAME_H
