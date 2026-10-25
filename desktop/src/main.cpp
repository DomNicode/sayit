#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AppController.h"
#include "MockVoiceClient.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("SayIt");
    MockVoiceClient voiceClient;
    AppController controller(&voiceClient);
    QQmlApplicationEngine engine;
    engine.setInitialProperties({{"controller", QVariant::fromValue(&controller)}});
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, [] { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("SayIt", "Main");

    return QGuiApplication::exec();
}