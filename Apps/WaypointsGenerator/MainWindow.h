#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dropEvent(QDropEvent* event_) override;
    void dragEnterEvent(QDragEnterEvent* event_) override;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
