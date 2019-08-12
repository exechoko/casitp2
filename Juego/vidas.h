#ifndef VIDAS_H
#define VIDAS_H
#include <QGraphicsTextItem>

class vidas: public QGraphicsTextItem
{
private:
    int vida;
public:
    vidas(QGraphicsItem * parent = nullptr);
    void reducir();
    int get_vidas();
};

#endif // VIDAS_H
