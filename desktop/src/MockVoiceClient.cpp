#include "MockVoiceClient.h"

MockVoiceClient::MockVoiceClient(QObject *parent)
    :VoiceClient(parent)
{
    m_timer.setInterval(2000);
    connect(&m_timer, &QTimer::timeout, this, &MockVoiceClient::toggleSpeaking);

}

void MockVoiceClient::connectToRoom(){
    m_timer.start();
}

void MockVoiceClient::disconnectFromRoom(){
    m_timer.stop();

    if(m_speaking){
        m_speaking = false;
        emit speakingChanged(false);
    }
}

void MockVoiceClient::toggleSpeaking(){
    m_speaking = !m_speaking;
    emit speakingChanged(m_speaking);
}