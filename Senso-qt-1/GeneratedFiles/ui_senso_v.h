/********************************************************************************
** Form generated from reading UI file 'senso_v.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSO_V_H
#define UI_SENSO_V_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Senso_vClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTextEdit *textEdit;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuWinSenso_V1_0;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Senso_vClass)
    {
        if (Senso_vClass->objectName().isEmpty())
            Senso_vClass->setObjectName(QStringLiteral("Senso_vClass"));
        Senso_vClass->resize(731, 435);
        centralWidget = new QWidget(Senso_vClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 180, 141, 131));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 180, 141, 131));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 10, 141, 131));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 10, 141, 131));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(120, 320, 161, 31));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(190, 10, 141, 131));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(510, 10, 141, 131));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(350, 180, 141, 131));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 320, 47, 13));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(350, 320, 161, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 320, 47, 13));
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(510, 180, 141, 131));
        textEdit_3->setReadOnly(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 360, 421, 20));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        label_3->setFont(font);
        Senso_vClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Senso_vClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 21));
        menuWinSenso_V1_0 = new QMenu(menuBar);
        menuWinSenso_V1_0->setObjectName(QStringLiteral("menuWinSenso_V1_0"));
        Senso_vClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Senso_vClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Senso_vClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Senso_vClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Senso_vClass->setStatusBar(statusBar);

        menuBar->addAction(menuWinSenso_V1_0->menuAction());

        retranslateUi(Senso_vClass);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Senso_vClass, SLOT(rotKlicked()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Senso_vClass, SLOT(gelbKlicked()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), Senso_vClass, SLOT(blauKlicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Senso_vClass, SLOT(runKlicked()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), Senso_vClass, SLOT(gruenKlicked()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), Senso_vClass, SLOT(helpKlicked()));

        QMetaObject::connectSlotsByName(Senso_vClass);
    } // setupUi

    void retranslateUi(QMainWindow *Senso_vClass)
    {
        Senso_vClass->setWindowTitle(QApplication::translate("Senso_vClass", "WinSenso", 0));
        pushButton->setText(QApplication::translate("Senso_vClass", "Exit", 0));
        pushButton_2->setText(QApplication::translate("Senso_vClass", "Blei", 0));
        pushButton_3->setText(QApplication::translate("Senso_vClass", "Rot", 0));
        pushButton_4->setText(QApplication::translate("Senso_vClass", "Gelb", 0));
        pushButton_5->setText(QApplication::translate("Senso_vClass", "Gr\303\274n", 0));
        pushButton_6->setText(QApplication::translate("Senso_vClass", "Blau", 0));
        pushButton_7->setText(QApplication::translate("Senso_vClass", "Help", 0));
        label->setText(QApplication::translate("Senso_vClass", "Debug", 0));
        label_2->setText(QApplication::translate("Senso_vClass", "Status", 0));
        label_3->setText(QApplication::translate("Senso_vClass", "WinSenso V1.0  2017 FHWS FAK-ET Wolfgang Spie\303\237", 0));
        menuWinSenso_V1_0->setTitle(QApplication::translate("Senso_vClass", "V1.0", 0));
    } // retranslateUi

};

namespace Ui {
    class Senso_vClass: public Ui_Senso_vClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSO_V_H
