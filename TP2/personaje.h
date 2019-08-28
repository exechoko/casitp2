#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>

class personaje : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    //agregado parametros de posicionamiento
    double /*int*/ coorX = 400;
    double /*int*/ coorY = 300;
    //

public:
    personaje(QGraphicsItem * parent = nullptr);
    //void keyPressEvent(QKeyEvent *movimiento);//usar si o si el metodo keyPressEvent
    //agregado
    double get_positionX();
    double get_positionY();
    //
    //void actualizar_posicion();

public slots:
    void keyPressEvent(QKeyEvent *movimiento); //usar si o si el metodo keyPressEvent
    void actualizar_posicion();
    //
};

#endif // PERSONAJE_H
