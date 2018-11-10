#include "json_parser.h"

json_parser::json_parser(QObject *parent) : QObject(parent) { }

weather_info json_parser::parse(QNetworkReply *reply) {
    weather_info info;
    auto reply_text = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(reply_text);
    info.city_name = json["name"].toString();
    info.humidity = QString::number(json["main"]["humidity"].toDouble());
    info.temp = QString::number(json["main"]["temp"].toDouble());
    info.weather_desc = json["weather"][0]["description"].toString();
    info.pressure = QString::number(json["main"]["pressure"].toDouble());
    info.wind_speed = QString::number(json["wind"]["speed"].toDouble());

    return info;
}
