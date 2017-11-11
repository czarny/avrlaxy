//
//  ds3231.h
//  gavrlaxy
//
//  Created by czarny on 25.04.2016.
//
//

#ifndef ds3231_h
#define ds3231_h

#include <stdint.h>



typedef union {
    uint8_t bytes[7];
    struct {
        uint8_t sec;
        uint8_t min;
        uint8_t hr;
        uint8_t dow;
        uint8_t day;
        uint8_t month;
        uint8_t year;
    };
} ds3231_datetime;

typedef union {
    uint8_t bytes[2];
    struct {
        int8_t dec;
        uint8_t fract;
    };
} ds3231_temp;


void ds3231_init(void);
void ds3231_read_datetime(ds3231_datetime *date);
void ds3231_read_temp(ds3231_temp *temp);


#endif /* ds3231_h */
