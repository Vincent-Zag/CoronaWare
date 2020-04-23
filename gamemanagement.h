#ifndef GAMEMANAGEMENT_H
#define GAMEMANAGEMENT_H

#include<QTimer>

class GameManagement
{
public:
    GameManagement();
    void DeleteLife();
    void Result(bool success);
    void ShowScore();
    void ShowTimer();


private:
    int lives_;
    int score_;
    QTimer *time_;
};

#endif // GAMEMANAGEMENT_H
