#ifndef QUEUE_RECEIVE_H
#define QUEUE_RECEIVE_H

#include <QMutex>
#include <QList>
#include <QWaitCondition>
#include <QThread>

#include "MSG.pb.h"
class Queue_receive
{
public:
    Queue_receive(){

    }

    ~Queue_receive(){
        QMutexLocker locker(&mutex);
        qDeleteAll(list); // 释放指针指向的对象
        list.clear(); // 清空列表
    }

    void add(MSG* msg){//accept_task use add() to wake deal_task
        QMutexLocker locker(&mutex);
        list.append(msg);
        condition_list.wakeOne();
    }

    MSG* pop_first(){//deal_task will sleep until accept_task add()
        QMutexLocker locker(&mutex);
        if(list.isEmpty()){
            condition_list.wait(&mutex);
            return nullptr;
        }
        MSG* msg=list.first();
        list.removeFirst();

        return msg;
    }
    bool isEmpty(){
        QMutexLocker locker(&mutex);
        return list.isEmpty();
    }

    int size(){
        QMutexLocker locker(&mutex);
        return list.size();
    }

    void wakeAll(){
        condition_list.wakeAll();
    }

private:
    QMutex mutex;
    QWaitCondition condition_list;
    QList<MSG*> list;

};

#endif // QUEUE_RECEIVE_H
