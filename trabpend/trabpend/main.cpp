#include <QCoreApplication>
#include <iostream>
#include <QProcess>
#include <QString>
#include <QJsonArray>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QJsonArray>

using namespace std;

void ejecuta(QStringList param);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //if (argc < 2) {
    //    std::cout << "Error, uso trabpend nombre_impresora [usuario]" << endl;
    //    return 1;
    //} else {
        QStringList parametros;
        parametros << argv[1];
        if (argc > 2)
        {
           parametros << argv[2];
        }
        ejecuta(parametros);
    //}
}

void ejecuta (QStringList param)
{
    QProcess proceso;
    proceso.start("tpit -a");
    proceso.waitForFinished(-1);
    QString salida = proceso.readAllStandardOutput();
    QStringList lista;
    QString trab;
    std::cout << "[";
    for (int i = 0; i < salida.count(); i++)
    {
        if (salida[i] == '\n')
        {
            lista << trab;
            if ((i + 1) < salida.count()) {
                std::cout << trab.toStdString() << ", ";
            } else {
                std::cout << trab.toStdString() << "]" << endl;
            }
            trab.clear();
        }
        else
        {
            trab.append(salida[i]);
        }
    }
}
