#include <QCoreApplication>
#include <QString>
#include <QProcess>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 2) {
        std::cout << "Uso: nombreimp puerto_impresora" << endl;
    }
    QProcess proceso;
    QStringList param;
    param << argv[1];
    proceso.start("nomimp", param);
    proceso.waitForFinished(-1);
    QString impresora = proceso.readAllStandardOutput();
    if (!(impresora == "")) {
        impresora = impresora.replace(":", "");
        impresora = impresora.replace("\n","");
        std::cout << impresora.toStdString() << endl;
    } else {
        std::cout << "No encontrado" << endl;
        return 1;
    }
    return 0;
}
