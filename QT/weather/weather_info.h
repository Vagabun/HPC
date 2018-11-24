#ifndef WEATHER_INFO_H
#define WEATHER_INFO_H

#include "header.h"

struct weather_info {
    QString city_name;
    QString weather_desc;
    QString temp;
    QString pressure;
    QString humidity;
    QString wind_speed;
};

#endif // WEATHER_INFO_H
