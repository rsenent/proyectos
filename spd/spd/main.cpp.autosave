#include <QCoreApplication>
#include <QThread>
#include <QtSql/QSqlDatabase>
#include <iostream>
#include <QTextStream>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <QDirIterator>
#include <QDateTime>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

bool conectarMariaDB(QSqlDatabase db);
QStringList ejecuta ();
bool consultaExisteJobID(QString jobID);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    conectarMariaDB(db);
    QStringList jobIDs;
    QProcess proceso;
    QString exe;
    QString pass;
    while (true) {
        if (db.open()) {
            jobIDs = ejecuta();
            for (int i = 0; i < jobIDs.count(); i++) {
                exe.clear();
                exe = "ci ";
                exe.append(jobIDs[i]);
                pass = "";
                proceso.start(exe);
                proceso.waitForFinished(-1);
                pass = proceso.readAllStandardOutput();
                exe.clear();
                exe = "/opt/printcontrol/apps/trabcups ";
                exe.append(jobIDs[i]);
                exe.append(" ");
                exe.append(pass);
                proceso.start(exe);
                proceso.waitForFinished(-1);
            }
        jobIDs.clear();
        }
    }
    return 0;
}

QStringList ejecuta ()
{
    QProcess proceso;
    QStringList param;
    param << "-a";
    proceso.start("tpit", param);
    proceso.waitForFinished(-1);
    QString salida = proceso.readAllStandardOutput();
    QStringList lista;
    QString trab;
    for (int i = 0; i < salida.count(); i++)
    {
        if (salida[i] == '\n')
        {
            if (!consultaExisteJobID(trab)) {
                lista << trab;
            }
            trab.clear();
        }
        else
        {
            trab.append(salida[i]);
        }
    }
    return lista;
}

bool consultaExisteJobID(QString jobID)
{
    QSqlQuery query;
    query.prepare("SELECT (job_id) FROM cups_trabajos WHERE job_id=?");
    query.bindValue(0, jobID);
    query.exec();
    QString job;
    query.addBindValue(job);
    if (query.next()) {
        return true;
    }
    return false;
}

bool conectarMariaDB(QSqlDatabase db)
{
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
