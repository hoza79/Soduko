# Sudoku Game

A full-featured Sudoku game built with C++ and Qt 6 using QML for the UI. The project includes a playable GUI, a backtracking solver, and a random puzzle generator.

---

## Features

- Dynamic 9×9 Sudoku grid in QML
- Editable cells with validation (digits 1-9)
- Thin grid lines for cell separation
- Bold lines every 3 cells for 3×3 block boundaries
- Random puzzle generation with adjustable difficulty
- Backtracking solver implemented in C++
- Integration between C++ logic and QML UI
- Real-time solving and puzzle generation from the UI
- Responsive and modern interface

---

## Technologies Used

- C++17
- Qt 6
- QML (Qt Quick)
- CMake

---

## How It Works

### Puzzle Generator

- Generates a fully solved Sudoku board.
- Randomly removes cells to create playable puzzles with unique solutions.
- Written in C++ as a QObject class exposed to QML.

### Solver

- Implements a recursive backtracking algorithm.
- Accepts a partially-filled board and fills in the solution.
- Written in C++ as a QObject class exposed to QML.

### UI

- Created entirely with QML and Qt Quick Controls.
- Binds UI fields to a QML ListModel for reactive updates.
- Buttons to generate and solve puzzles.

---
