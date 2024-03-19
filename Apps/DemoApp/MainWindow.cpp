#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDropEvent>
#include <QMimeData>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dropEvent(QDropEvent* event_) {
    const QUrl    url        = event_->mimeData()->urls().at(0);
    const QString inputFile = url.toLocalFile();
    std::cout << "filename : " << inputFile.toLocal8Bit().toStdString() << std::endl;
    try {

    }
    catch (const std::exception& e) {

    }
    event_->acceptProposedAction();
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event_) {
    if (event_->mimeData()->hasUrls()) {
        event_->acceptProposedAction();
    }
}
