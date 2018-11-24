#include "data_requester.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString api_token = "";
    data_requester d;

    QFile inputFile("input.txt");
    if (inputFile.open(QIODevice::ReadOnly)) {
       QTextStream in(&inputFile);
       while (!in.atEnd()) {
          QString id = in.readLine();
          d.send_request(api_token, id);
       }
       inputFile.close();
    }

    return a.exec();
}
