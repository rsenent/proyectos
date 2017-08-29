#include <QCoreApplication>
#include <QProcess>
#include <QString>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 4) {
        std::cout << "Uso: installimp -r nombre_impresora puerto" << endl
                  << "     installimp -v nombre_impresora_virtual impresora_real"
                  << endl;
        return 1;
    } else {
        if ( argv[1] == "-r") {
            QProcess proceso;
            QString exe = "lpadmin -h ";
            exe.append(argv[3]);
            exe.append(" -p ");
            exe.append(argv[2]);
            proceso.start(exe);
            proceso.waitForFinished(-1);
            exe = "cupsenable ";
            exe.append(argv[2]);
            proceso.start(exe);
            proceso.waitForFinished(-1);
        } else {
            QProcess proceso;
            QString exe = "lpadmin -p ";
            exe.append(argv[3]);
            exe.append(" -c ");
            exe.append(argv[2]);
            proceso.start(exe);
            proceso.waitForFinished(-1);
        }
    }
    return 0;
}
