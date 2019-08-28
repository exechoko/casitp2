#include "enemigo.h"
#include <QDebug>
#include <QKeyEvent>


enemigo::enemigo(QGraphicsItem *parent): QGraphicsPixmapItem (parent)
{
    QPixmap pix(":/enemigo.png");
    pix = pix.scaled(50,50,Qt::KeepAspectRatio);
    setPixmap(pix);

    // set posicion aleatoria del enemigo
    int numero_aleatorio = rand() % 700;
    setPos(numero_aleatorio, 100); // aparece en el borde superior y = 0, x = aleatorio
    //setRect(0,0,25,25);
    //setPen(QPen(Qt::red, 3, Qt::SolidLine)); //borde
    //setBrush(QBrush(Qt::black)); //relleno

    //el enemigo sabe moverse
    QTimer *tiempo = new QTimer ();
    connect(tiempo,SIGNAL(timeout()),this,SLOT(mover()));
    tiempo->start(500);
}
/*
void enemigo::perseguir(personaje *pers)
{
    if (pers->get_positionX() > pos().x()){
        setPos(x()+2,y());
        qDebug() << "Se movio a la derecha";
    } else if (pers->get_positionY() > pos().y()) {
        setPos(x(),y()+2);
        qDebug() << "Se movio hacia abajo";
    } else if (pers->get_positionX() < pos().x()) {
        setPos(x()-2,y());
        qDebug() << "Se movio hacia la izquierda";
    } else if (pers->get_positionY() < pos().y()) {
        setPos(x(),y()-2);
        qDebug() << "Se movio hacia arriba";
    }

}
*/


void enemigo::mover()
{
    /*

    QTimer *tiempo = new QTimer ();
    personaje *pers = new personaje ();


    double X = pers->get_positionX();
    double Y = pers->get_positionY();
    pers->setPos(X,Y);

    qDebug() << pers->pos().x() << " , " << pers->pos().y();

    //perseguir(pers);

    if (pers->get_positionX() > pos().x()){
        setPos(x()+2,y());
        qDebug() << "Se movio a la derecha";
    } else if (pers->get_positionY() > pos().y()) {
        setPos(x(),y()+2);
        qDebug() << "Se movio hacia abajo";
    } else if (pers->get_positionX() < pos().x()) {
        setPos(x()-2,y());
        qDebug() << "Se movio hacia la izquierda";
    } else if (pers->get_positionY() < pos().y()) {
        setPos(x(),y()-2);
        qDebug() << "Se movio hacia arriba";
    }
    */

    QList<QGraphicsItem *> items_colisionados = collidingItems();
    for (int i = 0, n = items_colisionados.size(); i < n; i++) {
        if (typeid(*(items_colisionados[i])) == typeid(personaje)) {
            //remover enemigo
            //scene()->removeItem(items_colisionados[i]);
            //qDebug() << "se removio enemigo";
            scene()->removeItem(this);
            //qDebug() << "se removio personaje";

            //eliminar el enemigo
            //delete items_colisionados[i];
            delete this;
            return;
        }

        //mover al enemigo
        //int aleaX = rand() % 2;
        //int aleaY = rand() % 2;
        setPos(x() + 50, y() + 50);

        //eliminar enemigo cuando salga de la pantalla
        if (pos().x() > 800 || pos().y() > 600) {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Enemigo eliminado"; // es lo mismo que el cout
        }
    }
}

void enemigo::generar()
{
    enemigo * enem = new enemigo ();
    scene()->addItem(enem);
}

void enemigo::colision()
{
    personaje *P = new personaje();
    if (this->collidesWithItem(P)) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "me choco";
    }
}

/*void enemigo::perseguir()
{
    personaje *P = new personaje ();
    enemigo *E =new enemigo ();

    if (P->get_positionX() > E->pos().x()){
        E->setPos(x()+2,y());
        qDebug() << P->get_positionX() << " , " << P->get_positionY();
    } else if (P->get_positionY() > E->pos().y()) {
        E->setPos(x(),y()+2);
        qDebug() << P->get_positionX() << " , " << P->get_positionY();
    } else if (P->get_positionX() < E->pos().x()) {
        E->setPos(x()-2,y());
        qDebug() << P->get_positionX() << " , " << P->get_positionY();
    } else if (P->get_positionY() < E->pos().y()) {
        E->setPos(x(),y()-2);
        qDebug() << P->get_positionX() << " , " << P->get_positionY();
    }
}
*/
