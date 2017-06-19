#include <iostream>
#include <string.h>

using namespace std;

struct infopersona
{
    char direccion[25];
    char ciudad[25];
    char provincia[20];
    long int codigo_postal;
};

struct cliente
{
    char nombre_cliente[25];
    infopersona cliinfo;
    double saldo;
};

struct empleado
{
    char nombreemp[25];
    infopersona empinfo;
    double salario;
};

//Funciones del cliente
void asignarCliente(const char * nombre, cliente * c)
{
    strcpy(c->nombre_cliente, nombre);
}

void direccionCliente(const char * direccion, cliente * c)
{
    strcpy(c->cliinfo.direccion, direccion);
}

void ciudadCliente(const char * ciudad, cliente * c)
{
    strcpy(c->cliinfo.ciudad, ciudad);
}

void provinciaCliente(const char * provincia, cliente * c)
{
    strcpy(c->cliinfo.provincia, provincia);
}

void cdPostalCliente(long int postal, cliente * c)
{
    c->cliinfo.codigo_postal=postal;
}

void saldoCliente(double saldo, cliente * c)
{
    c->saldo=saldo;
}

//Funciones del empleado
void nombreEmp(const char * nombre, empleado * c)
{
    strcpy(c->nombreemp, nombre);
}

void direccionEmp(const char * direccion, empleado * c)
{
    strcpy(c->empinfo.direccion, direccion);
}

void ciudadEmp(const char * ciudad, empleado * c)
{
    strcpy(c->empinfo.ciudad, ciudad);
}

void provinciaEmp(const char * provincia, empleado * c)
{
    strcpy(c->empinfo.provincia, provincia);
}

void cdPostalEmp(long int postal, empleado * c)
{
    c->empinfo.codigo_postal=postal;
}

void salarioEmp(double salario, empleado * c)
{
    c->salario=salario;
}

int main()
{
    cliente micliente;
    empleado miempleado;

    //variables para el cliente
    char nombre[25],direccion[25],ciudad[25],provincia[20];
    long int cdpostal;
    double saldo;

    //variables para el empleado
    char nombre2[25],direccion2[25],ciudad2[25],provincia2[20];
    long int cdpostal2;
    double salario;

    //ingresando datos del nuevo cliente
    cout<< "Ingrese el nombre del nuevo cliente"<< endl;
    cin >> nombre;
    cout<< "Ingrese la direccion del nuevo cliente"<< endl;
    cin >> direccion;
    cout<< "Ingrese la ciudad del cliente" << endl;
    cin >> ciudad;
    cout<< "Ingrese la provincia" << endl;
    cin >> provincia;
    cout<< "Ingrese el codigo postal" << endl;
    cin >> cdpostal;
    cout << "Ingrese el saldo" << endl;
    cin >> saldo;

    //ingresando los datos del empleado
    cout<< "Ingrese el nombre del nuevo empleado"<< endl;
    cin >> nombre2;
    cout<< "Ingrese la direccion del nuevo empleado"<< endl;
    cin >> direccion2;
    cout<< "Ingrese la ciudad del empleado" << endl;
    cin >> ciudad2;
    cout<< "Ingrese la provincia" << endl;
    cin >> provincia2;
    cout<< "Ingrese el codigo postal" << endl;
    cin >> cdpostal2;
    cout << "Ingrese el saldo" << endl;
    cin >> salario;

    //envia los datos a las funciones del empleado.
    asignarCliente(nombre, & micliente);
    direccionCliente(direccion, & micliente);
    ciudadCliente(ciudad, & micliente);
    provinciaCliente(provincia, & micliente);
    cdPostalCliente(cdpostal, & micliente);
    saldoCliente(saldo, & micliente);

    //envia los datos a las funciones del empleado
    nombreEmp(nombre2, & miempleado);
    direccionEmp(direccion2, & miempleado);
    ciudadEmp(ciudad2, & miempleado);
    provinciaEmp(provincia2, & miempleado);
    cdPostalEmp(cdpostal2, & miempleado);
    salarioEmp(salario, & miempleado);

    //imprimir informacion cliente
    cout << endl;
    cout << "Los datos del nuevo cliente son:" << endl;
    cout << "Nombre: "<< micliente.nombre_cliente << endl;
    cout << "Direccion: "<< micliente.cliinfo.direccion << endl;
    cout << "Ciudad: "<< micliente.cliinfo.ciudad << endl;
    cout << "Provincia: "<< micliente.cliinfo.provincia << endl;
    cout << "Codigo Postal: "<< micliente.cliinfo.codigo_postal << endl;
    cout << "Saldo: "<< micliente.saldo << endl;
    //imprime informacion del empleado
    cout << endl;
    cout << "Los datos del nuevo empleado son: " << endl;
    cout << "Nombre: " << miempleado.nombreemp<< endl;
    cout << "Direccion: " << miempleado.empinfo.direccion << endl;
    cout << "Ciudad: " << miempleado.empinfo.ciudad << endl;
    cout << "Provincia: " << miempleado.empinfo.provincia << endl;
    cout << "Codigo Postal: " << miempleado.empinfo.codigo_postal << endl;
    cout << "Salario: " << miempleado.salario << endl;


    return 0;
}
