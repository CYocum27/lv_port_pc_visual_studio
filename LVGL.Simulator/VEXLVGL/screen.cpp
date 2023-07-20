#include "lvgl/lvgl.h"
#include "screen.h"
extern "C" {
#include "VEXLVGL/images.h"
}

void initscreen() {
    lv_obj_t* img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &LogoScreen);
}
