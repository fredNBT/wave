#ifndef PINS_H_
#define PINS_H_

#include "Arduino.h"

#define PIN_LED_HB  13
#define PIN_SYSTICK  8
#define PIN_POD0     9
#define PIN_POD1    10
#define PIN_LED_SRV 12
#define PIN_BTN_SRV 17

#define PIN_MTR_EN   4
#define PIN_MTR_DIR  5
#define PIN_MTR_PULS 6
#define PIN_MTR_ERR 18

#define PIN_BTN_USR 11
#define PIN_BTN_RMT  2
#define PIN_PIR_TRG  3

#define PIN_BTN_LID 14
#define PIN_BTN_ES1 15
#define PIN_BTN_ES2 16

void pins_init(void);
bool flags_get_lid(void);
bool flags_get_es1(void);

#endif
