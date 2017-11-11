//
//  ssd1306.h
//  gavrlaxy
//
//  Created by Krzysztof Czarnota on 05.11.2017.
//

#ifndef ssd1306_h
#define ssd1306_h

#include <stdint.h>

// SSD1306 Commands
typedef enum SSD1306_COMMAND {
    SSD1306_SETLOWERCOLUMNSTARTADDRES   = 0x00,
    SSD1306_SETHIGHERCOLUMNSTARTADDRES  = 0x10,
    SSD1306_SETMEMORYADDRESSINGMODE     = 0x20,
    SSD1306_COLUMNADDRES                = 0x21,
    SSD1306_PAGEADDRES                  = 0x22,
    SSD1306_SETDISPLAYSTARTLINE         = 0x40,
    SSD1306_SETCONTRASTCONTROL          = 0x81,
    SSD1306_SETCHARGEPUMP               = 0x8D,
    SSD1306_SETSEGMENTREMAP             = 0xA0,
    SSD1306_ENTIREDISPLAYALLONRESUME    = 0xA4,
    SSD1306_ENTIREDISPLAYALLON          = 0xA5,
    SSD1306_SETNORMALDISPLAY            = 0xA6,
    SSD1306_SETINVERSEDISPLAY           = 0xA7,
    SSD1306_SETMULTIPLEXRATIO           = 0xA8,
    SSD1306_SETDISPLAYOFF               = 0xAE,
    SSD1306_SETDISPLAYON                = 0xAF,
    SSD1306_SETCOMOUTPUTSCANDIRECTIONINC = 0xC0,
    SSD1306_SETCOMOUTPUTSCANDIRECTIONDEC = 0xC8,
    SSD1306_SETDISPLAYOFFSET            = 0xD3,
    SSD1306_SETDISPLAYCLOCKDIVRATIO     = 0xD5,
    SSD1306_SETPRECHARGEPERIOD          = 0xD9,
    SSD1306_SETCOMPINSHWCONFIGURATION   = 0xDA,
    SSD1306_SETVCOMDESELECTLEVEL        = 0xDB,
    SSD1306_NOP                         = 0xE3,
    SSD1306_SWITCHCAPVCC                = 0x2
} SSD1306_COMMAND;


void ssd1306_init(void);
void ssd1306_command(SSD1306_COMMAND c);
void ssd1306_data(uint8_t d);

void ssd1306_clear(void);
void ssd1306_goto(uint8_t x, uint8_t y);
void ssd1306_putc(char ch);
void ssd1306_puts(char *string);

#endif /* ssd1306_h */
