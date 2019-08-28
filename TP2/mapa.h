#ifndef MAPA_H
#define MAPA_H
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <mainwindow.h>


class mapa: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    mapa(QGraphicsItem *parent = nullptr);

    QLabel *** labels;
    unsigned long dim;
    void inicializarMatriz();
    int getValorMatriz(int i, int j);
};

#endif // MAPA_H

