#include "nodov.h"


nodov::nodov(int px, int py, int valor, int nNodo)
{
    this->px=px;
    this->py=py;
    this->valor=valor;
    this->nNodo=nNodo;
    setFlag(ItemIsSelectable);
}

QRectF nodov::boundingRect() const
{
    return QRectF(0,0,9,9);//controla tamano
}

void nodov::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QString text=QString::number(valor);
    QRectF rect = boundingRect();
    QRectF rect2 = boundingRect();
    QRectF rect3 = boundingRect();
    QRectF rect4 = boundingRect();
    QPen pen(Qt::blue, 3);//(color,grosor)
    painter->setPen(pen);
    painter->drawPolygon(rect);//polygon=cuadrado
   // painter->drawEllipse(rect2);
   // painter->drawEllipse(rect3);
   // painter->drawEllipse(rect4);
    QPen pent(Qt::black, 1);
    painter->setPen(pent);
   // painter->drawText(50,50,text);
   // QTextStream(stdout) << "x: "<<this->x()<<" y: "<< this->y();
    rect.setRect(0,0,-10,-10);

   /* rect->setY(0);
    rect2->setX(25);
    rect2->setY(0);
    rect3->setX(50);
    rect3->setY(0);
    rect4->setX(75);
    rect4->setY(0);*/

}

void nodov::mousePressEvent(QGraphicsSceneEvent *event)
{

}
