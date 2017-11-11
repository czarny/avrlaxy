//
//  i2c.c
//  gavrlaxy
//
//  Created by czarny on 26.04.2016.
//
//

#include "i2c.h"

#include <util/twi.h>



void i2c_init(uint16_t speed) {
//    PORTC |= 0x24;

    // SCLf = F_CPU /(16 + 2·TWBR·4^TWPS)
    uint16_t twbr = ((F_CPU / (1000.0 * speed)) - 16) / 2;

    uint8_t prescaler=0;
    while(twbr > 255) {
        twbr /= 4;
        prescaler++;
    };

    TWBR = twbr;
    TWSR = prescaler;
}


void i2c_start(uint8_t address) {
    TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
    i2c_wait();

    i2c_write(address);
}


void i2c_wait(void) {
    while(!(TWCR & _BV(TWINT)));
}


void i2c_stop(void) {
    TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);
    while(TWCR & _BV(TWSTO));
}


void i2c_write(uint8_t data) {
    TWDR = data;
    TWCR = _BV(TWINT) | _BV(TWEN);

    i2c_wait();
}


uint8_t i2c_read_ack(void) {
    TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA);  // Start TWI with auto ack
    i2c_wait();

    return TWDR;
}

uint8_t i2c_read_nack(void) {
    TWCR = _BV(TWINT) | _BV(TWEN);  // Start TWI without ack
    i2c_wait();

    return TWDR;
}


void i2c_write_reg(uint8_t address, uint8_t reg, uint8_t *data, uint8_t length) {
    uint8_t i = 0;

    // Start write reg
    i2c_start(address);
    i2c_write(reg);

    // Wirte data
    for(i = 0; i < length; i++) {
        i2c_write(data[i]);
    }

    // Finish
    i2c_stop();
}


void i2c_read_reg(uint8_t address, uint8_t reg, uint8_t *data, uint8_t length) {
    uint8_t i = 0;

    // Start read reg
    i2c_start(address);
    i2c_write(reg);

    // Read data
    i2c_start(address | 0x01);
    for(i = 0; i < length - 1; i++) {
        data[i] = i2c_read_ack();
    }
    data[i] = i2c_read_nack();

    // Finish
    i2c_stop();
}
