#pragma once

#include <QObject>
#include <QtQml/qqmlregistration.h>

class AppController : public QObject{

    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("wird in main.cpp erzeugt")
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)

public:
    explicit AppController(QObject *parent = nullptr);
    bool running() const;

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

signals:
    void runningChanged();

private:
    void setRunning(bool running);
    bool m_running = false;
};
