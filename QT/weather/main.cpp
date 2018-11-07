#include <QCoreApplication>
#include "data_requester.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString api_token = "";
    QString city_id = "";
    data_requester d;
    d.send_request(api_token, city_id);
    //d.test_reply();

    return a.exec();
}
