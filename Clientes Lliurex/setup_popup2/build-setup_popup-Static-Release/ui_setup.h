/********************************************************************************
** Form generated from reading UI file 'setup.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setup
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;
    QFrame *line_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_5;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *setup)
    {
        if (setup->objectName().isEmpty())
            setup->setObjectName(QString::fromUtf8("setup"));
        setup->resize(312, 488);
        centralWidget = new QWidget(setup);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(69, 90, 231, 131));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(20, 70, 65, 27));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(91, 70, 131, 27));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);
        label_3->setGeometry(QRect(20, 100, 65, 27));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(91, 100, 131, 27));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 145, 52));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setChecked(true);

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(layoutWidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 400, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 400, 99, 27));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 60, 219, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 30, 210, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_2);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(70, 230, 221, 22));
        checkBox->setChecked(true);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(40, 270, 221, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 0, 301, 22));
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 290, 221, 22));
        lineEdit_5 = new QLineEdit(centralWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setGeometry(QRect(160, 350, 131, 27));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(false);
        label_4->setGeometry(QRect(70, 320, 81, 27));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(false);
        label_5->setGeometry(QRect(70, 350, 65, 27));
        lineEdit_4 = new QLineEdit(centralWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(160, 320, 131, 27));
        setup->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(setup);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 312, 25));
        setup->setMenuBar(menuBar);
        mainToolBar = new QToolBar(setup);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        setup->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(setup);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        setup->setStatusBar(statusBar);

        retranslateUi(setup);
        QObject::connect(pushButton_2, SIGNAL(clicked()), setup, SLOT(close()));

        QMetaObject::connectSlotsByName(setup);
    } // setupUi

    void retranslateUi(QMainWindow *setup)
    {
        setup->setWindowTitle(QApplication::translate("setup", "setup", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("setup", "Usuario:", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QString());
        label_3->setText(QApplication::translate("setup", "Passwd:", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QString());
        radioButton_3->setText(QApplication::translate("setup", "Usuario Multiple", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("setup", "Usuario Unico", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("setup", "Instalar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("setup", "Cerrar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setup", "Servidor: ", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("setup", "Lliurex 14", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("setup", "Lliurex 15+", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("setup", "Instalar Impresora PrinToMe", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("setup", "Instalar Autentificaci\303\263n PrintControl", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("setup", "Instalar Impresora Directa", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QString());
        label_4->setText(QApplication::translate("setup", "Impresora:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("setup", "Puerto:", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class setup: public Ui_setup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
