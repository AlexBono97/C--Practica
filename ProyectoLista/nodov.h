#ifndef NODOV_H
#define NODOV_H
#include <qpainter.h>
#include<qgraphicsitem.h>
#include <qtextstream.h>

class nodov: public QGraphicsItem
{
public:
    nodov(int px,int py, int va,int nNodo);


    QRectF boundingRect() const;
    void paint(QPainter* painter,const QStyleOptionGraphicsItem *option, QWidget* widget);
    int px,py;
    int valor,nNodo;
protected:
    void mousePressEvent(QGraphicsSceneEvent *event);
    void mouseReleaseEvent(QGraphicsSceneEvent *event);
};

#endif // NODOV_H
