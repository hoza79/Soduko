#include "SodukoGenerator.h"
#include <QRandomGenerator>

SodukoGenerator::SodukoGenerator(QObject *parent)
    : QObject(parent)
{
}

QList<int> SodukoGenerator::generatePuzzle(int holes)
{
    int grid[9][9] = {0};

    solveBoard(grid);

    int removed = 0;
    while (removed < holes) {
        int row = QRandomGenerator::global()->bounded(9);
        int col = QRandomGenerator::global()->bounded(9);
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            removed++;
        }
    }

    QList<int> puzzle;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            puzzle.append(grid[i][j]);
        }
    }
    return puzzle;
}

bool SodukoGenerator::solveBoard(int grid[9][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                QList<int> numbers;
                for (int n = 1; n <= 9; n++) numbers.append(n);

                while (!numbers.isEmpty()) {
                    int index = QRandomGenerator::global()->bounded(numbers.size());
                    int num = numbers.takeAt(index);

                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveBoard(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool SodukoGenerator::isValid(int grid[9][9], int row, int col, int num)
{
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}
