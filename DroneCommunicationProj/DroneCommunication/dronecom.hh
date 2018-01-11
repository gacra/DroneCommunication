#ifndef DRONECOM_H
#define DRONECOM_H

// Includes all other classes
#include <sensorset.hh>
#include <receiver.hh>
#include <printer.hh>

/*!
 * \brief Represents the Drone Communication application
 */
class DroneCom {

private:

    SensorSet *_sensorSet;      // Set of drone sensors (stores its values)
    Receiver  *_receiver;       // UDP server receiving the drone messages
    Printer   *_printer;        // Print on the terminal the values of the sensors

    QThread *_printerThread;    // Thread for the Printer object
    QThread *_receiverThread;   // Thread for the Receiver object

public:

    /*!
     * \brief Creates the application modules and starts them (in their respective threads)
     */
    DroneCom();

    ~DroneCom();
};

#endif // DRONECOM_H
