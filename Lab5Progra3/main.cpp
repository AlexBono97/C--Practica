#include <iostream>
#include <list>

using namespace std;

class Entity
{
public:
    virtual void draw()=0;
    virtual void logic()=0;
};

class Guerrero : public Entity
{
public:
    void draw()
    {
        cout<< "Wraaaah" << endl;
    }
    void logic()
    {
        cout << "Function logic del guerrero" << endl;
    }
};
class Mago : public Entity
{
public:
    void draw()
    {
        cout << "pirrin" << endl;
    }
    void logic()
    {
        cout << "funcion logica del mago" << endl;
    }
};


int main()
{
    list<Entity*> entities;
    entities.push_back(new Mago());
    entities.push_back(new Guerrero());
    entities.push_back(new Mago());

    for(list<Entity*>::iterator i = entities.begin();
        i!=entities.end();
        i++)
    {
        (*i)->draw();
    }
    for(list<Entity*>::iterator i = entities.begin();
        i!=entities.end();
        i++)
    {
        (*i)->logic();
    }
    return 0;
}
