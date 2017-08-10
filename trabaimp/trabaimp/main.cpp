#include <QCoreApplication>
#include <QProcess>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 3)
    {
        std::cout << "Error, uso trabaimp job-id impresora" << endl;
        return 1;
    }
    else
    {
        QString exe = "lpmove";
        QStringList parametros;
        parametros << argv[1] << argv[2];
        QProcess proceso;
        proceso.start(exe, parametros);
        proceso.waitForFinished(-1);
    }
    return 0;
}
