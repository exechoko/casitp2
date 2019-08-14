#include "enemigo.h"
#include <QDebug>


enemigo::enemigo(QGraphicsItem *parent): QGraphicsRectItem (parent)
{
    // set posicion aleatoria del enemigo
    int numero_aleatorio = rand() % 700;
    setPos(numero_aleatorio,0);
    setRect(0,0,25,25);
    setPen(QPen(Qt::red, 3, Qt::SolidLine));
    setBrush(QBrush(Qt::black));

    //el enemigo sabe moverse
    QTimer *tiempo = new QTimer ();
    connect(tiempo,SIGNAL(timeout()),this,SLOT(mover()));
    tiempo->start(50);

}

void enemigo::mover()
{
    //mover al enemigo
    int aleaX = rand()%2;
    int aleaY = rand()%2;
    setPos(x() + aleaX, y() + aleaY);

    if (pos().x() > 800 || pos().y() > 600){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemigo eliminado";// es lo mismo que el cout
    }
}

void enemigo::generar()
{
    enemigo * enem = new enemigo ();
    scene()->addItem(enem);
}

