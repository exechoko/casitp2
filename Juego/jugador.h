#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class jugador : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    jugador(QGraphicsItem * parent = nullptr);
    void keyPressEvent(QKeyEvent *evento);
public slots:
    void generar();

};

#endif // JUGADOR_H
