#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDropEvent>
#include <QMimeData>
#include <iostream>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    connect(ui->toolButton_input, &QToolButton::clicked, [=]() {
        auto inputFile = QFileDialog::getOpenFileName(
            nullptr, QString::fromLocal8Bit("航点文件输入路径"), "", "(*.txt)");
        if (!inputFile.isEmpty()) {
            ui->lineEdit_input->setText(inputFile);
        }
        });
    connect(ui->toolButton_output, &QToolButton::clicked, [=]() {
        auto outputFile = QFileDialog::getSaveFileName(
            nullptr, QString::fromLocal8Bit("航点输出文件路径"), "output.txt", "(*.txt)");
        if (!outputFile.isEmpty()) {
            ui->lineEdit_ouput->setText(outputFile);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dropEvent(QDropEvent* event_) {
    const QUrl    url        = event_->mimeData()->urls().at(0);
    const QString inputFile = url.toLocalFile();
    std::cout << "filename : " << inputFile.toLocal8Bit().toStdString() << std::endl;
    ui->lineEdit_input->setText(inputFile);
    event_->acceptProposedAction();
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event_) {
    if (event_->mimeData()->hasUrls()) {
        event_->acceptProposedAction();
    }
}
