#ifndef DATA_REQUESTER_H
#define DATA_REQUESTER_H

#include "header.h"
#include "json_parser.h"
#include "output_handler.h"

class data_requester : public QObject {
    Q_OBJECT
public:
    explicit data_requester(QObject *parent = nullptr);
    void send_request(QString &api_token, QString &city_id);
signals:
public slots:
    void reply_finished(QNetworkReply *reply);
private:
    QNetworkAccessManager *_manager;
    const QString _api_host = "api.openweathermap.org";
    const QString _api_version = "data/2.5";
    const QString _api_type_of_request = "weather";
    const QString _api_units = "metric";
    const QString _https_template = "https://%1/%2/%3?id=%4&units=%5&appid=%6";
    QNetworkRequest _create_request(QString &api_token, QString &city_id);
};

#endif // DATA_REQUESTER_H
