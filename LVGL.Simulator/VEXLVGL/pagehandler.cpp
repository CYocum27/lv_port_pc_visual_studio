#include "screen.h"
#include "lvgl/lvgl.h"
#include "pagehandler.h"
void pageHandler(int page) {
    switch (page) {
    case 0:
        initScreen();
        break;
    case 1:
        autonSelector();
        break;
        
    }
}
