#ifndef SODUKOGENERATOR_H
#define SODUKOGENERATOR_H

#include <QObject>
#include <QList>

class SodukoGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SodukoGenerator(QObject *parent = nullptr);

    Q_INVOKABLE QList<int> generatePuzzle(int holes = 40);

private:
    bool solveBoard(int grid[9][9]);
    bool isValid(int grid[9][9], int row, int col, int num);
};

#endif
