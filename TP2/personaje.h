#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class personaje: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    personaje(QGraphicsItem * parent = nullptr);
    void keyPressEvent(QKeyEvent *movimiento);//usar si o si el metodo keyPressEvent
};

#endif // PERSONAJE_H
