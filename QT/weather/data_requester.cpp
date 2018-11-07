#include "data_requester.h"

data_requester::data_requester(QObject *parent) : QObject(parent) {
    _manager = new QNetworkAccessManager(this);
    connect(_manager, &QNetworkAccessManager::finished,
            this, &data_requester::replyFinished);
}

void data_requester::replyFinished(QNetworkReply *reply) {
    if (reply->isFinished())
        parse_reply(reply);
        //qDebug() << reply->readAll();
    reply->close();
    reply->deleteLater();
}

QNetworkRequest data_requester::create_request(QString &api_token, QString &city_id) {
    QNetworkRequest request;
    QString url = https_template.arg(api_host).arg(api_version).arg(api_type_of_request).arg(city_id).arg(api_units).arg(api_token);
    qDebug() << url;
    request.setUrl(url);
    request.setRawHeader("Content-Type","application/json");
    return request;
}

void data_requester::parse_reply(QNetworkReply *reply) {
    QJsonParseError error;
    auto reply_text = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(reply_text, &error);
    qDebug() << json;
}

void data_requester::send_request(QString &api_token, QString &city_id) {
    QNetworkRequest request = create_request(api_token, city_id);
    _manager->get(request);
}

void data_requester::test_reply() {
    QString url = "https://samples.openweathermap.org/data/2.5/weather?id=2172797&appid=b6907d289e10d714a6e88b30761fae22";
    _manager->get(QNetworkRequest(QUrl(url)));
}
