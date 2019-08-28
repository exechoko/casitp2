#include "celda.h"

celda::celda(QGraphicsItem *parent): QGraphicsPixmapItem (parent)
{
    //QPixmap pix(":/pared.png");
    //pix(":/pared.png");
    //pix = pix.scaled(50,50,Qt::KeepAspectRatio);
    //setPixmap(pix);
    //setPos(200,200);
}

bool celda::validar(int band)
{
    if (band == 1)
        return true;
    else
        return false;
}
