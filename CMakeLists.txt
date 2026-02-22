cmake_minimum_required(VERSION 3.16)
project(Calculatrice VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_PREFIX_PATH "/usr/lib/cmake/Qt6")
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
qt_add_executable(Calculatrice
   ./src/main.cpp
   ./src/MainWindow.cpp
   ./src/Calculator.cpp
   ./src/Parser.cpp
   ./include/MainWindow.hpp
   ./include/Calculator.hpp
   ./include/Parser.hpp
)
target_link_libraries(Calculatrice PRIVATE Qt6::Widgets)
