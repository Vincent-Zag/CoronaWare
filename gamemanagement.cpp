#include "gamemanagement.h"

GameManagement::GameManagement()
{
   lives_ = 2;
   score_ = 0;
}
void GameManagement::SetLife(int x, int y){
    life *lives = new life(x,y);
}
//void GameManagement::DeleteLife(){

//}
//void GameManagement::Result(bool success){

//}
//void GameManagement::ShowScore(){

//}
//void GameManagement::ShowTimer(){

//}
