#include "gamemanagement.h"

GameManagement::GameManagement()
{
   score_ = 0;
   life1_ = new Life(901,50);
   life2_ = new Life(801,50);
   timer_hands_[0] = new Timer(501,40,0);
   timer_hands_[1] = new Timer(401,40,1);
   timer_hands_[2] = new Timer(301,40,2);
   timer_hands_[3] = new Timer(201,40,3);
   timer_hands_[4] = new Timer(101,40,4);
   timer_hands_[5] = new Timer(1,40,5);
}

//void GameManagement::DeleteLife(){

//}
//void GameManagement::Result(bool success){

//}
//void GameManagement::ShowScore(){

//}

void GameManagement::SetScore(int value){
    score_ = score_ + value;
}
