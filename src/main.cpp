#include <QtWidgets>
#include "../include/MainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow main_window;
    main_window.resize(320, 240);
    main_window.show();
    main_window.setWindowTitle(QApplication::translate("main_window", "Calculatrice"));
    return app.exec();
}