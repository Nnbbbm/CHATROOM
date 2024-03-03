#include <QHostAddress>
#include <QMessageBox>

#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "msg.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_login_clicked()
{
    socket=new QTcpSocket(this);

    quint16 port=12345;
    socket->connectToHost(QHostAddress("192.168.88.131"),port);

    connect(socket,&QTcpSocket::connected,[=](){
        MSG* msg=new MSG();
        msg->set_type(TYPE::CLIENT_LOGIN);
        QString s=ui->username->text()+"|"+ui->password->text();
        msg->set_data(s.toLatin1());
        sendMSG(msg,socket);

        connect(socket,&QTcpSocket::readyRead,[=](){
            while(socket->bytesAvailable()>0){
                MSG* msg=receiveMSG(socket);
                if(msg->type()==TYPE::CLIENT_LOGIN_YES){
                    username=ui->username->text();
                    disconnect(socket,nullptr,nullptr,nullptr);
                    accept();
                }else if(msg->type()==TYPE::CLIENT_LOGIN_NO){
                    MSG* msg1=new MSG;
                    msg1->set_type(TYPE::CLIENT_QUIT);
                    sendMSG(msg1,socket);

                    socket->close();
                    socket->deleteLater();

                    QMessageBox::warning(nullptr, "wrong", QString::fromStdString(msg->data()), QMessageBox::Ok);

                    ui->username->clear();
                    ui->password->clear();
                }else{
                    qDebug()<<"type:"<<msg->type();
                }
                delete msg;
            }
        });


    });




}

