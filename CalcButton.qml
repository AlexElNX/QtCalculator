import QtQuick
import QtQuick.Controls

Button {
    id: btn
    width: 80
    height: 50
    hoverEnabled: true

    contentItem: Rectangle {
        anchors.fill: parent
        color:  btn.hovered && btnText.text === "=" ? "#E93FB7" :
                btnText.text === "=" ? "#FF43C8" :
                btn.down ? "#212024" :
                btn.hovered ? "#28272b" :
                "#333137"

        radius: 5

        Text{
            id: btnText
            text: parent.parent.text
            color: btnText.text === "=" ? "black" : "white"
            font.pixelSize: 18;
            anchors.centerIn: parent
        }
    }

    onClicked: {

    }
}