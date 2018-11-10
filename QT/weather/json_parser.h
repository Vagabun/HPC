#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "header.h"
#include "weather_info.h"

class json_parser : public QObject
{
    Q_OBJECT
public:
    explicit json_parser(QObject *parent = nullptr);
    weather_info parse(QNetworkReply *reply);

signals:

public slots:
};

#endif // JSON_PARSER_H
