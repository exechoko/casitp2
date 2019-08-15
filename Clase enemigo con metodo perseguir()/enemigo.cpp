#include "enemigo.h"
#include <QDebug>
#include <QKeyEvent>


enemigo::enemigo(QGraphicsItem *parent): QGraphicsRectItem (parent)
{
    // set posicion aleatoria del enemigo
    int numero_aleatorio = rand() % 700;
    setPos(numero_aleatorio,0);// aparece en el borde superior y = 0, x = aleatorio
    setRect(0,0,25,25);
    setPen(QPen(Qt::red, 3, Qt::SolidLine)); //borde
    setBrush(QBrush(Qt::black)); //relleno

    //el enemigo sabe moverse
    QTimer *tiempo = new QTimer ();
    connect(tiempo,SIGNAL(timeout()),this,SLOT(mover()));
    tiempo->start(50);


}

void enemigo::perseguir(personaje *pers)
{
    if (pers->pos().x() > pos().x()){
        setPos(x()+2,y());
        qDebug() << "Se movio a la derecha";

    } else if (pers->pos().y() > pos().y()) {
        setPos(x(),y()+2);
        qDebug() << "Se movio hacia abajo";
    } else if (pers->pos().x() < pos().x()) {
        setPos(x()-2,y());
        qDebug() << "Se movio hacia la izquierda";
    } else if (pers->pos().y() < pos().y()) {
        setPos(x(),y()-2);
        qDebug() << "Se movio hacia arriba";
    }

}


void enemigo::mover()
{
    personaje *pers = new personaje ();
    perseguir(pers);


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

