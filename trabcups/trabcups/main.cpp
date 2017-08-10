#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <iostream>
#include <QTextStream>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>

using namespace std;

/*
struct Datos{
    QString impresora;
    QString jobId;
    QString nombreFicheroCups;
};
*/

struct Datos {
    QString impresora;
    QString jobId;
    QString nombreFicheroCups;
    QString usuario;
    QString usuarioHost;
    QString nombreTrabajo;
    int color;
    int paginas;
    int copias;
    int duplex;
    QString tamPagina;
};

void procesarDatos(Datos datos);
bool conectarMariaDB();
Datos recogerDatos(Datos dato);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 3) {
        std::cout << "Error: Numero de argumentos invalido" << endl << "Uso: trabcups jobid impresora" << endl;
        return 1;
    } else {
        Datos datos;
        datos.jobId = argv[1];
        datos.impresora = argv[2];
        if (conectarMariaDB()) {
            procesarDatos(datos);
        }
        return 0;
    }
}

void procesarDatos(Datos dato)
{
        QSqlQuery query;
        dato = recogerDatos(dato);
        query.prepare("INSERT INTO cups_trabajos (job_id,"
                      "usuario, "
                      "usuario_host, "
                      "nombre_fichero_cups, "
                      "nombre_trabajo, "
                      "color, "
                      "paginas, "
                      "copias, "
                      "duplex, "
                      "impresora, "
                      "tam_pagina)"
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(dato.jobId);
        query.addBindValue(dato.usuario);
        query.addBindValue(dato.usuarioHost);
        query.addBindValue(dato.nombreFicheroCups);
        query.addBindValue(dato.nombreTrabajo);
        query.addBindValue(dato.color);
        query.addBindValue(dato.paginas);
        query.addBindValue(dato.copias);
        query.addBindValue(dato.duplex);
        query.addBindValue(dato.impresora);
        query.addBindValue(dato.tamPagina);
        if (!query.exec()) {
            std::cout << "Error: " << query.lastError().databaseText().toStdString() << endl;
        }
}

Datos recogerDatos(Datos dato)
{
    dato.nombreFicheroCups = "/var/spool/cups/d";
    int i = 0;
    while (i + dato.jobId.count() < 5) {
        dato.nombreFicheroCups.append("0");
        i++;
    }
    dato.nombreFicheroCups.append(dato.jobId);
    dato.nombreFicheroCups.append("-001");
    dato.paginas = 1;
    dato.copias = 1;
    dato.duplex = 0;
    dato.color = 1;
    dato.tamPagina = "Tam. Pers.";
    dato.nombreTrabajo = "";
    dato.usuarioHost = "";
    if (dato.nombreFicheroCups == "") {

    } else {
        QFile fcups(dato.nombreFicheroCups);
        if (fcups.open(QIODevice::ReadOnly)) {
            QTextStream stream(&fcups);
            QString linea;
            while (!stream.atEnd()) {
                linea = stream.readLine();
                if (linea.startsWith("@PJL SET USERNAME = \"")) {
                    linea = linea.replace("@PJL SET USERNAME = \"", "");
                    linea = linea.replace("\"", "");
                    linea = linea.replace("\n", "");
                    dato.usuarioHost = linea;
                }
                if (linea.startsWith("@PJL SET KMCERTFLEXSTING1 = \"")) {
                    linea = linea.replace("@PJL SET KMCERTFLEXSTING1 = \"", "");
                    linea = linea.replace("\"", "");
                    linea = linea.replace("\n", "");
                    dato.usuario = linea;
                }
                if (linea.startsWith("@PJL SET JOBNAME = \"")) {
                    linea = linea.replace("@PJL SET JOBNAME = \"", "");
                    linea = linea.replace("\"", "");
                    linea = linea.replace("\n", "");
                    dato.nombreTrabajo = linea;
                }
                if (linea.startsWith("@PJL SET QTY = ")) {
                    linea = linea.replace("@PJL SET QTY = ", "");
                    linea = linea.replace("\n", "");
                    dato.copias = linea.toInt();
                }
                if ((linea.startsWith("%%BeginFeature: *KMDuplex 2Sided"))||(linea.startsWith("<</Duplex true>>"))) {
                    dato.duplex = 1;
                }
                if (linea.contains("KMColorSelect 0")) {
                    dato.color = 0;
                }
                if (linea.startsWith("(%%[Page: ")) {
                    linea = linea.replace("(%%[Page: ", "");
                    linea = linea.replace("]%%) =", "");
                    linea = linea.replace("\n", "");
                    dato.paginas = linea.toInt();
                }
                if (linea.startsWith("(%%[Pages: ")) {
                    linea = linea.replace("(%%[Pages: ", "");
                    linea = linea.replace("]%%) =", "");
                    linea = linea.replace("\n", "");
                    dato.paginas = linea.toInt();
                }
                if (linea.startsWith("%%BeginFeature: *PageSize ")) {
                    linea = linea.replace("%%BeginFeature: *PageSize ", "");
                    linea = linea.replace("\n", "");
                    dato.tamPagina = linea;
                }
                if ((linea.startsWith("%%Title: ("))&&(dato.nombreTrabajo == "")) {
                    linea = linea.replace("%%Title: (", "");
                    linea = linea.replace(")", "");
                    linea = linea.replace("\n", "");
                    dato.nombreTrabajo = linea;
                }
                if ((linea.startsWith("%%For: ("))&&(dato.usuarioHost=="")) {
                    linea = linea.replace("%%For: (", "");
                    linea = linea.replace(")", "");
                    linea = linea.replace("\n", "");
                    dato.usuarioHost = linea;
                }
            }
            fcups.close();
        }
    }
    return dato;
}

bool conectarMariaDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("oli_printcontrol");
    db.setUserName("printcontrol");
    db.setPassword("PCadmin123$");
    if (db.open())
    {
        return true;
    }
    return false;
}
