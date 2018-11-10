#include "output_handler.h"

output_handler::output_handler(QObject *parent) : QObject(parent) { }

void output_handler::write(weather_info info) {
    QFile file("output.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "Error";
        return;
    }
    QTextStream out(&file);
    out << "City: " << info.city_name << endl;
    out << "Temperature: " <<  info.temp << " C" << endl;
    out << "Humidity: " << info.humidity << " %" << endl;
    out << "Pressure: " << info.pressure << endl;
    out << "Weather condition: " << info.weather_desc << endl;
    out << "Speed of wind: " << info.wind_speed << endl << endl;
    file.close();
}
