#include "setup.h"
#include "ui_setup.h"


setup::setup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setup)
{
    ui->setupUi(this);
}

setup::~setup()
{
    delete ui;
}

void setup::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked()) {
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->label->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        ui->radioButton_3->setEnabled(true);
        ui->radioButton_4->setEnabled(true);
        if (ui->radioButton_4->isChecked()) {
            ui->label_2->setEnabled(true);
            ui->lineEdit_2->setEnabled(true);
            ui->label_3->setEnabled(true);
            ui->lineEdit_3->setEnabled(true);
        } else {
            ui->label_2->setEnabled(false);
            ui->lineEdit_2->setEnabled(false);
            ui->label_3->setEnabled(false);
            ui->lineEdit_3->setEnabled(false);
        }
        ui->checkBox->setEnabled(true);
    } else {
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        ui->label->setEnabled(false);
        ui->lineEdit->setEnabled(false);
        ui->radioButton_3->setEnabled(false);
        ui->radioButton_4->setEnabled(false);
        ui->label_2->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->label_3->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->checkBox->setEnabled(false);
    }
}

void setup::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked()) {
        ui->label_4->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->label_5->setEnabled(true);
        ui->lineEdit_5->setEnabled(true);
    } else {
        ui->label_4->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->label_5->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
    }
}

void setup::on_radioButton_3_clicked()
{
    ui->label_2->setEnabled(false);
    ui->label_3->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
}

void setup::on_radioButton_4_clicked()
{
    ui->label_2->setEnabled(true);
    ui->label_3->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
}

void setup::on_pushButton_clicked()
{
    if (ui->checkBox_2->isChecked()) {
        popup();
    }
    if (ui->checkBox_3->isChecked()) {
        impresoraDirecta();
    }
    QMessageBox::information(this,"Terminado", "Proceso terminado correctamente");
}

