import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: window
    width: 300
    height: 400
    visible: true
    title: qsTr("SayIt")
    color: "#1f1f1f"

    required property AppController controller

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 16

        Label {
            text: !window.controller.running ? qsTr("Bereit") : window.controller.speaking ?
                                                   qsTr("Agent spricht ...")
                                                 : qsTr("Agent hört zu ...")
            color: "#e0e0e0"
            font.pixelSize: 20
            Layout.alignment: Qt.AlignHCenter
        }

        Rectangle {
            Layout.preferredWidth: 160
            Layout.preferredHeight: 160
            Layout.alignment: Qt.AlignHCenter
            radius: width / 2
            color: !window.controller.running ? "#3d6fd6" : window.controller.speaking ?
                                                    "#e0a030"
                                                  : "#2e9e6b"
            Behavior on color { ColorAnimation { duration: 250 } }
            scale: window.controller.speaking ? 1.1 : 1.0
            Behavior on scale { NumberAnimation { duration: 250 } }
        }

        Button {
            text: window.controller.running ? qsTr("Stop") : qsTr("Start")
            Layout.alignment: Qt.AlignHCenter
            onClicked: window.controller.running ? window.controller.stop() : window.controller.start()
        }
    }
}