#ifndef ACCEPT_TASK_H
#define ACCEPT_TASK_H

#include <QTcpSocket>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <string>
#include <QWaitCondition>
#include <QMutexLocker>

#include "queue_receive.h"
#include "MSG.pb.h"
#include "msg.h"

class Accept_task : public QObject
{
    Q_OBJECT
public:
    explicit Accept_task(QObject *parent = nullptr);
    Accept_task(QTcpSocket* socket,Queue_receive* queue)
        :socket_fd(socket),queue_receive(queue)
    {

    }
    void work(){
        connect(socket_fd, &QTcpSocket::readyRead, this, [=]() {
            while(socket_fd->bytesAvailable()>0){
                receiveMSG_to_queue(queue_receive,socket_fd);
            }
        });
    }



private:
    QTcpSocket* socket_fd;
    Queue_receive* queue_receive;


signals:
};




#endif // ACCEPT_TASK_H
