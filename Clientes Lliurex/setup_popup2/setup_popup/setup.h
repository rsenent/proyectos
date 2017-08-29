#ifndef SETUP_H
#define SETUP_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include <QProcess>

namespace Ui {
class setup;
}

class setup : public QMainWindow
{
    Q_OBJECT

public:
    explicit setup(QWidget *parent = 0);
    ~setup();

private slots:
    void on_pushButton_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();
    void on_checkBox_2_clicked();
    void on_checkBox_3_clicked();
    bool popup();
    bool impresoraDirecta();

private:
    Ui::setup *ui;
};

#endif // SETUP_H
