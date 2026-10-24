#pragma once

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "VoiceClient.h"

class AppController : public QObject{

    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("wird in main.cpp erzeugt")
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)
    Q_PROPERTY(bool speaking READ speaking NOTIFY speakingChanged)

public:
    explicit AppController(VoiceClient *voiceClient, QObject *parent = nullptr);
    bool running() const;
    bool speaking() const;

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void runningChanged();
    void speakingChanged();

private:
    void setRunning(bool running);
    void setSpeaking(bool speaking);

    bool m_running = false;
    bool m_speaking = false;
    VoiceClient *m_voiceClient = nullptr;
};
