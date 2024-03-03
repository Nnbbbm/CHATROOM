#include "msg.h"

#include <QTcpSocket>

#include "queue_receive.h"

void sendMSG(MSG* msg,QTcpSocket* socket){
    if(msg->type()==TYPE::CLIENT_QUIT){
        qDebug()<<"client quit!";
    }
    std::string data;
    msg->SerializeToString(&data);
    int length=data.size();

    socket->write((char*)&length,(qint64)sizeof(int));
    socket->write(data.data(),(qint64)length);
}

MSG* receiveMSG(QTcpSocket* socket){
    int datalength=0;
    recieveData_fixed_length((char*)&datalength,(qint64)sizeof(datalength),socket);

    std::string data;
    data.resize(datalength);
    recieveData_fixed_length(data.data(),(qint64)datalength,socket);

    MSG* msg=new MSG();
    msg->ParseFromString(data);
    return msg;
}

void receiveMSG_to_queue(Queue_receive* queue_receive,QTcpSocket* socket){
    queue_receive->add(receiveMSG(socket));
}

int recieveData_fixed_length(char *data, qint64 length_need,QTcpSocket* socket){
    qint64 length_get=0;
    while(length_get<length_need){
        qint64 length_once = socket->read(data+length_get,length_need-length_get);
        if(length_once<=0)
            return length_once;
        length_get+=length_once;
    }
    return length_get;
}
