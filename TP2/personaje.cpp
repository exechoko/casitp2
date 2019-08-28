#include "personaje.h"
#include <celda.h>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

personaje::personaje(QGraphicsItem *parent): QGraphicsPixmapItem (parent)
{
    QPixmap pix(":/personaje.jpg");
    pix = pix.scaled(50,50,Qt::KeepAspectRatio);
    setPixmap(pix);


    //setRect(0,0,25,25);
    //setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    //setPos(400,300);
    //agregado posicion por parametros
    setPos(coorX,coorY);

    /*if ((coorX != 400) || (coorY != 300)){
        setPos(coorX,coorY);
    }*/

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    get_positionX();
    get_positionY();

    ///////
    //connect(tiempo,SIGNAL(timeout()),this,SLOT(actualizar_posicion()));
    //tiempo->start(10);
}

void personaje::keyPressEvent(QKeyEvent *movimiento)
{
    //celda *c = new celda();
    //int band = 1;
    //if (c->validar(band)) {
    if (movimiento->key() == Qt::Key_Left) {
        setPos(x() - 50, y());

    } else if (movimiento->key() == Qt::Key_Right) {
        setPos(x() + 50, y());

    } else if (movimiento->key() == Qt::Key_Up) {
        setPos(x(), y() - 50);

    } else if (movimiento->key() == Qt::Key_Down) {
        setPos(x(), y() + 50);
    }
    //}

    actualizar_posicion();

}

//agregado
double personaje::get_positionX()
{
    return this->coorX;
}

double personaje::get_positionY()
{
    return this->coorY;
}

void personaje::actualizar_posicion()
{
    coorX = pos().x();
    coorY = pos().y();

    qDebug() << "posicion actualizada del personaje: " << coorX << " , " << coorY;
}
//
//capaz que no es necesario crear las variables de crX ni coorY
//verificar con pos().x y pos().y directamente
