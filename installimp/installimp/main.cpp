#include <QCoreApplication>
#include <QProcess>
#include <QString>
#include <iostream>

using namespace std;

void instalaimpresora(QString p, QString n, QString modo);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 2) {
        std::cout << "Uso: installimp -r nombre_impresora puerto" << endl
                  << "     installimp -v nombre_impresora_virtual" << endl
                  << "     installimp -b nombre_impresora_a_borrar" << endl;
        return 1;
    } else {
        QString nombreImpresora = argv[2];
        nombreImpresora.replace("-","_");
        QString modo = argv[1];
        if ( modo == "-r") {
            QString mod = " -p ";
            instalaimpresora(argv[3], nombreImpresora, mod);
        } else {
            if (modo == "-v") {
                QString nImpresora = nombreImpresora;
                QString mod = " -p ";
                nImpresora.append("-null");
                instalaimpresora("null", nImpresora, mod);
                mod.clear();
                mod = " -c ";

                instalaimpresora(nImpresora, nombreImpresora, mod);
            } else {
                if (modo == "-b") {
                    QProcess proceso;
                    QString exe = "lpadmin -x ";
                    exe.append(nombreImpresora);
                    proceso.start(exe);
                    proceso.waitForFinished(-1);
                } else {
                    std::cout << "Uso2: installimp -r nombre_impresora puerto" << endl
                        << "     installimp -v nombre_impresora_virtual" << endl
                        << "     installimp -b nombre_impresora_a_borrar" << endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void instalaimpresora(QString p, QString n, QString modo)
{
    QProcess proceso;
    QString exe;
    if (modo==" -p ") {
        exe = "lpadmin -v socket://";
    } else {
        exe = "lpadmin -p ";
    }
    exe.append(p);
    exe.append(modo);
    exe.append(n);
    //*****
    std::cout << "Proceso: " << exe.toStdString() << endl;
    //*****
    proceso.start(exe);
    proceso.waitForFinished(-1);
    //*****
    p = proceso.readAllStandardOutput();
    std::cout << "Proceso fin: " << p.toStdString() << endl;
    //*****
    exe = "cupsenable ";
    exe.append(n);
    proceso.start(exe);
    proceso.waitForFinished(-1);
    exe = "cupsaccept ";
    exe.append(n);
    proceso.start(exe);
    proceso.waitForFinished(-1);
}
