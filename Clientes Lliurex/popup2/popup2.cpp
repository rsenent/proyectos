#include "popup2.h"
#include "ui_popup2.h"

using namespace std;


popup2::popup2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::popup2)
{
    ui->setupUi(this);
    ui->label_3->setVisible(false);
    ui->label_3->setOpenExternalLinks(false);
    ui->label_3->setText("");
    if ((leer_dato("Usuario unico: ") == "Si") || (leer_dato("Usuario unico: ") == "si") || (leer_dato("Usuario unico: ") == "SI")) {
        ui->lineEdit->setText(leer_dato("Usuario: "));
        ui->lineEdit_2->setText(leer_dato("Token: "));
        on_pushButton_clicked();
    }
}

void popup2::on_pushButton_clicked()
{
    if (ui->pushButton->text() == "Iniciar sesión") {
        QString datos;
        datos = valida();
        QStringList valores;
        valores << leerDatos(datos);
        //QMessageBox::information(this, "Datos", datos);
        if (valores[0] == "1") {
            actualizaFicheroAutentificacion();
            ui->webView->resize(270,100);
            ui->webView->setVisible(true);
            ui->lineEdit->setVisible(false);
            ui->lineEdit_2->setVisible(false);
            ui->label->setVisible(false);
            ui->label_2->setVisible(false);
            ui->label_4->setVisible(false);
            ui->label_3->setVisible(true);
            ui->label_3->setTextFormat(Qt::RichText);
            ui->label_3->setTextInteractionFlags(Qt::TextBrowserInteraction);
            ui->label_3->setOpenExternalLinks(true);
            QString link = "<a href=\"";
            link.append(valores[3]);
            link.append("\">Ir a Print Control</a>");
            ui->label_3->setText(link);
            ui->pushButton->setText(QString::fromUtf8("Cerrar sesión"));
            ui->webView->load(QUrl(valores[2]));
            ui->webView->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical,Qt::ScrollBarAlwaysOff);
            ui->webView->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal,Qt::ScrollBarAlwaysOff);
        } else {
            QMessageBox::information(this, "Print Control", valores[1]);
        }
    } else {
        actualizaFicheroAutentificacion();
        ui->webView->resize(0,100);
        ui->webView->setVisible(false);
        ui->lineEdit->setVisible(true);
        ui->lineEdit_2->setVisible(true);
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->label_4->setVisible(true);
        ui->label_3->setVisible(false);
        ui->label_3->setOpenExternalLinks(false);
        ui->label_3->setText("");
        ui->pushButton->setText(QString::fromUtf8("Iniciar sesión"));
    }
}

QStringList popup2::leerDatos(QString datos)
{
    QStringList data = datos.split("||**||", QString::SkipEmptyParts);
    return data;
}

void popup2::actualizaFicheroAutentificacion()
{
    QString datos;
    if (ui->pushButton->text() == "Iniciar sesión") {
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

QString popup2::valida()
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
    //if (reply->error())
    return reply->readAll();
}


QString popup2::leer_dato(QString dato)
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

popup2::~popup2()
{
    delete ui;
}

