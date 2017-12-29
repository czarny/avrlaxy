//
//  ds3231.c
//  gavrlaxy
//
//  Created by czarny on 25.04.2016.
//
//

#include "ds3231.h"

#include <avr/io.h>
#include "../bdc/bdc.h"
#include "../i2c/i2c.h"


#define CONV    5

#ifndef DS3231_ADDRESS
    #define DS3231_ADDRESS 0xD0
#endif


void ds3231_init(void) {
    i2c_init(400);
}


void ds3231_read_datetime(ds3231_datetime *datetime) {
    uint8_t buffer[7];
    i2c_read_reg(DS3231_ADDRESS, 0x00, buffer, 7);

    for(int i = 0; i < 7; i++) {
        datetime->bytes[i] = bcd2dec(buffer[i]);
    }
}


void ds3231_write_datetime(ds3231_datetime *date) {
    for(int i = 0; i < 7; i++) {
        date->bytes[i] = dec2bcd(date->bytes[i]);
    }

    i2c_write_reg(DS3231_ADDRESS, 0x00, date->bytes, 7);
}


void ds3231_read_temp(ds3231_temp *temp) {
    uint8_t fract_map[] = {0, 25, 50, 75};
    uint8_t buffer[2];
    i2c_read_reg(DS3231_ADDRESS, 0x11, buffer, 2);

    temp->dec = buffer[0];
    temp->fract = fract_map[buffer[1] >> 6];

    uint8_t ctrl;
    i2c_read_reg(DS3231_ADDRESS, 0x0E, &ctrl, 1);
    ctrl |= _BV(CONV);
    i2c_write_reg(DS3231_ADDRESS, 0x0E, &ctrl, 1);
}
