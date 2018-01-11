#ifndef RECEIVER_H
#define RECEIVER_H

// Includes Qt libraries
#include <QObject>
#include <QUdpSocket>

// Includes SensorSet class
#include <sensorset.hh>

/*!
 * \brief UDP server receiving the drone messages
 */
class Receiver : public QObject {
    Q_OBJECT

private:

    QUdpSocket *_socket;     // UDP socket
    SensorSet  *_sensorSet;  // Set of drone sensors

public:

    /*!
     * \brief Receiver constructor
     * \param sensorSet Set of drone sensors
     */
    explicit Receiver(SensorSet *sensorSet, QObject *parent = 0);

    ~Receiver();

public slots:

    /*!
     * \brief Called when a datagram arrives
     */
    void readRedy();
};

#endif // RECEIVER_H
