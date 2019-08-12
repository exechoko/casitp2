#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class score: public QGraphicsTextItem{
private:
    int marcador;
public:
    score(QGraphicsItem * parent = nullptr);
    void incrementar();
    int get_score();

};

#endif // SCORE_H
