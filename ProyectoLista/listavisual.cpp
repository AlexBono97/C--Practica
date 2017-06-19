#include "listavisual.h"
#include "ui_listavisual.h"
#include <fstream>


ListaVisual::ListaVisual(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListaVisual)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->ViewLista->setScene(scene);
    list=new Lista();
    // create our object and add it to the scene
 /*   item = new nodov(-692,-22,1,1);
    scene->addItem(item);
    QGraphicsPixmapItem *newItem=new QGraphicsPixmapItem(QPixmap("flechas.png"));
    newItem->setX(-592);
    newItem->setY(-22);
    scene->addItem(newItem);
    scene->addItem(new nodov(-492,-22,1,1));*/

}

ListaVisual::~ListaVisual()
{
    delete ui;
}

void ListaVisual::dibujar()
{
    PX=-692;//posicion inicial X del primer nodo
    scene->clear();
    ui->ViewLista->update();
    int cant =0;
    Nodo* temp= list->inicial;
    while(temp!=0){

        scene->addItem(new nodov(PX,PY,temp->getVal(),cant));
        PX+=100;
        QGraphicsPixmapItem *newItem=new QGraphicsPixmapItem(QPixmap("flechas.png"));
        newItem->setX(PX);
        newItem->setY(PY);
        scene->addItem(newItem);
        PX+=100;
        temp=temp->getSig();
    }
    scene->addItem(new nodonull(PX,PY));//agrega el nodo Null
}

void ListaVisual::on_btnAgregar_pressed()
{
    int val=ui->txtvalor->text().toInt();
    Nodo *nuevo=new Nodo(val);
    list->agregarNodo(nuevo);
    ui->txtcantnodos->setText(QString::number(list->cantNodos()));
    ui->txtsumnodos->setText(QString::number(list->sumaNodos()));
    ui->txtpromedio->setText(QString::number(list->promedioNodos()));
    ui->txtmayor->setText(QString::number(list->nodoMayor()->getVal()));
    ui->txtmenor->setText(QString::number(list->nodoMenor()->getVal()));
    dibujar();
    ui->cmbobjetos->addItem(QString::number(val));
    ui->txtfile->setText(QString::number(ui->cmbobjetos->currentIndex()));
}

void ListaVisual::on_pushButton_pressed()
{//ecribir

    QFile file(ui->txtfile->text());
        // Trying to open in WriteOnly and Text mode
        file.open(QFile::WriteOnly |QFile::Text);


        // To write text, we use operator<<(),
        // which is overloaded to take
        // a QTextStream on the left
        // and data types (including QString) on the right

        QTextStream out(&file);
        Nodo* temp=list->inicial;
        while(temp!=0){
        out << QString::number(temp->getVal())<<"\n";
        temp=temp->getSig();
        file.flush();
        }

        file.close();
        list->inicial=0;
        scene->clear();
        ui->ViewLista->update();



    /*ofstream out(ui->txtfile->text());
    Nodo* temp=list->inicial;
    while(temp!=0){

      int num=temp->getVal();
      out.write((char*)&num,4);
      temp=temp->getSig();
    }
    scene->clear();
    ui->ViewLista->update();
    out.close();*/
}

void ListaVisual::on_btncargar_pressed()
{


    //leer
    QFile file(ui->txtfile->text());
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream in(&file);
    while(!in.atEnd()){
       QString myText = in.readLine();
       list->agregarNodo(new Nodo(myText.toInt()));
    }

    file.close();
    dibujar();
    /*ifstream in(ui->txtfile->text());
    in.seekg(0,ios::end);
    int cant_registros = in.tellg()/4;
    int num_lectura;
    in.seekg(0,ios::beg);
    for(int i=0;i<cant_registros;i++)
    {
        in.read((char*)&num_lectura,4);
        list->agregarNodo(new Nodo(num_lectura));
    }
    in.close();
    dibujar();*/



}

void ListaVisual::on_pushButton_2_pressed()
{   Nodo* temp=list->inicial;
    int num =ui->cmbobjetos->currentIndex();
    if(num==0){
        if(list->inicial->getSig()!=0){
            list->inicial=list->inicial->getSig();
            list->inicial->agregarAnt(0);
        }
        else
           list->inicial=0;


    }
    else{
        int cont=0;

        while(temp!=0){
            if(num==cont){
                break;

            }
            cont++;
            temp=temp->getSig();
        }
        temp->getAnt()->agregarSig(temp->getSig());
       // temp->getSig()->agregarAnt(temp->getAnt());
    }

    dibujar();
    ui->cmbobjetos->clear();
    addItemslist();
}

void ListaVisual::addItemslist()
{
    Nodo* temp= list->inicial;
    while(temp!=0){

        ui->cmbobjetos->addItem(QString::number(temp->getVal()));
        temp=temp->getSig();
    }
}
