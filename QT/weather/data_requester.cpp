#include "data_requester.h"

data_requester::data_requester(QObject *parent) : QObject(parent) {
    _manager = new QNetworkAccessManager(this);
    connect(_manager, &QNetworkAccessManager::finished,
            this, &data_requester::reply_finished);
}

void data_requester::reply_finished(QNetworkReply *reply) {
    json_parser p;
    output_handler o;
    o.write(p.parse(reply));
    reply->close();
    reply->deleteLater();
    //QCoreApplication::quit();
}

QNetworkRequest data_requester::_create_request(QString &api_token, QString &city_id) {
    QNetworkRequest request;
    QString url = _https_template.arg(_api_host).arg(_api_version).arg(_api_type_of_request).arg(city_id).arg(_api_units).arg(api_token);
    qDebug() << "GET " <<  url;
    request.setUrl(url);
    request.setRawHeader("Content-Type","application/json");
    return request;
}

void data_requester::send_request(QString &api_token, QString &city_id) {
    QNetworkRequest request = _create_request(api_token, city_id);
    _manager->get(request);
}
