#include "score.h"



Score::Score(bool wario_dance, bool wario_unhappy, int cells, QColor color, bool happy, bool cheer, bool score_zero,int width, int height)
{
    if(wario_dance){
        wario_dance_= new QMovie(":/assets/img/wario_dancing.gif");
    }
    if(wario_unhappy){
        wario_unhappy_.load(":/assets/img/gamemanagement_background.jpeg");
        wario_unhappy_ = wario_unhappy_.scaled(100, 100);
        setPos(100,100);
        setPixmap(wario_unhappy_);
    }
    color_=color;
    if(happy){
        song_= new QMediaPlayer();
        song_->setMedia(QUrl("qrc:/assets/sound/WarioWare, Inc. Super Smash Bros. Ultimate.mp3"));
    }
    if(cheer){
        sound_= new QMediaPlayer();
        sound_-> setMedia(QUrl("qrc:/assets/sound/Correct/win1.wav"));
    }
    else{
        sound_= new QMediaPlayer();
        sound_-> setMedia(QUrl("qrc:/assets/sound/Incorrect/lose.wav"));
    }
    if(score_zero){
        song_= new QMediaPlayer();
        song_->setMedia(QUrl("qrc:/assets/sound/Patience minigame/Nichijou - GOD IS DEAD.mp3"));
    }
    this->populate(cells,width,height);

}

void Score::populate(int cells, int width, int height){
    cells_.clear();
    for(int i=0; i<cells; i++){
        int cell_w= qrand()%(width-100);
        int cell_h= qrand()%(height-100);
        cells_.push_back(new Corona(cell_w,cell_h));
    }

}



