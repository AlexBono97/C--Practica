#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include "aplicacion.h"
#include "listaaplicaciones.h"
#include <iostream>
#include <QStringList>
//cuadritos
#include <QPainter>
#include <QGraphicsScene>

#define DIV 1024
#define WIDTH 7
using namespace std;
// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

ListaAplicaciones lista;
int ram=0;
long int idSel=0;
void PrintProcessNameAndID( DWORD processID )
{


    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.

    HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, processID );

    // Get the process name.

    if (NULL != hProcess )
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod),
             &cbNeeded) )
        {
            GetModuleBaseName( hProcess, hMod, szProcessName,
                               sizeof(szProcessName)/sizeof(TCHAR) );
        }
    }

    // process name and identifier.
    string t;
            #ifndef UNICODE
                t = szProcessName;
            #else
                std::wstring wStr = szProcessName;
                t = std::string(wStr.begin(), wStr.end());
            #endif
            QString nt= QString::fromStdString(t);
            unsigned long int ID= processID;
            Aplicacion* a= new Aplicacion(nt, ID);
            lista.addApp(a);

    // Release the handle to the process.

    CloseHandle( hProcess );
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nameL->setText("");
    ui->ramL->setText("");
    ui->idL->setText("");
    MEMORYSTATUSEX statex;

     statex.dwLength = sizeof (statex);

     GlobalMemoryStatusEx (&statex);

     ui->progressBar->setValue(statex.dwMemoryLoad);
     ui->progressBar_2->setValue(0);
     ram=8388608*(statex.dwMemoryLoad/100);

    DWORD aProcesses[1024], cbNeeded, cProcesses;
        unsigned int i;

        if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
        {

        }


        // Calculate how many process identifiers were returned.

        cProcesses = cbNeeded / sizeof(DWORD);

        // Print the name and process identifier for each process.

        for ( i = 0; i < cProcesses; i++ )
        {
            if( aProcesses[i] != 0 )
            {
                PrintProcessNameAndID( aProcesses[i] );
            }
        }
        QStringList* lis= lista.toArray();
    if (lis->isEmpty() ){
        for(int i = 0; i < 10; i++)
            {
                ui->listWidget->addItem("Item " + QString::number(i));
            }
    } else {
        for(int i = 0; i < lis->size(); i++)
            {
                ui->listWidget->addItem(lis->at(i));

            }
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::setValueProgressBar(long int val){
    MEMORYSTATUSEX statex;

     statex.dwLength = sizeof (statex);

     GlobalMemoryStatusEx (&statex);
     int ram2=8388608*(statex.dwMemoryLoad/100);
    return (val*100)/ram2;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    // Get the pointer to the currently selected item.
    item = ui->listWidget->currentItem();

    // Set the text color and its background color using the pointer to the item.
    //item->setTextColor(Qt::white);
    //item->setBackgroundColor(Qt::blue);
    ui->nameL->setText(item->text());
    long int processID=lista.getID(item->text());
    idSel=processID;
    ui->idL->setText(QString::number(processID));
    HANDLE hProcess;
    PROCESS_MEMORY_COUNTERS pmc;

    hProcess = OpenProcess(  PROCESS_QUERY_INFORMATION |
                                    PROCESS_VM_READ,
                                    FALSE, processID );
    if (NULL == hProcess)
        return;

    if ( GetProcessMemoryInfo( hProcess, &pmc, sizeof(pmc)) )
    {
        ui->ramL->setText(""+QString::number(pmc.WorkingSetSize)+"KB");
        ui->progressBar_2->setValue((100)*(pmc.PagefileUsage)/pmc.WorkingSetSize);
    }
    CloseHandle( hProcess );
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    lista.head=0;
    DWORD aProcesses[1024], cbNeeded, cProcesses;
        unsigned int i;

        if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
        {

        }


        // Calculate how many process identifiers were returned.

        cProcesses = cbNeeded / sizeof(DWORD);

        // Print the name and process identifier for each process.

        for ( i = 0; i < cProcesses; i++ )
        {
            if( aProcesses[i] != 0 )
            {
                PrintProcessNameAndID( aProcesses[i] );
            }
        }
        QStringList* lis= lista.toArray();
    if (lis->isEmpty() ){
        for(int i = 0; i < 10; i++)
            {
                ui->listWidget->addItem("Item " + QString::number(i));
            }
    } else {
        for(int i = 0; i < lis->size(); i++)
            {
                ui->listWidget->addItem(lis->at(i));

            }
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    HANDLE explorer;
    explorer = OpenProcess(PROCESS_ALL_ACCESS,false,idSel);
    TerminateProcess(explorer,1);
    CloseHandle(explorer);
}
