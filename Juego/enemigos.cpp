#include "enemigos.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //para usar el random
#include <game.h>

extern game *g;

enemigos::enemigos(QGraphicsItem *parent): QObject (), QGraphicsRectItem (parent)
{
    // set posicion aleatoria del enemigo
    int numero_aleatorio = rand() % 700;
    setPos(numero_aleatorio,0);

    // dibujamos el enemigo
    setRect(0, 0, 50, 50);

    // conectamos
    QTimer *tiempo = new QTimer();
    connect(tiempo, SIGNAL(timeout()), this, SLOT(move()));

    tiempo->start(50);
}

void enemigos::move()
{
    //mover el enemigo hacia abajo
    setPos(x(), y() +10);

    //destruir el enemigo cuando llegue al final de la pantalla
    if (pos().y() > 600){
        //disminuir las vidas
        g->V->reducir();

        scene()->removeItem(this);
        delete this;
    }
}
