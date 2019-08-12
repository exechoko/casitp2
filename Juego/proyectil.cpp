#include "proyectil.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemigos.h"
#include "game.h"


extern game * g;

proyectil::proyectil(QGraphicsItem * parent) : QObject (), QGraphicsRectItem (parent)
{
    // dibujamos el proyectil
    setRect(0, 0, 2, 20);

    // conectamos
    QTimer *tiempo = new QTimer();
    connect(tiempo, SIGNAL(timeout()), this, SLOT(move()));
    tiempo->start(50);
}

void proyectil::move()
{
    QTimer * tiempo = new QTimer(this);

    // si el proyectil se la pega al enemigo, destruirlo
    QList < QGraphicsItem*>items_colisionados = collidingItems();
    for (int i = 0, n = items_colisionados.size(); i < n; i++) {
        if (typeid (*(items_colisionados[i])) == typeid (enemigos)){

            //incrementar el marcador(score)
            g->marcador->incrementar();

            //remover enemigo
            scene()->removeItem(items_colisionados[i]);
            scene()->removeItem(this);

            //eliminar el enemigo
            delete items_colisionados[i];
            delete this;
            return;
        }

    }

    //mover el proyectil hacia arriba
    setPos(x(), y() - 10);
    // para eliminar el proyectil una vez que se salio de la ventana
    if (pos().y() + rect().height() < 0){
        tiempo->stop();
        scene()->removeItem(this);
        delete this;
        qDebug() << "Proyectil eliminado";
    }
}
