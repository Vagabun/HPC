#ifndef OUTPUT_HANDLER_H
#define OUTPUT_HANDLER_H

#include "header.h"
#include "weather_info.h"

class output_handler : public QObject
{
    Q_OBJECT
public:
    explicit output_handler(QObject *parent = nullptr);
    void write(weather_info info);

signals:

public slots:
};

#endif // OUTPUT_HANDLER_H
