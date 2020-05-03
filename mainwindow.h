#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsItem>

#include "corona.h"
#include "patience.h"
#include "wash.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Games();
private slots:
    // default slot that reacts to random button being clicked
    void CoronaSelectedSlot(Corona * c);
    void PatienceSelectedSlot(Patience * p);
    //void WashSelectedSlot(Wash * w);

    void on_startButton_clicked();

    void ShowCountdownTimerSlot();

    void PhasePassed();

    void PhaseFailed();

    void PatienceGame();

    void WashGame();

    void on_handwashing_gif_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene_;
    QGraphicsScene *managementScene_;
    int height_;
    int width_;
    int repeat_ = 5;
    int lives_;
    bool beat_;
};
#endif // MAINWINDOW_H
