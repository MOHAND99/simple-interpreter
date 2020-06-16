#include <QApplication>
#include "MainWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MainWindow window;
    window.setWindowState(Qt::WindowMaximized);
    window.show();
    return application.exec();
}


