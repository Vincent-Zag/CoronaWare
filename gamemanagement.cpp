#include "gamemanagement.h"

GameManagement::GameManagement()
{
   lives_ = 2;
   if (lives_ == 2){
        life1_ = new Life(901,50);
        life2_ = new Life(801,50);
   }else if (lives_ == 1){
        life1_ = new Life(901,50);
   }
   timer_hands_[0] = new Timer(501,40,0);
   timer_hands_[1] = new Timer(401,40,1);
   timer_hands_[2] = new Timer(301,40,2);
   timer_hands_[3] = new Timer(201,40,3);
   timer_hands_[4] = new Timer(101,40,4);
   timer_hands_[5] = new Timer(1,40,5);
}

void GameManagement::SetLife(int value){
    lives_ = lives_ + value;
}
