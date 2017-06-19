#ifndef NODONULL_H
#define NODONULL_H
#include <qpainter.h>
#include<qgraphicsitem.h>

class nodonull: public QGraphicsItem
{
public:
    nodonull(int px,int py);
    QRectF boundingRect() const;
    void paint(QPainter* painter,const QStyleOptionGraphicsItem *option, QWidget* widget);
    int px,py;
};

#endif // NODONULL_H
