#ifndef PRINTER_H
#define PRINTER_H

// Include Qt library
#include <QtCore>

// Include SensorSet class
#include <sensorset.hh>

/*!
 * \brief Print on the terminal the values of the sensors with 10Hz frequency
 */
class Printer : public QObject {
    Q_OBJECT

private:

    QTimer     _timer;      // Timer to get the desired frequency
    SensorSet *_sensorSet;  // Set of drone sensors

public:

    /*!
     * \brief Printer constructor
     * \param sensorSet Set of drone sensors
     */
    explicit Printer(SensorSet *sensorSet, QObject *parent = 0);

    ~Printer();

    /*!
     * \brief Starts printing the values of the sensors with 10Hz frequency
     */
    void startPrinting();

public slots:

    /*!
     * \brief When called, prints sensor set values
     */
    void printSensors();
};

#endif // PRINTER_H
