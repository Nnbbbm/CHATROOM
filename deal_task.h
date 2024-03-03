#ifndef DEAL_TASK_H
#define DEAL_TASK_H

#include <QObject>
#include <QTcpSocket>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>

#include "queue_receive.h"
#include "MSG.pb.h"
class Deal_task : public QObject
{
    Q_OBJECT
public:
    explicit Deal_task(QObject *parent = nullptr);

    Deal_task(Queue_receive* queue)
        :queue_receive(queue)
    {

    }
    void work(){
        qDebug()<<"deal_task working!: "<<QThread::currentThreadId();
        while(running){
            MSG* msg=queue_receive->pop_first();
            if(msg==nullptr){
                continue;
            }

            QString s=QString::fromStdString(msg->data());
            QString username;
            switch (msg->type()) {
            case TYPE::TEXT_DATA:
                username=QString::fromStdString(msg->from());
                emit TEXT_DATA(username+" : "+s);
                break;
            case TYPE::SERVER_HINT:
                emit SERVER_HINT(s);
                break;
            case TYPE::ROOM_NUM:
                emit ROOM_NUM(s);
                break;
            case TYPE::ROOM_NAMES:
                emit ROOM_NAMES(s);
                break;
            }

            delete msg;
        }
    }


    bool running=true;
private:
    Queue_receive* queue_receive;


signals:
    void SERVER_HINT(QString s);
    void TEXT_DATA(QString s);
    void ROOM_NUM(QString s);
    void ROOM_NAMES(QString s);
};

#endif // DEAL_TASK_H
