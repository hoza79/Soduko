#include "SudokuSolver.h"

SudokuSolver::SudokuSolver(QObject *parent)
    : QObject(parent)
{
}

QList<int> SudokuSolver::solve(const QList<int> &board)
{
    int grid[9][9];

    for (int i = 0; i < 81; i++) {
        grid[i / 9][i % 9] = board[i];
    }

    if (solveBoard(grid)) {
        QList<int> result;
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                result.append(grid[row][col]);
            }
        }
        return result;
    } else {
        return {};
    }
}

bool SudokuSolver::solveBoard(int grid[9][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
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

bool SudokuSolver::isValid(int grid[9][9], int row, int col, int num)
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
