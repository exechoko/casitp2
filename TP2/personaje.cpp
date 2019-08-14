#include "personaje.h"
#include <QKeyEvent>

personaje::personaje(QGraphicsItem *parent): QGraphicsRectItem (parent)
{
    setRect(0,0,25,25);
    setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    setPos(400,300);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

}

void personaje::keyPressEvent(QKeyEvent *movimiento)
{
    if (movimiento->key()==Qt::Key_Left){
        setPos(x() - 10, y());
    } else if (movimiento->key()==Qt::Key_Right) {
        setPos(x() + 10, y());
    } else if (movimiento->key()==Qt::Key_Up) {
        setPos(x(), y() - 10);
    } else if (movimiento->key()==Qt::Key_Down) {
        setPos(x(), y() + 10);
    }
}