bool setup::popup()
{
    if (ui->lineEdit->text() == "") {
        QMessageBox::information(this,"ERROR", "IP servidor no introducida");
        ui->lineEdit->setFocus();
        return false;
    }
    if (ui->radioButton_4->isChecked()) {
        if (ui->lineEdit_2->text() == "") {
            QMessageBox::information(this,"ERROR", "Introducir nombre de usuario");
            ui->lineEdit_2->setFocus();
            return false;
        }
        if (ui->lineEdit_3->text() == "") {
            QMessageBox::information(this,"ERROR", trUtf8("Introducir contraseña usuario"));
            ui->lineEdit_3->setFocus();
            return false;
        }
    }
    QDir dir;
    if (!dir.exists("/opt/printcontrol")) {
        dir.mkdir("/opt/printcontrol");
    }
    if (!dir.exists("/opt/printcontrol/popup")) {
        dir.mkdir("/opt/printcontrol/popup");
    }
    QFile fich("/opt/printcontrol/popup/config.cfg");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream data(&fich);
        if (ui->radioButton_4->isChecked()) {
            data << "CONFIGURACION" << endl
                 << "=============" << endl << endl
                 << "Servidor: http://" << ui->lineEdit->text() << "/PRINTCONTROL/public/acceso/index/popup" << endl << endl
                 << "Usuario unico: Si" << endl << endl
                 << "Usuario: " << ui->lineEdit_2->text() << endl << endl
                 << "Token: " << ui->lineEdit_3->text() << endl << endl;
        } else {
            data << "CONFIGURACION" << endl
                 << "=============" << endl << endl
                 << "Servidor: http://" << ui->lineEdit->text() << "/PRINTCONTROL/public/acceso/index/popup" << endl << endl
                 << "Usuario unico: No" << endl << endl;
        }
        fich.flush();
        fich.close();
    }
    QProcess exe;
    QString orden;
    if (ui->checkBox->isChecked()) {
        exe.start("cp /tmp/data/minolta /usr/lib/cups/filter/minolta");
        exe.waitForFinished();
        exe.start("chmod 755 /usr/lib/cups/filter/minolta");
        exe.waitForFinished();
        orden = "lpadmin -v smb://";
        orden.append(ui->lineEdit->text());
        orden.append("/printome -p PrinToMe -P /tmp/data/konicalinux.ppd");
        exe.start(orden);
        exe.waitForFinished();
        exe.start("cupsaccept printome");
        exe.waitForFinished();
        exe.start("cupsenable printome");
        exe.waitForFinished();
    }
    fich.setFileName("/etc/cups/ppd/usuario.km");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream data(&fich);
        data << "ACCOUNT_NAME=\"\"" << endl
             << "ACCOUNT_PASSWORD=\"\"" << endl << endl;
        fich.flush();
        fich.close();
    }
    exe.start("chmod 777 /etc/cups/ppd/usuario.km");
    exe.waitForFinished();
    if (ui->radioButton->isChecked()) {
        exe.start("cp /tmp/data/popuplliurex14 /opt/printcontrol/popup/popup2");
        exe.waitForFinished();
    } else {
        exe.start("cp /tmp/data/popup2 /opt/printcontrol/popup/popup2");
        exe.waitForFinished();
    }
    fich.setFileName("/usr/share/applications/popup2.desktop");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream data(&fich);
        data << "[Desktop Entry]" << endl
             << "Version=1.0"  << endl
             << "Name=PrintControl" << endl
             << "Comment=PopUp PrintControl" << endl
             << "Exec=/opt/printcontrol/popup/popup2" << endl
             << "Icon=/opt/printcontrol/popup/oliplus2.ico" << endl
             << "Terminal=false" << endl
             << "Type=Application" << endl << endl;
        fich.flush();
        fich.close();
    }
    exe.start("cp /tmp/data/oliplus2.ico /usr/share/applications/");
    exe.waitForFinished();
    exe.start("chmod 755 /opt/printcontrol/popup/popup2");
    exe.waitForFinished();
    exe.start("cp /tmp/data/oliplus2.ico /opt/printcontrol/popup/oliplus2.ico");
    exe.waitForFinished();
    exe.start("chmod 644 /usr/share/applications/oliplus2.ico");
    exe.waitForFinished();
    exe.start("chmod 644 /opt/printcontrol/popup/oliplus2.ico");
    exe.waitForFinished();
    fich.setFileName("/etc/profile.d/popup.sh");
    if (fich.open(QIODevice::WriteOnly)) {
        QTextStream data(&fich);
        data << "#!/bin/bash" << endl
             << "/opt/printcontrol/popup/popup2 &" << endl << endl;
        fich.flush();
        fich.close();
    }
    exe.start("chmod 755 /etc/profile.d/popup.sh");
    exe.waitForFinished();
    exe.start("/opt/printcontrol/popup/popup2");
    return true;
}

bool setup::impresoraDirecta()
{
    if (ui->lineEdit_4->text() == "") {
        QMessageBox::information(this,"ERROR", "Nombre Impresora no introducido");
        ui->lineEdit_4->setFocus();
        return false;
    }
    if (ui->lineEdit_5->text() == "") {
        QMessageBox::information(this,"ERROR", "Puerto Impresora no introducido");
        ui->lineEdit_5->setFocus();
        return false;
    }
    QProcess exe;
    QString orden;
    exe.start("cp /tmp/data/minolta /usr/lib/cups/filter/minolta");
    exe.waitForFinished();
    exe.start("chmod 755 /usr/lib/cups/filter/minolta");
    exe.waitForFinished();
    orden = "lpadmin -v socket://";
    orden.append(ui->lineEdit_5->text());
    orden.append(" -p ");
    orden.append(ui->lineEdit_4->text());
    orden.append(" -P /tmp/data/konicalinux.ppd");
    exe.start(orden);
    exe.waitForFinished();
    orden.clear();
    orden = "cupsaccept ";
    orden.append(ui->lineEdit_4->text());
    exe.start(orden);
    exe.waitForFinished();
    orden.replace("cupsaccpet ", "cupsenable ");
    exe.start(orden);
    exe.waitForFinished();
    return true;
}
