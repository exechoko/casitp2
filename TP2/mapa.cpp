#include "mapa.h"



mapa::mapa(QGraphicsItem *parent)
{
    this->inicializarMatriz();
}

void mapa::inicializarMatriz()
{
    //En el ejemplo voy usando dim = 30
    this->dim = 30;

    this->labels = new QLabel**[dim];
    for (unsigned long i = 0; i < dim; i++) {
        this->labels[i] = new QLabel*[dim];
        for (unsigned long j = 0; j < dim; j++) {

                this->labels[i][j] = new QLabel();
                this->labels[i][j]->setBackgroundRole(QPalette::Dark);
                this->labels[i][j]->setScaledContents(true);

                this->labels[i][j]->setFixedSize(17,17);
                this->labels[i][j]->setText(" ");
                this->show();
                //this->show(labels[i][j] ,i,j);

        }

    }

    for (unsigned long i = 0; i < dim; i++) {
        for (unsigned long j = 0; j < dim; j++) {
            if (this->getValorMatriz(i,j)) {
                QPixmap pix(":/pared.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);

            } else {
                QPixmap pix(":/piso.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);
            }
        }
     }

}

int mapa::getValorMatriz(int i, int j)
{
    return rand() %2;
}

