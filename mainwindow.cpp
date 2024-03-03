#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
#include <QCloseEvent>
#include <string>
#include <QTimer>

#include "accept_task.h"
#include "queue_receive.h"
#include "deal_task.h"
#include "msg.h"
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent,QTcpSocket* sock,QString name)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,socket(sock)
    ,username(name)
{
    ui->setupUi(this);
    ui->leave_room->setEnabled(false);
    setWindowTitle("Welcome "+username+ " !");
    ui->message_edit->setEnabled(false);
    ui->send->setEnabled(false);
    connect(ui->message_edit,&QLineEdit::returnPressed,[=](){
        ui->send->clicked();
    });
    connect(ui->send,&QPushButton::clicked,[=](){
        ui->message_edit->clear();
    });



    isConnect=true;
    queue_receive=new Queue_receive();
    queue_send=new Queue_send();

    thread_accept=new QThread;
    for(int i=0;i<deal_num;i++){
        thread_deal[i]=new QThread;
    }

    accept_task=new Accept_task(socket,queue_receive);
    accept_task->moveToThread(thread_accept);
    connect(thread_accept,&QThread::started,accept_task,&Accept_task::work);
    thread_accept->start();

    for(int i=0;i<deal_num;i++){
        deal_task[i]=new Deal_task(queue_receive);
        deal_task[i]->moveToThread(thread_deal[i]);
        connect(deal_task[i],&Deal_task::SERVER_HINT,this,[=](QString s){
            statusBar()->showMessage(s);
        });
        connect(deal_task[i],&Deal_task::TEXT_DATA,this,[=](QString s){

            ui->message_all->addItem(s);
        });
        connect(deal_task[i],&Deal_task::ROOM_NUM,this,[=](QString s){
            if(isEnterRoom)
                return;
            ui->rooms->clear();
            QStringList qstringList=s.split("|");

            QString s_temp;
            int i=0;
            for(QString s_for:qstringList){

                if(i==2){
                    ui->rooms->addItem(s_temp);
                    i=0;
                    s_temp.clear();
                }

                if(i==0){
                    s_temp+="Room: ";
                    if(s_for!="")
                        set_rooms.insert(s_for);
                }

                if(i==1){
                    s_temp+="    people: ";
                }
                s_temp+=s_for;
                i++;
            }
        });
        connect(deal_task[i],&Deal_task::ROOM_NAMES,this,[=](QString s){
            ui->rooms->clear();
            QStringList qstringList=s.split("|");
            for(QString temp:qstringList){
                if(temp=="")
                    return;
                ui->rooms->addItem(temp);
            }
        });
    }

    for(int i=0;i<deal_num;i++){
        connect(thread_deal[i],&QThread::started,deal_task[i],&Deal_task::work);
        thread_deal[i]->start();
    }

    QTimer* timer = new QTimer(this);

    timer->setSingleShot(true);
    timer->setInterval(100);

    connect(timer, &QTimer::timeout, this, &MainWindow::check_room);

    timer->start();
}
MainWindow::~MainWindow()
{
    destroy();
    delete ui;
}


void MainWindow::on_disconnect_clicked()
{

    if(socket){
        MSG* msg=new MSG();
        msg->set_type(TYPE::CLIENT_QUIT);
        sendMSG(msg,socket);
        delete msg;
    }

    destroy();
    this->close();
}


void MainWindow::on_send_clicked()
{
    if(ui->message_edit->text()=="")
        return;
    MSG* msg=new MSG();
    msg->set_type(TYPE::TEXT_DATA);
    QString s(ui->message_edit->text());
    msg->set_data(s.toLatin1());
    msg->set_from(username.toLatin1());
    sendMSG(msg,socket);
    delete msg;
}



void MainWindow::on_enter_room_clicked()
{
    if(set_rooms.find(ui->room_num->text())==set_rooms.end()){
        QMessageBox::warning(nullptr, "wrong", "wrong room number！", QMessageBox::Ok);
        return;
    }

    isEnterRoom=true;
    ui->rooms->clear();
    ui->enter_room->setEnabled(false);
    ui->leave_room->setEnabled(true);
    ui->message_edit->setEnabled(true);
    ui->send->setEnabled(true);
    ui->room_num->setEnabled(false);


    MSG* msg=new MSG();
    msg->set_type(TYPE::CLIENT_ENTER_ROOM);
    QString s(ui->room_num->text());

    msg->set_data(s.toLatin1());
    msg->set_from(username.toLatin1());
    sendMSG(msg,socket);
    delete msg;



}


void MainWindow::on_leave_room_clicked()
{
    isEnterRoom=false;
    ui->message_all->clear();
    ui->enter_room->setEnabled(true);
    ui->leave_room->setEnabled(false);
    ui->message_edit->setEnabled(false);
    ui->send->setEnabled(false);
    ui->room_num->setEnabled(true);


    check_room();

    MSG* msg=new MSG();
    msg->set_type(TYPE::CLIENT_LEAVE_ROOM);
    msg->set_from(username.toLatin1());
    sendMSG(msg,socket);
    delete msg;

}




void MainWindow::destroy(){
    if(thread_accept){
        thread_accept->quit();
        thread_accept->wait();
        thread_accept->deleteLater();
        thread_accept=nullptr;
    }
    for(int i=0;i<deal_num;i++){
        if(thread_deal[i]){
            thread_deal[i]->quit();
            deal_task[i]->running=false;
            queue_receive->wakeAll();
            thread_deal[i]->wait();
            thread_deal[i]->deleteLater();
            thread_deal[i]=nullptr;
        }
    }


    if(socket){
        socket->close();
        socket->deleteLater();
        socket=nullptr;
    }

    if(accept_task){
        accept_task->deleteLater();
        accept_task=nullptr;
    }

    for(int i=0;i<deal_num;i++){
        if(deal_task[i]){
            deal_task[i]->deleteLater();
            deal_task[i]=nullptr;
        }
    }


    if(queue_receive){
        delete queue_receive;
        queue_receive=nullptr;
    }

    if(queue_send){
        delete queue_send;
        queue_send=nullptr;
    }
}





void MainWindow::check_room()
{
    MSG* msg=new MSG;
    msg->set_type(TYPE::ROOM_NUM);
    sendMSG(msg,socket);
    delete msg;
}

