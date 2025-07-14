import QtQuick 2.15
import QtQuick.Controls 2.15
import Soduko

Item {
    width: 700
    height: 700

    ListModel {
        id: boardModel
        Component.onCompleted: {
            for (let i = 0; i < 81; i++) {
                append({ value: "" })
            }
        }
    }

    Rectangle {
        id: boardRect
        width: 450
        height: 450
        anchors.centerIn: parent
        color: "white"
        border.color: "black"
        border.width: 2

        Grid {
            id: sudokuGrid
            anchors.fill: parent
            columns: 9
            spacing: 0

            Repeater {
                id: cellRepeater
                model: boardModel

                Rectangle {
                    width: 50
                    height: 50
                    color: "white"

                    TextField {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 20
                        maximumLength: 1
                        color: "black"
                        text: model.value

                        onTextChanged: {
                            boardModel.setProperty(index, "value", text)
                        }

                        background: Rectangle {
                            color: "yellow"
                        }
                    }
                }
            }
        }

        Repeater {
            model: 8
            Rectangle {
                width: 1
                height: boardRect.height
                color: "black"
                x: (index + 1) * boardRect.width / 9
                y: 0
            }
        }

        Repeater {
            model: 8
            Rectangle {
                width: boardRect.width
                height: 1
                color: "black"
                x: 0
                y: (index + 1) * boardRect.height / 9
            }
        }

        Repeater {
            model: 2
            Rectangle {
                width: 3
                height: boardRect.height
                color: "black"
                x: (index + 1) * boardRect.width / 3 - 1.5
                y: 0
            }
        }

        Repeater {
            model: 2
            Rectangle {
                width: boardRect.width
                height: 3
                color: "black"
                x: 0
                y: (index + 1) * boardRect.height / 3 - 1.5
            }
        }
    }



    Row {
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: boardRect.bottom
        anchors.topMargin: 20

        Button {
            text: "Generate"
            onClicked: {
                var puzzle = generator.generatePuzzle(40)
                for (let i = 0; i < 81; i++) {
                    boardModel.setProperty(i, "value", puzzle[i] > 0 ? puzzle[i].toString() : "")
                }
            }
        }

        Button {
            text: "Solve"
            onClicked: {
                var board = []
                for (let i = 0; i < 81; i++) {
                    var val = boardModel.get(i).value
                    board.push(Number(val) || 0)
                }

                var solved = solver.solve(board)
                console.log("Solved board:", solved)

                if (solved.length === 81) {
                    for (let i = 0; i < 81; i++) {
                        boardModel.setProperty(i, "value", solved[i].toString())
                    }
                } else {
                    console.log("No solution found!")
                }
            }
        }
    }
}
