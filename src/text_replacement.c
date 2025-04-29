
#include "modding.h"
#include "global.h"
#include "ultra64.h"
#include "eztr_api.h"

EZTR_ON_INIT void replace_msgs() {
    EZTR_Basic_ReplaceText(
        0x1FA4,
        EZTR_STANDARD_TEXT_BOX_I,
        49,
        EZTR_ICON_NO_ICON,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        EZTR_NO_VALUE,
        true,
        "|1Ei}You picked the wrong house, fool!"EZTR_MSG_END,
        NULL
    );
}