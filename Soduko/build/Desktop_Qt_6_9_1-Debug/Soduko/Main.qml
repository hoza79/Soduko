import QtQuick
import Soduko

Window {
    width: 700
    height: 700
    visible: true
    title: qsTr("Sudoku")

    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2

    Board {}
}
