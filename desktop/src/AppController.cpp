#include "AppController.h"

AppController::AppController(QObject *parent)
    : QObject(parent)
{

}

bool AppController::running() const {
    return m_running;
}

void AppController::stop(){
    setRunning(false);
}

void AppController::start(){
    setRunning(true);
}


void AppController::setRunning(bool running){
    if(m_running == running){
        return;
    }

    m_running = running;
    emit runningChanged();
}