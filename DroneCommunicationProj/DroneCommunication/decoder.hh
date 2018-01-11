#ifndef DECODER_H
#define DECODER_H

// Includes Qt library
#include <QtCore>

// Includes SensorSet class
#include <sensorset.hh>

/*!
 * \brief Static class that decodes the message received from the drone
 */
class Decoder {

public:

    /*!
     * \brief Decodes the message received from the drone
     * \param msg Message received
     * \param sensorSet Set of drone sensors that will be changed
     */
    static void decode(QString msg, SensorSet *sensorSet);
};

#endif // DECODER_H
