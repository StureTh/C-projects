#include "images.h"


image_t image_camel;
const char camel_data[8][18] = {

"    //",
"   _00\\",
"  (__/ \\  _  _",
"     \\  \\/ \\/ \\",
"     (         )",
"      \\_______/ \\",
"       [[] [[]   *",
"       [[] [[]"
};


void IMAGE_init(void)
{
    image_camel.image = camel_data;
    image_camel.width = 18;
    image_camel.height = 8;
}
