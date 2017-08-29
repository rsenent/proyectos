#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::popup)
{
    ui->setupUi(this);
    login(false,"","");
    connect(ui->lineEdit, SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));
    connect(ui->lineEdit_2, SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));
    ui->lineEdit->setFocus();
    if ((leer_dato("Usuario unico: ") == "Si") || (leer_dato("Usuario unico: ") == "si") || (leer_dato("Usuario unico: ") == "SI")) {
        ui->lineEdit->setText(leer_dato("Usuario: "));
        ui->lineEdit_2->setText(leer_dato("Token: "));
        on_pushButton_clicked();
    }
}

popup::~popup()
{
    delete ui;
}

void popup::closeEvent(QCloseEvent *)
{
    vaciaUsuarioKM();
}

void popup::vaciaUsuarioKM()
{
    QFile exit("/etc/cups/ppd/usuario.km");
    if (exit.open(QIODevice::WriteOnly))
    {
        QTextStream datos(&exit);

        datos << "ACCOUNT_NAME=\"\"" << endl
              << "ACCOUNT_PASSWORD=\"\"" << endl << endl;
        exit.flush();
    }
    exit.close();
}

void popup::on_pushButton_clicked()
{
    if (ui->label_3->text() == "Identifiquese para imprimir") {
        QStringList valores;
        valores << leerDatos(valida());
        if (valores[0]  == "1") {
            actualizaFicheroAutentificacion(true);
            login(true,valores[1],valores[4]);
        } else {
            QMessageBox::information(this, "Print Control", valores[1]);
        }
    } else {
        vaciaUsuarioKM();
        login(false,"","");
    }
}

void popup::on_pushButton_2_clicked()
{
    QStringList valores;
    valores << leerDatos(valida());
    if (valores[0]  == "1") {
        actualizaFicheroAutentificacion(true);
        login(true,valores[1],valores[4]);
    } else {
       QMessageBox::information(this, "Print Control", "Error usuario no encontrado");
    }
}

void popup::login(bool on, QString nombre, QString saldo)
{
    if (on) {
        ui->label_3->setText("Usuario logueado:");
        QString format = "<font color='blue'>%1</font>";
        ui->label_4->setText(format.arg(nombre));
        format = "<font color='green'>%1</font>";
        ui->label_5->setText(format.arg(saldo));
        ui->groupBox->setVisible(false);
        ui->groupBox_2->setVisible(true);
        ui->pushButton->setText(trUtf8("Cerrar sesión"));
    } else {
        ui->label_3->setText("Identifiquese para imprimir");
        ui->groupBox->setVisible(true);
        ui->lineEdit->setText("");
        ui->lineEdit->setFocus();
        ui->lineEdit_2->setText("");
        ui->groupBox_2->setVisible(false);
        ui->pushButton->setText(trUtf8("Iniciar sesión"));
    }
}

QStringList popup::leerDatos(QString datos)
{
    QStringList data = datos.split("||**||", QString::SkipEmptyParts);
    return data;
}

void popup::actualizaFicheroAutentificacion(bool on)
{
    QString datos;
    if (on) {
        datos = "echo 'ACCOUNT_NAME=\"";
        datos.append(ui->lineEdit->text());
        datos.append("\"' > /etc/cups/ppd/usuario.km");
        system(datos.toStdString().c_str());
        datos.clear();
        datos = "echo 'ACCOUNT_PASSWORD=\"";
        datos.append(ui->lineEdit_2->text());
        datos.append("\"' >> /etc/cups/ppd/usuario.km");
        system(datos.toStdString().c_str());
    } else {
        system("echo 'ACCOUNT_NAME=\"\"' > /etc/cups/ppd/usuario.km");
        system("echo 'ACCOUNT_PASSWORD=\"\"' >> /etc/cups/ppd/usuario.km");
    }
}

QString popup::valida()
{
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QByteArray data;
    data.append("usuario=");
    data.append(ui->lineEdit->text());
    data.append("&pass=");
    QByteArray pass;
    pass.append(ui->lineEdit_2->text());
    QCryptographicHash *encrypt = new QCryptographicHash(QCryptographicHash::Sha1);
    encrypt->addData(pass);
    QString passencript;
    passencript = encrypt->result().toBase64();
    data.append(passencript);
    QString servidor = leer_dato("Servidor: ");
    //QMessageBox::information(this, "Url", servidor);
    QUrl serverUrl;
    serverUrl.setUrl(servidor);
    QNetworkRequest req(serverUrl);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = mgr.post(req,data);
    eventLoop.exec();
    //QMessageBox::information(this, "Url", servidor);
    //if (reply->error())
    return reply->readAll();
}


QString popup::leer_dato(QString dato)
{
    QFile conf("/opt/printcontrol/popup/config.cfg");
    QString ret;
    if (conf.open(QIODevice::ReadOnly)) {
        QString linea;
        while (!conf.atEnd()) {
            linea = conf.readLine();
            if (linea.startsWith(dato)) {
                linea = linea.replace(dato,"");
                ret = linea.replace("\n","");
            }
        }
    }
    conf.close();
    return ret;
}

