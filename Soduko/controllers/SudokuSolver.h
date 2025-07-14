#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <QObject>
#include <QList>

class SudokuSolver : public QObject
{
    Q_OBJECT
public:
    explicit SudokuSolver(QObject *parent = nullptr);

    Q_INVOKABLE QList<int> solve(const QList<int> &board);

private:
    bool solveBoard(int grid[9][9]);
    bool isValid(int grid[9][9], int row, int col, int num);
};

#endif
