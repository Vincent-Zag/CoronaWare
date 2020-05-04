#include "countvirus.h"

void CountVirus::populate(int width, int height){
    cells_.clear();
    int value=(qrand()%5)+8; //value will always display at least 8 and go to 12
    for(int i=0; i<value; i++){
        int cell_w= qrand()%(width-100);
        int cell_h= qrand()%(height-100);
        cells_.push_back(new Corona(cell_w,cell_h));
    }
}
