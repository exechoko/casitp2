#include "game.h"
#include <QDebug>



game::game(QWidget *parent)
{
    escena = new QGraphicsScene ();
    escena->setSceneRect(0,0,800,600);
    setScene(escena);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    P = new personaje ();

    E = new enemigo ();

    escena->addItem(P);
    escena->addItem(E);

    /*QTimer *tiempo = new QTimer();
    QObject::connect(tiempo,SIGNAL(timeout()),J,SLOT(generar()));*/

    //tiempo_movi = new QTimer ();
    tiempo_generar = new QTimer ();
    //connect(tiempo_movi,SIGNAL(timeout()),E,SLOT(mover()));
    connect(tiempo_generar,SIGNAL(timeout()),E,SLOT(generar()));
    //tiempo_movi->start(100);
    tiempo_generar->start(2000);

    if ((P->pos().x()&& P->pos().y()) == (E->pos().x() && P->pos().y()) ){
        qDebug() << "Colisiono";
    }






}
