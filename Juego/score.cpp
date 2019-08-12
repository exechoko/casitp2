#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // inicializar el score en 0
    marcador = 0;

    // estilo del texto
    setPlainText(QString("Marcador: ") + QString::number(marcador)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void score::incrementar(){
    marcador++;
    setPlainText(QString("Marcador: ") + QString::number(marcador)); // Score: 1
}

int score::get_score(){
    return marcador;
}
