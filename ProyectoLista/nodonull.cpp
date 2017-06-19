#include "nodonull.h"

nodonull::nodonull(int px,int py)
{
    this->px=px;
    this->py=py;
}

QRectF nodonull::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void nodonull::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::red, 3);
    painter->setPen(pen);
    painter->drawRect(rect);
    QPen pent(Qt::black, 3);
    painter->setPen(pent);
    painter->drawText(50,50,"NULL");
    this->setX(px);
    this->setY(py);
}
