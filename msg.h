#ifndef MSG_H
#define MSG_H
#include <QApplication>
#include <QTcpSocket>

#include "queue_receive.h"
#include "MSG.pb.h"

MSG* receiveMSG(QTcpSocket* socket);
void receiveMSG_to_queue(Queue_receive* queue_receive,QTcpSocket* socket);
int recieveData_fixed_length(char *data, qint64 length_need,QTcpSocket* socket);
void sendMSG(MSG* msg,QTcpSocket* socket);

#endif // MSG_H
