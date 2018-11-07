#ifndef DATA_REQUESTER_H
#define DATA_REQUESTER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>

class data_requester : public QObject {
    Q_OBJECT
public:
    explicit data_requester(QObject *parent = nullptr);
    void test_reply();
    void send_request(QString &api_token, QString &city_id);
signals:

public slots:
    void replyFinished(QNetworkReply *reply);
private:
    QNetworkAccessManager *_manager;
    const QString api_host = "api.openweathermap.org";
    const QString api_version = "data/2.5";
    const QString api_type_of_request = "weather";
    const QString api_units = "metric";
    const QString https_template = "https://%1/%2/%3?id=%4&units=%5&appid=%6";
    QNetworkRequest create_request(QString &api_token, QString &city_id);
    void parse_reply(QNetworkReply *reply);
};

#endif // DATA_REQUESTER_H
