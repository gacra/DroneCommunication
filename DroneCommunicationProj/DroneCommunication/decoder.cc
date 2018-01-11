// Includes class header
#include <decoder.hh>

void Decoder::decode(QString msg, SensorSet *sensorSet) {
    // Searches by the protocol pattern: $A123.0B1234.8C1235.2D123.3
    // and separates the constituent parts

    QChar header = msg.at(0);

    // Confirms the header character
    // and changes the values of the sensor set
    if(header == '$') {
        msg.remove(0, 1);

        QRegularExpression re("\\D\\d+(\\.\\d+)?");
        QRegularExpressionMatchIterator iter = re.globalMatch(msg);

        QRegularExpressionMatch match;
        QString part;
        QChar code;
        float value;
        QHash<QChar, float> sensors;

        while(iter.hasNext()) {
            match = iter.next();
            part = match.captured(0);
            code = part.at(0);
            part.remove(code);
            value = part.toFloat();
            sensors.insert(code, value);
        }

        sensorSet->setMultSensors(sensors);
    }
}
