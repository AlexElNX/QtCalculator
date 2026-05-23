import QtQuick
import QtQuick.Controls

Window {
    maximumHeight: 500
    maximumWidth: 330

    minimumHeight: 500
    minimumWidth: 330

    visible: true
    color: "#211F24"
    title: qsTr("Calculator")

    Column {
        spacing: 30
        Rectangle {
            height: 150
            width: 330
            color: "#211F24"
            Text {
                id: name
                text: calculator ? calculator.display : "0"
                width: parent.width - 15
                font.pixelSize: 45
                font.family: "Verdana"
                color: "white"
                fontSizeMode: Text.Fit
                minimumPixelSize: 23
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 15
                horizontalAlignment: Text.AlignRight

            }
        }

        Grid {
            anchors.topMargin: 10
            spacing: 3

            CalcButton {
                text: "%"
                onClicked: calculator.percentage()
            }
            CalcButton {
                text: "CE"
                onClicked: calculator.clearEntry()
            }
            CalcButton {
                text: "C"
                onClicked: calculator.clearAll()
            }
            CalcButton {
                text: "⌫"
                onClicked: calculator.backspace()
            }
            CalcButton {
                text: "1/x"
                onClicked: calculator.reciprocal()
            }
            CalcButton {
                text: "x²"
                onClicked: calculator.square()
            }
            CalcButton {
                text: "²√x"
                onClicked: calculator.squareRoot()
            }
            CalcButton {
                text: "÷"
                onClicked: calculator.setOperation("/")

            }
            CalcButton {
                text: "7"
                onClicked: calculator.addDigit("7")
            }
            CalcButton {
                text: "8"
                onClicked: calculator.addDigit("8")
            }
            CalcButton {
                text: "9"
                onClicked: calculator.addDigit("9")
            }
            CalcButton {
                text: "×"
                onClicked: calculator.setOperation("*")
            }
            CalcButton {
                text: "4"
                onClicked: calculator.addDigit("4")
            }
            CalcButton {
                text: "5"
                onClicked: calculator.addDigit("5")
            }
            CalcButton {
                text: "6"
                onClicked: calculator.addDigit("6")
            }
            CalcButton {
                text: "-"
                onClicked: calculator.setOperation("-")

            }
            CalcButton {
                text: "1"
                onClicked: calculator.addDigit("1")
            }
            CalcButton {
                text: "2"
                onClicked: calculator.addDigit("2")
            }
            CalcButton {
                text: "3"
                onClicked: calculator.addDigit("3")
            }
            CalcButton {
                text: "+"
                onClicked: calculator.setOperation("+")
            }
            CalcButton {
                text: "+/-"
                onClicked: calculator.toggleSign()

            }
            CalcButton {
                text: "0"
                onClicked: calculator.addDigit("0")
            }
            CalcButton {
                text: "."
                onClicked: calculator.addDigit(".")
            }
            CalcButton {
                text: "="
                onClicked: calculator.calculate()
            }

        }
    }


}
