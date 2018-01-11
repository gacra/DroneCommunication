// Includes class header
#include <sensorset.hh>

SensorSet::SensorSet() {
    //Indicates that initially no value was setted
    _airspeed = std::numeric_limits<float>::quiet_NaN();
    _altitude = std::numeric_limits<float>::quiet_NaN();
    _latitude = std::numeric_limits<float>::quiet_NaN();
    _longitude = std::numeric_limits<float>::quiet_NaN();
}

float SensorSet::getAirspeed() {
    QMutexLocker locker(&_mutex);
    return _airspeed;
}

float SensorSet::getAltitude() {
    QMutexLocker locker(&_mutex);
    return _altitude;
}

float SensorSet::getLatitude() {
    QMutexLocker locker(&_mutex);
    return _latitude;
}

float SensorSet::getLongitude() {
    QMutexLocker locker(&_mutex);
    return _longitude;
}

void SensorSet::setMultSensors(QHash<QChar, float> sensors) {
    QHashIterator<QChar, float> iter(sensors);

    // The sensorSet is locked to make sure that all sensors
    // are updated before a reading is performed
    QMutexLocker locker(&_mutex);

    while(iter.hasNext()) {
        iter.next();
        setSensor(iter.key(), iter.value());
    }
}

QString SensorSet::toString() {
    QString text;

    // The sensorSet is locked to avoid printing a state
    // where only a few sensors have been updated
    QMutexLocker locker(&_mutex);

    text += "Airspeed:  "  + QString::number(_airspeed)  + "\n";
    text += "Altitude:  "  + QString::number(_altitude)  + "\n";
    text += "Latitude:  "  + QString::number(_latitude)  + "\n";
    text += "Longitude: "  + QString::number(_longitude) + "\n";

    return text;
}

void SensorSet::setAirspeed(float airspeed) {
    _airspeed = airspeed;
}

void SensorSet::setAltitude(float altitude) {
    _altitude = altitude;
}

void SensorSet::setLatitude(float latitude) {
    _latitude = latitude;
}

void SensorSet::setLongitude(float longitude) {
    _longitude = longitude;
}

void SensorSet::setSensor(QChar code, float value) {
    switch (code.unicode()) {
    case 'A':
        setAirspeed(value);
        break;
    case 'B':
        setAltitude(value);
        break;
    case 'C':
        setLatitude(value);
        break;
    case 'D':
        setLongitude(value);
        break;
    default:
        break;
    }
}
