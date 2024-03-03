#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QMutex>
#include <QTcpSocket>
#include <QCloseEvent>
#include <QApplication>

#include "MSG.pb.h"
#include "queue_send.h"
#include "queue_receive.h"
#include "accept_task.h"
#include "deal_task.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,QTcpSocket* sock=nullptr,QString name="");
    ~MainWindow();

    void check_room();


private slots:

    void on_send_clicked();

    void on_enter_room_clicked();


    void on_leave_room_clicked();

    void on_disconnect_clicked();











private:
    Ui::MainWindow *ui;


    QTcpSocket* socket=nullptr;

    Queue_send* queue_send=nullptr;
    Queue_receive* queue_receive=nullptr;

    QThread* thread_accept=nullptr;
    // QThread* thread_deal=nullptr;

    Accept_task* accept_task=nullptr;
    // Deal_task* deal_task=nullptr;

    int deal_num=5;
    Deal_task* deal_task[5];//size of arr is deal_num
    QThread* thread_deal[5];//size of arr is deal_num

    QString username;

    QSet<QString> set_rooms;

    bool isConnect=false;
    bool isEnterRoom=false;

    void destroy();

signals:
    void dis_connect();
};
#endif // MAINWINDOW_H
