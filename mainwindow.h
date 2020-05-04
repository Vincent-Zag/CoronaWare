#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsItem>

#include "corona.h"
#include "patience.h"
#include "wash.h"
#include "disinfect.h"

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
    void DisinfectGameSlot(Disinfect * d);

    void on_startButton_clicked();

    void ShowCountdownTimerSlot();

    void DisinfectGame();

    void CountGame();

    void PhasePassed();

    void PhaseFailed();

    void PatienceGame();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene_;
    QGraphicsScene *managementScene_;
    int height_;
    int width_;
    int repeat_ = 5;
    int lives_;
    bool beat_;
    int corona_num_=0;
};
#endif // MAINWINDOW_H
