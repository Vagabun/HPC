#ifndef DATA_REQUESTER_H
#define DATA_REQUESTER_H

#include <QObject>

class data_requester : public QObject
{
    Q_OBJECT
public:
    explicit data_requester(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATA_REQUESTER_H