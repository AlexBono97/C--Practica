#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    while(true)
    {
        cout << "Elige una opcion: " << endl;
        cout << "1) Crear Archivo" << endl;
        cout << "2) Escribir en el archivo" << endl;
        cout << "3) Imprimir el archivo" << endl;
        cout << "4) Salir" << endl;
        int opcion;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            {


            cout << "Ingrese el nombre del archivo que quiere" << endl;
            string nombre;
            cin>>nombre;
            ofstream miarchivo(nombre);
            break;
            }

        case 2:
            {
              cout << "Escriba en cual archivo quiere escribir" << endl;
            string nomarchivo;
            cin >> nomarchivo;

            ofstream miarchivo2(nomarchivo);

            if(miarchivo2.is_open())
                {
                    cout << "Escriba algo" << endl;
                    string lineas;
                    cin >> lineas;
                    miarchivo2 << lineas << endl;
                    miarchivo2.close();

            }else
            cout <<"No puedo abrirlo " << endl;


            }
            break;
        case 3:
            {
                cout << "Ingrese el nombre del archivo a imprimir" << endl;
                string nomarchivo;
                cin >> nomarchivo;

                string line;
                ifstream miarchivo3(nomarchivo);

                if(miarchivo3.is_open())
                    {
                        while(getline(miarchivo3,line))
                        {
                            cout << line << endl;
                        }
                        miarchivo3.close();
                }else
                {
                    cout << "No pude abrirlo en el segundo metodo" << endl;
                }
                break;

            }
        case 4:
            {
                return 0;
            }
            }


    }
    //crea archivo
    //ofstream miarchivo("Prueba.txt");

    //escribe en el archivp
    /*if(miarchivo.is_open())
    {
        miarchivo << "Hola a todos. \n";
        miarchivo << "Estamos probando escribir lineas. \n";
        miarchivo.close();

    }else
    cout <<"No puedo abrirlo " << endl;
*/
    //imprime archivo
    string line;
    ifstream miarchivo2("Prueba.txt");

    if(miarchivo2.is_open())
    {
        while(getline(miarchivo2,line))
        {
            cout << line << endl;
        }
        miarchivo2.close();
    }else
    {
        cout << "No pude abrirlo en el segundo metodo" << endl;
    }
    return 0;
}
