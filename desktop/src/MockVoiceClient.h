#pragma once

#include <QTimer>
#include "VoiceClient.h"


class MockVoiceClient : public VoiceClient{

    Q_OBJECT

    public:
        explicit MockVoiceClient(QObject *parent = nullptr);
        void connectToRoom() override;
        void disconnectFromRoom() override;

    private:
        void toggleSpeaking();

        QTimer m_timer;
        bool m_speaking = false;
};
