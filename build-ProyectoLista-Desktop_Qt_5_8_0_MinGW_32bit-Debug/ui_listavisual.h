/********************************************************************************
** Form generated from reading UI file 'listavisual.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTAVISUAL_H
#define UI_LISTAVISUAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListaVisual
{
public:
    QWidget *centralWidget;
    QGraphicsView *ViewLista;
    QLineEdit *txtvalor;
    QLabel *label;
    QPushButton *btnAgregar;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txtpromedio;
    QLineEdit *txtcantnodos;
    QLineEdit *txtsumnodos;
    QLineEdit *txtmayor;
    QLabel *label_5;
    QLineEdit *txtmenor;
    QLabel *label_6;
    QLineEdit *txtfile;
    QPushButton *btncargar;
    QPushButton *pushButton;
    QLabel *label_7;
    QComboBox *cmbobjetos;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ListaVisual)
    {
        if (ListaVisual->objectName().isEmpty())
            ListaVisual->setObjectName(QStringLiteral("ListaVisual"));
        ListaVisual->resize(866, 473);
        centralWidget = new QWidget(ListaVisual);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ViewLista = new QGraphicsView(centralWidget);
        ViewLista->setObjectName(QStringLiteral("ViewLista"));
        ViewLista->setGeometry(QRect(10, 10, 831, 171));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        ViewLista->setFont(font);
        txtvalor = new QLineEdit(centralWidget);
        txtvalor->setObjectName(QStringLiteral("txtvalor"));
        txtvalor->setGeometry(QRect(20, 250, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 230, 47, 13));
        btnAgregar = new QPushButton(centralWidget);
        btnAgregar->setObjectName(QStringLiteral("btnAgregar"));
        btnAgregar->setGeometry(QRect(40, 290, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 370, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 240, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 270, 101, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 300, 101, 16));
        txtpromedio = new QLineEdit(centralWidget);
        txtpromedio->setObjectName(QStringLiteral("txtpromedio"));
        txtpromedio->setGeometry(QRect(260, 240, 113, 20));
        txtcantnodos = new QLineEdit(centralWidget);
        txtcantnodos->setObjectName(QStringLiteral("txtcantnodos"));
        txtcantnodos->setGeometry(QRect(300, 270, 113, 20));
        txtsumnodos = new QLineEdit(centralWidget);
        txtsumnodos->setObjectName(QStringLiteral("txtsumnodos"));
        txtsumnodos->setGeometry(QRect(280, 300, 113, 20));
        txtmayor = new QLineEdit(centralWidget);
        txtmayor->setObjectName(QStringLiteral("txtmayor"));
        txtmayor->setGeometry(QRect(280, 360, 113, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 330, 101, 16));
        txtmenor = new QLineEdit(centralWidget);
        txtmenor->setObjectName(QStringLiteral("txtmenor"));
        txtmenor->setGeometry(QRect(280, 330, 113, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 360, 101, 16));
        txtfile = new QLineEdit(centralWidget);
        txtfile->setObjectName(QStringLiteral("txtfile"));
        txtfile->setGeometry(QRect(566, 280, 161, 20));
        btncargar = new QPushButton(centralWidget);
        btncargar->setObjectName(QStringLiteral("btncargar"));
        btncargar->setGeometry(QRect(564, 320, 75, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(654, 320, 75, 23));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(590, 260, 111, 20));
        cmbobjetos = new QComboBox(centralWidget);
        cmbobjetos->setObjectName(QStringLiteral("cmbobjetos"));
        cmbobjetos->setGeometry(QRect(30, 330, 101, 22));
        ListaVisual->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ListaVisual);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 866, 21));
        ListaVisual->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ListaVisual);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ListaVisual->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ListaVisual);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ListaVisual->setStatusBar(statusBar);

        retranslateUi(ListaVisual);

        QMetaObject::connectSlotsByName(ListaVisual);
    } // setupUi

    void retranslateUi(QMainWindow *ListaVisual)
    {
        ListaVisual->setWindowTitle(QApplication::translate("ListaVisual", "ListaVisual", Q_NULLPTR));
        label->setText(QApplication::translate("ListaVisual", "Valor", Q_NULLPTR));
        btnAgregar->setText(QApplication::translate("ListaVisual", "Agregar", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ListaVisual", "Remover", Q_NULLPTR));
        label_2->setText(QApplication::translate("ListaVisual", "Promedio", Q_NULLPTR));
        label_3->setText(QApplication::translate("ListaVisual", "Cantidad de Nodos", Q_NULLPTR));
        label_4->setText(QApplication::translate("ListaVisual", "Suma de Nodos", Q_NULLPTR));
        label_5->setText(QApplication::translate("ListaVisual", "Nodo Mayor", Q_NULLPTR));
        label_6->setText(QApplication::translate("ListaVisual", "Nodo Menor", Q_NULLPTR));
        btncargar->setText(QApplication::translate("ListaVisual", "Cargar Lista", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ListaVisual", "Guardar Lista", Q_NULLPTR));
        label_7->setText(QApplication::translate("ListaVisual", "Nombre del Documento", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ListaVisual: public Ui_ListaVisual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTAVISUAL_H
