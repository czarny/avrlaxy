//
//  i2c.h
//  gavrlaxy
//
//  Created by czarny on 26.04.2016.
//
//

#ifndef i2c_h
#define i2c_h

#include <stdint.h>

void i2c_init(uint16_t speed);
void i2c_start(uint8_t address);
void i2c_wait(void);
void i2c_stop(void);

void i2c_write(uint8_t data);
uint8_t i2c_read_ack(void);
uint8_t i2c_read_nack(void);

void i2c_write_reg(uint8_t address, uint8_t reg, uint8_t *data, uint8_t length);
void i2c_read_reg(uint8_t address, uint8_t reg, uint8_t *data, uint8_t length);


#endif /* i2c_h */
