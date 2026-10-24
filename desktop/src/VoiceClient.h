#pragma once

#include <QObject>


class VoiceClient : public QObject{

    Q_OBJECT

public:
    using QObject::QObject;
    ~VoiceClient() override = default;

    virtual void connectToRoom() = 0;
    virtual void disconnectFromRoom() = 0;

signals:
    void speakingChanged(bool speaking);

};
