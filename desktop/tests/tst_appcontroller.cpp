#include <QTest>

#include "AppController.h"
#include "VoiceClient.h"


class FakeVoiceClient : public VoiceClient{
    Q_OBJECT

public:
    using VoiceClient::VoiceClient;

    void connectToRoom() override {connectCalls++;}
    void disconnectFromRoom() override { disconnectCalls++;}

    int connectCalls = 0;
    int disconnectCalls = 0;
};


class TestAppController : public QObject{
    Q_OBJECT

private slots:
    void startsNotRunning();
    void startsSetsRunningandConnects();
    void startTwiceConnectsOnce();
    void stopDisconnects();
    void speakingFollowsVoiceClient();
};

void TestAppController::startsNotRunning(){
    FakeVoiceClient voice;
    AppController controller(&voice);

    QCOMPARE(controller.running(), false);
    QCOMPARE(controller.speaking(), false);
}

void TestAppController::startsSetsRunningandConnects(){
    FakeVoiceClient voice;
    AppController controller(&voice);

    controller.start();

    QCOMPARE(controller.running(), true);
    QCOMPARE(voice.connectCalls, 1);
}

void TestAppController::startTwiceConnectsOnce(){
    FakeVoiceClient voice;
    AppController controller(&voice);

    controller.start();
    controller.start();

    QCOMPARE(voice.connectCalls, 1);
}

void TestAppController::stopDisconnects(){
    FakeVoiceClient voice;
    AppController controller(&voice);

    controller.start();
    controller.stop();

    QCOMPARE(controller.running(), false);
    QCOMPARE(voice.disconnectCalls, 1);
}

void TestAppController::speakingFollowsVoiceClient(){
    FakeVoiceClient voice;
    AppController controller(&voice);

    emit voice.speakingChanged(true);
    QCOMPARE(controller.speaking(), true);

    emit voice.speakingChanged(false);
    QCOMPARE(controller.speaking(), false);
}

QTEST_GUILESS_MAIN(TestAppController);
#include "tst_appcontroller.moc"
