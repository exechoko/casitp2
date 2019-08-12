#ifndef MIRECTANGULO_H
#define MIRECTANGULO_H
#include <proyectil.h>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <enemigos.h>

class mirectangulo : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *evento);
public slots:
    void generar();

};

#endif // MIRECTANGULO_H
