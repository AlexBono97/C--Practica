#include "listaaplicaciones.h"

ListaAplicaciones::~ListaAplicaciones()
{
    //dtor
}
ListaAplicaciones::ListaAplicaciones()
{
    head=0;
    tail=0;
    cont =0;
}

bool ListaAplicaciones::verificar(Aplicacion* a){
    Aplicacion* tmp = head;
     while(tmp != 0){
         if (tmp->name==a->name)
             return false;
         tmp = tmp->next;
     }
     return true;
}

void ListaAplicaciones::addApp(Aplicacion* a)
{
    if (head==0){
        head=a;
        tail=a;
        tail->setAnt(head);
    } else {
       if(verificar(a)){
        a->setAnt(tail);
        tail->setNext(a);
        tail=tail->next;
       } else {

       }
    }
    cont++;
}
void ListaAplicaciones::printList()
{
       Aplicacion* tmp = head;

        while(tmp != 0){
            if (tmp->name!= "<unkn")

            tmp = tmp->next;
        }
}

QStringList* ListaAplicaciones::toArray(){
    QStringList* lis=new QStringList();
    Aplicacion* tmp = head;

     while(tmp != 0){
         if (tmp->name!= "<unkn")
            lis->append((tmp->name));
         tmp = tmp->next;
     }

     return lis;
}

long int ListaAplicaciones::getID(QString nam){
    Aplicacion* tmp = head;
    while(tmp != 0){
        if (tmp->name== nam)
            return tmp->id;
        tmp=tmp->getNext();
    }
    return 1;
}
