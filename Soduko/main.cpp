#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controllers/SudokuSolver.h"
#include "controllers/SodukoGenerator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    SudokuSolver solver;
    SodukoGenerator generator;
    engine.rootContext()->setContextProperty("solver", &solver);
    engine.rootContext()->setContextProperty("generator", &generator);

    engine.loadFromModule("Soduko", "Main");

    return app.exec();
}
