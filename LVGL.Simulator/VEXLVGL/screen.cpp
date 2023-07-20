﻿#include "lvgl/lvgl.h"
#include "screen.h"
extern "C" {
#include "VEXLVGL/images.h"
}

static const char* btn_map[] = { "1", "2", "\n", "3", "4", NULL };

void initscreen() {
    lv_obj_t* img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &LogoScreen);
}
lv_obj_t* AutonTitle;
static void AutonHandler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        const char* txt = lv_btnmatrix_get_btn_text(obj, id);
        lv_label_set_text_fmt(AutonTitle, "Current Auton is: %s", txt);
        LV_UNUSED(txt);
        LV_LOG_USER("Current auton is: %s\n", txt);
    }
}


void autonSelector() {
    AutonTitle = lv_label_create(lv_scr_act());
    lv_label_set_text(AutonTitle, "No Auton Selected");
    lv_obj_align(AutonTitle, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_t* AutonButtons = lv_btnmatrix_create(lv_scr_act());
    lv_btnmatrix_set_map(AutonButtons, btn_map);
    lv_btnmatrix_set_btn_ctrl_all(AutonButtons, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_one_checked(AutonButtons, true);
    lv_obj_add_event_cb(AutonButtons, AutonHandler, LV_EVENT_ALL, NULL);
    lv_obj_align(AutonButtons, LV_ALIGN_CENTER, 0, 0);
}
