# Calculatrice

A graphical calculator built in C++ with Qt6, featuring a full mathematical expression parser.

## Demo



https://github.com/user-attachments/assets/2ed98e5b-a1cd-456f-9774-4460fa1ef4c3



## Features

- Basic operations: addition, subtraction, multiplication, division
- Full expression evaluation respecting operator precedence (e.g. `3 + 4 * 2 = 11`)
- Calculation history displayed in real time
- Clean and minimal Qt6 interface

## How it works

### Expression Parser — Shunting Yard Algorithm

Rather than evaluating expressions button by button, the calculator uses a proper expression parser based on the **Shunting Yard algorithm**, invented by Edsger Dijkstra.

The algorithm works in three steps:

1. **Tokenization** — the input string (e.g. `"3 + 4 * 2"`) is split into a list of tokens: numbers and operators.
2. **Infix to Postfix conversion** — the tokens are reordered from standard infix notation (`3 + 4 * 2`) to postfix notation (`3 4 2 * +`) using a stack, respecting operator precedence (`*` and `/` before `+` and `-`).
3. **Postfix evaluation** — the postfix expression is evaluated using a second stack, producing the final result.

This approach makes it straightforward to extend the parser with parentheses support or new operators in the future.

### Architecture

The project is split into three clearly separated layers:

- **Calculator** — pure C++ business logic, arithmetic operations and history management. No Qt dependency.
- **Parser** — stateless expression parser, all methods are static. No Qt dependency.
- **MainWindow** — Qt6 interface, connects user input to Calculator and Parser. Contains no business logic.

## Dependencies

- [Qt6](https://www.qt.io/) — Widgets module for the graphical interface

## Build & Run

**Requirements:** g++ or clang++, CMake 3.16+, Qt6

This project was developed using **VSCode with the CMake Tools extension**. There is no Makefile — CMake generates the build files automatically.

```bash
# Clone the repository
git clone https://github.com/xeradse/Calculatrice.git
cd Calculatrice

# Configure and build
mkdir build
cd build
cmake ..
cmake --build .

# Run
./Calculatrice
```

## Project Structure

```
Calculatrice/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── Calculator.hpp
│   ├── Parser.hpp
│   └── MainWindow.hpp
└── src/
    ├── main.cpp
    ├── Calculator.cpp
    ├── Parser.cpp
    └── MainWindow.cpp
```

## Author

Made as a personal C++ project to practice Qt6, object-oriented architecture, and algorithm implementation.
