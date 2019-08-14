#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>

class enemigo: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemigo(QGraphicsItem *parent = nullptr);
public slots:
    void mover();
    void generar();
};

#endif // ENEMIGO_H
