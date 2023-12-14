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

    QObject::connect(htmlWindow, &QPlainTextEdit::textChanged, [htmlWindow, webWindow]()
    {
        auto html = htmlWindow->toPlainText();
        webWindow->setHtml(html);
    });

    mainWindow->show();
    return a.exec();
}

// Text for test:
/*<!DOCTYPE html>
<html>
 <head>
  <title>Основной DOCTYPE html — schoolsw3.com</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
 </head>
 <body>

  <h1>HTML5 Основной DOCTYPE html</h1>

  <h1>Мой первый заголовок</h1>
  <p>Мой первый параграф.</p>

 </body>
</html>*/
