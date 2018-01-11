#ifndef SENDER_H
#define SENDER_H

#include <QObject>
#include <QUdpSocket>

/*!
 * \brief Simulates drone sending messages
 */
class Sender : public QObject {
    Q_OBJECT

private:

    QUdpSocket *_socket;    //UDP Socket

public:

    explicit Sender(QObject *parent = 0);

    /*!
     * \brief Send a message to DroneCommunication
     * \param str Message to be sent
     */
    void sendMessage(QString str);
};

#endif // SENDER_H
