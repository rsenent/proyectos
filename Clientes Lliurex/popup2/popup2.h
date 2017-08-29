#ifndef POPUP2_H
#define POPUP2_H

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
#include <QWebPage>
#include <QWebView>
#include <QWebFrame>
#include <QTextStream>
#include <QProcess>

namespace Ui {
class popup2;
}

class popup2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit popup2(QWidget *parent = 0);
    ~popup2();

private slots:
    void on_pushButton_clicked();
    QString leer_dato (QString dato);
    QString valida ();
    void actualizaFicheroAutentificacion();
    QStringList leerDatos(QString datos);

private:
    Ui::popup2 *ui;
};

#endif // POPUP2_H
