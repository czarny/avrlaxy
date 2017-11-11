//
//  bdc.c
//  gavrlaxy
//
//  Created by czarny on 11.10.2017.
//
//

#include "bdc.h"


uint8_t dec2bcd(uint8_t dec) {
    uint8_t bcd = ((dec / 10) << 4) | (dec % 10);
    return bcd;
}


uint8_t bcd2dec(uint8_t bcd) {
    uint8_t dec = (((bcd >> 4) & 0x0F) * 10) + (bcd & 0x0F);
    return dec;
}
