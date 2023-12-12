#include "mainwindow.h"

#include <QApplication>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto* mainWindow = new QWidget;
    mainWindow->setMinimumSize(1000, 500);

    auto* hbox = new QHBoxLayout(mainWindow);
    auto* htmlWindow = new QPlainTextEdit;
    hbox->addWidget(htmlWindow);

    auto* webWindow = new QWebEngineView;
    hbox->addWidget(webWindow);

    htmlWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    webWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainWindow->show();
    return a.exec();
}
