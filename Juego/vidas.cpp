#include "vidas.h"
#include <QFont>

vidas::vidas(QGraphicsItem *parent): QGraphicsTextItem (parent)
{
    //inicializar las vidas
    vida = 3;
    //dibujando el texto
    setPlainText(QString("Vidas: ") + QString::number(vida)); //muestra Vidas: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",15));
}

void vidas::reducir()
{
    vida--;
    setPlainText(QString("Vidas: ") + QString::number(vida)); // muestra Vidas: 2

}

int vidas::get_vidas()
{
    return vida;
}
