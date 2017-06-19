#ifndef LISTAVISUAL_H
#define LISTAVISUAL_H
#include "nodo.h"
#include "lista.h"
#include "nodov.h"
#include "nodonull.h"
#include <iostream>
#include <fstream>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QFile>

namespace Ui {
class ListaVisual;
}

class ListaVisual : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListaVisual(QWidget *parent = 0);
    ~ListaVisual();
    void initItems();
    void dibujar();

private slots:
    void on_btnAgregar_pressed();

    void on_pushButton_pressed();

    void on_btncargar_pressed();

    void on_pushButton_2_pressed();

private:
    const int PY=-22;
    int PX=-692;
    Lista *list;
    Ui::ListaVisual *ui;
    QGraphicsScene *scene;
    void addItemslist();
    nodov* item;

};

#endif // LISTAVISUAL_H
