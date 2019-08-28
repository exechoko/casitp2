#ifndef CELDA_H
#define CELDA_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class celda: public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT

public:
    celda(QGraphicsItem *parent = nullptr);
    bool validar(int band);
};

#endif // CELDA_H
