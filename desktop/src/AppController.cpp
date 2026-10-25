#include "AppController.h"

AppController::AppController(VoiceClient *voiceClient, QObject *parent)
    : QObject(parent)
    , m_voiceClient(voiceClient)
{
    connect(m_voiceClient, &VoiceClient::speakingChanged, this, &AppController::setSpeaking);
}

bool AppController::running() const {
    return m_running;
}

bool AppController::speaking() const{
    return m_speaking;
}

void AppController::stop(){

    if(!m_running){
        return;
    }

    setRunning(false);
    m_voiceClient->disconnectFromRoom();
}

void AppController::start(){

    if(m_running){
        return;
    }
    setRunning(true);
    m_voiceClient->connectToRoom();
}


void AppController::setRunning(bool running){
    if(m_running == running){
        return;
    }

    m_running = running;
    emit runningChanged();
}


void AppController::setSpeaking(bool speaking){
    if(m_speaking == speaking){
        return;
    }

    m_speaking = speaking;
    emit speakingChanged();
}