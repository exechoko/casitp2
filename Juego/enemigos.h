#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsItem>

class enemigos : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemigos(QGraphicsItem *parent = nullptr);
public slots:
    void move();
};

#endif // ENEMIGOS_H
