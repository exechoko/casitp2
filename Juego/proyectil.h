#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QGraphicsRectItem>
#include <QDebug>
#include <QGraphicsItem>
#include <QObject>



class proyectil : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    proyectil(QGraphicsItem *parents = nullptr);
public slots:
    void move();
};

#endif // PROYECTIL_H
