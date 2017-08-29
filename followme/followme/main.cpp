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

bool conectarMariaDB();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 3) {
        std::cout << "Uso: followme usuario ip" << endl;
        return 1;
    }
    QProcess exe;
    exe.start("/opt/printcontrol/apps/trabpend");
    exe.waitForFinished();
    QString jobsid = exe.readAllStandardOutput();
    QString query = "SELECT job_id FROM cups_trabajos WHERE lower(usuario) = lower(\"";
    query.append(argv[1]);
    query.append("\") AND job_id IN (");
    jobsid.replace("[","");
    jobsid.replace("]","");
    jobsid.replace("\n","");
    query.append(jobsid);
    query.append(");");
    QStringList ip;
    ip << argv[2];
    exe.start("/opt/printcontrol/apps/nombreimp", ip);
    exe.waitForFinished();
    QString nombreImpresora = exe.readAllStandardOutput();
    QByteArray error = exe.readAllStandardError();
    nombreImpresora.replace("\n","");
    conectarMariaDB();
    QSqlQuery consulta;
    consulta.exec(query);
    while (consulta.next()) {
        QString job = consulta.value(0).toString();
        ip.clear();
        ip << job << nombreImpresora;
        exe.start("/opt/printcontrol/apps/trabaimp", ip);
        exe.waitForFinished();
    }

    return 0;
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
