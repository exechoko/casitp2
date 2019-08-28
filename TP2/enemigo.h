#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <personaje.h>

class enemigo: public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT

public:
    enemigo(QGraphicsItem *parent = nullptr);
public slots:
    virtual void mover();
    void generar();
    void colision();
    //void perseguir();
};

#endif // ENEMIGO_H
