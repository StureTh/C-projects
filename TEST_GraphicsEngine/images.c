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

image_t image_bat;
const char bat_data[13][30] = {
    "  ._.                  _.____.",
    "  ) \\.              /    .(",
    "  )  |            .'   .(",
    "  ). ).          .'  .(",
    "    ) |.        .'  (",
    "    ). ;      ./  .(",
    "     ) |      )  (",
    "     ).;      :.(",
    "      )|    .|.;",
    "      .^--^./ (.",
    "      ;0..0;   \\",
    "        vv_.:_.;",
    "            m  M",
};

void IMAGE_init(void)
{
    image_camel.image = &camel_data;
    image_camel.height = 8;
    image_camel.width = 18;


    image_bat.image = &bat_data;
    image_bat.height =13;
    image_bat.width = 30;

}
