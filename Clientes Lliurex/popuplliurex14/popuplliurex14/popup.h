#ifndef POPUP_H
#define POPUP_H

#include <QMainWindow>
#include <QMainWindow>
#include <stdio.h>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDir>
#include <iostream>
#include <QMessageBox>
#include <QCheckBox>
#include <QDate>
#include <QApplication>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QCryptographicHash>
#include <QByteArray>
#include <QProcess>
#include <QCloseEvent>

namespace Ui {
class popup;
}

class popup : public QMainWindow
{
    Q_OBJECT

public:
    explicit popup(QWidget *parent = 0);
    ~popup();

private slots:
    void closeEvent(QCloseEvent *);
    void vaciaUsuarioKM();
    void on_pushButton_clicked();
    QString leer_dato (QString dato);
    QString valida ();
    void actualizaFicheroAutentificacion(bool on);
    QStringList leerDatos(QString datos);
    void login(bool on, QString nombre, QString saldo);
    void on_pushButton_2_clicked();

private:
    Ui::popup *ui;
};

#endif // POPUP_H
