#ifndef SENSORSET_H
#define SENSORSET_H

// Includes Qt library
#include <QtCore>

/*!
 * \brief Set of drone sensors (Stores its values)
 */
class SensorSet {

private:

    float _airspeed;    // Airspeed
    float _altitude;    // Barometric Altitude
    float _latitude;    // Position Latitude
    float _longitude;   // Position Longitude

private:

    QMutex _mutex;

public:

    SensorSet();

    // Getters
    float getAirspeed();
    float getAltitude();
    float getLatitude();
    float getLongitude();

    /*!
     * \brief Sets the values of multiple sensors based on their codes
     * \param sensors Hash containing the sensor code and its value
     */
    void setMultSensors(QHash<QChar, float> sensors);

    /*!
     * \brief Transforms sensor values into a string for printing
     * \return String for printing
     */
    QString toString();

private:

    // Setters
    void setAirspeed(float airspeed);
    void setAltitude(float altitude);
    void setLatitude(float latitude);
    void setLongitude(float longitude);

    /*!
     * \brief Sets sensor value based in its code
     * \param code Sensor code (A, B, C or D)
     * \param value Value that sensor will receive
     */
    void setSensor(QChar code, float value);
};

#endif // SENSORSET_H
