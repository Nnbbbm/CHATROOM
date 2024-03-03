#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QTcpSocket* socket=nullptr;
    QString username;

private slots:
    void on_login_clicked();

private:
    Ui::Dialog *ui;


signals:

};

#endif // DIALOG_H
