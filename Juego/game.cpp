#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemigos.h"

game::game(QWidget * parent)
{
    /*// Iniciamos la escena y definimos su tamaño
    QGraphicsScene scene;
    scene.setSceneRect(-100, -100, 200, 200);
    // Color y estilo
    scene.setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));

    // Creamos y agregamos nuestro item (rectángulo) a la escena
    QGraphicsRectItem *item = new QGraphicsRectItem();
    // izquierda, arriba, ancho y alto
    item->setRect(0, 0, 140, 60);
    // Línea: Ancho y estilo
    item->setPen(QPen(Qt::blue, 4, Qt::SolidLine));
    // Relleno: Color y estilo.
    item->setBrush(QBrush(Qt::green, Qt::SolidPattern));

    // Creamos una vista para visualizar la escena
    QGraphicsView view(&scene);
    view.setRenderHints(QPainter::Antialiasing);
    view.show();*/

    // creamos una escena
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); //creamos la escena 800*600

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // creamos un jugador(forma rectangular)
    J = new jugador();
    // definimos tamaño del jugador y posicion
    J->setRect(0, 0, 50, 50);
    // color y ancho de la linea del jugador
    J->setPen(QPen(Qt::red, 3, Qt::SolidLine));
    // color de relleno del jugador
    J->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    J->setPos(400,500);
    //para que capte el teclado
    J->setFlag(QGraphicsItem::ItemIsFocusable);
    J->setFocus();
    // agregamos el item a la escena
    scene->addItem(J);

    //creamos el score y las vidas
    marcador = new score();
    scene->addItem(marcador);
    V = new vidas();
    V->setPos(V->x(),V->y()+25);
    scene->addItem(V);


    // generar enemigos
    QTimer *tiempo = new QTimer();
    QObject::connect(tiempo,SIGNAL(timeout()),J,SLOT(generar()));
    tiempo->start(2000);

    show();

}
