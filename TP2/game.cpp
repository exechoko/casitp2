#include "game.h"
#include <QDebug>



game::game(QWidget *parent)
{
    escena = new QGraphicsScene ();
    escena->setSceneRect(0, 0, 600, 600);
    setScene(escena);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600, 600);

    inicializar();

    P = new personaje();
    E = new enemigo();

    escena->addItem(P);
    escena->addItem(E);

    /*
    if (this->E->collidesWithItem(this->P)) {
        escena->removeItem(this->E);
        qDebug() << "me choco";
    }
    */

    tiempo_generar = new QTimer();
    tiempo = new QTimer();

    connect(tiempo_generar, SIGNAL(timeout()), E, SLOT(generar()));
    tiempo_generar->start(2000);

    connect(tiempo, SIGNAL(timeout()), E, SLOT(colision()));
    tiempo->start(50);
}

void game::inicializar()
{
    int band = 0;
    int dim = 12;
    C = new celda **[dim];

    for (int i = 0; i < dim; i++) {
        this->C[i] = new celda *[dim];
        for (int j = 0; j < dim; j++) {
            this->C[i][j] = new celda ();
            this->escena->addItem(C[i][j]);
            qDebug() << i << " " << j;
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (this->getValorMatriz(i,j)) {
                //getValor 0(cero) = pared
                QPixmap pix(":/pared.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(50, 50, Qt::KeepAspectRatio);
                this->C[i][j]->setPixmap(pix);
                //mover la posicion donde se van creando las celdas (es 50 porque el tamaño de la imag es 50*50)
                //sino se crean una encima de la otra
                this->C[i][j]->setPos(i * 50, j * 50);
                band = 0;

            } else {
                //getvalor 1(uno) = piso
                QPixmap pix(":/piso.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(50, 50, Qt::KeepAspectRatio);
                this->C[i][j]->setPixmap(pix);
                this->C[i][j]->setPos(i * 50, j * 50);
                band = 1;
            }
        }
        validar_paso(band);
    }

}

int game::getValorMatriz(int i, int j)
{
    return rand() % 2;
}

bool game::validar_paso(int band)
{
    if (band == 1)
        return true;
    else
        return false;
}
/*
void game::keyPressEvent(QKeyEvent *movimiento)
{
    if (movimiento->key() == Qt::Key_Left) {
        this->P->setPos(x() - 50, y());

    } else if (movimiento->key() == Qt::Key_Right) {
        this->P->setPos(x() + 50, y());

    } else if (movimiento->key() == Qt::Key_Up) {
        this->P->setPos(x(), y() - 50);

    } else if (movimiento->key() == Qt::Key_Down) {
        this->P->setPos(x(), y() + 50);
    }
}
*/
