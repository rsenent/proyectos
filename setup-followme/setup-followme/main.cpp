#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QProcess>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dir;
    if (!dir.exists("/opt/printcontrol")) {
        dir.mkdir("/opt/printcontrol");
    }
    if (!dir.exists("/opt/printcontrol/apps")) {
        dir.mkdir("/opt/printcontrol/apps");
    }
    QProcess exe;
    exe.start("rm -Rf /opt/printcontrol/apps/setup-printome");
    exe.waitForFinished();
    exe.start("chmod -R 755 /opt/printcontrol/apps");
    exe.waitForFinished();
    QFile fich("/usr/sbin/ci");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream texto(&fich);
        texto << "#!/bin/bash" << endl
              << "lpstat -o | awk '{ print $1}' | grep $1 | cut -d'-' -f1" << endl << endl;
        fich.flush();
        fich.close();
    }
    fich.setFileName("/usr/sbin/tpit");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream texto(&fich);
        texto << "#!/bin/bash" << endl
              << "if [ \"$#\" == 1 ]; then" << endl
              << "      if [ \"$1\" == \"-a\" ]; then" << endl
              << "            lpq -a | awk '{ print $3 }' | sed '1,1d'" << endl
              << "      else" << endl
              << "            lpq -P $1 | awk '{ print $3 }' | sed '1,2d'" << endl
              << "      fi" << endl
              << "else" << endl
              << "      lpq -P $1 $2 | awk '{ print $3 }' | sed '1,2d'" << endl
              << "fi" << endl;
        fich.flush();
        fich.close();
    }
    fich.setFileName("/usr/sbin/nomimp");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream texto(&fich);
        texto << "#!/bin/bash" << endl
              << "lpstat -v | grep $1 | awk '{ print$3 }'" << endl  << endl;
        fich.flush();
        fich.close();
    }
    exe.start("chmod 755 /usr/sbin/nomimp");
    exe.waitForFinished();
    exe.start("chmod 755 /usr/sbin/ci");
    exe.waitForFinished();
    exe.start("chmod 755 /usr/sbin/tpit");
    exe.waitForFinished();
    fich.setFileName("/etc/systemd/system/spd.service");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream texto(&fich);
        texto << "[Unit]" << endl
              << "Description = SPD Service" << endl
              << "After=network.target" << endl << endl
              << "[Service]" << endl
              << "User=root" << endl
              << "Type=simple" << endl << endl
              << "ExecStart=/opt/printcontrol/apps/spd" << endl << endl
              << "Restart=always" << endl << endl
              << "[Install]" << endl
              << "WantedBy=multi-user.target" << endl << endl;
        fich.flush();
        fich.close();
    }
    exe.start("chmod 664 /etc/systemd/system/spd.service");
    exe.waitForFinished();
    exe.start("systemctl enable spd.service");
    exe.waitForFinished();
    exe.start("systemctl daemon-reload");
    exe.waitForFinished();
    exe.start("service spd start");
    exe.waitForFinished();
    return 0;
}
