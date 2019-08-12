#include "jugador.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "proyectil.h"
#include "enemigos.h"
#include <QDebug>

jugador::jugador(QGraphicsItem *parent): QGraphicsRectItem (parent)
{

}

void jugador::keyPressEvent(QKeyEvent *evento)
{
    //qDebug() << "Mi rectangulo sabe que tecla presiono";
    if (evento->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    } else if (evento->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    } else if (evento->key() == Qt::Key_Up) {
        setPos(x(), y() - 10);
    } else if (evento->key() == Qt::Key_Down) {
        setPos(x(), y() + 10);
    } else if (evento->key() == Qt::Key_Space) {
        //creamos una bala
        proyectil *bala = new proyectil();
        //qDebug() << "Proyectil creado";
        bala->setPos(x(), y());
        scene()->addItem(bala);
    }
}

void jugador::generar()
{
    //Crear un enemigo
    enemigos * enem = new enemigos ();
    scene()->addItem(enem);

}
