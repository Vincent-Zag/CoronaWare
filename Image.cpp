#include "Image.h"

Image::Image(){
    pixmap_->load(":/assets/img/corona virus.png");
    * pixmap_ = pixmap_->scaled(100, 100);
}
