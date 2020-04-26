#include "gamemanagement.h"

GameManagement::GameManagement()
{
   lives_ = 2;
   score_ = 0;
   life_.load(":/assets/img/toilet paper.png");
   life_ = life_.scaled(100, 100);
   setPixmap(life_);

}

//void GameManagement::DeleteLife(){

//}
//void GameManagement::Result(bool success){

//}
//void GameManagement::ShowScore(){

//}
//void GameManagement::ShowTimer(){

//}
