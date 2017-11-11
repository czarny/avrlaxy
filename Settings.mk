 # MCU name
MCU ?= atmega328

# Processor frequency
F_CPU ?= 16000000

# Optimization level, can be [0, 1, 2, 3, s]. 
#     0 = turn off optimization. s = optimize for size.
#     (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT ?= s

# Toolchain
CC = /opt/local/bin/avr-gcc
OBJCOPY = /opt/local/bin/avr-objcopy
OBJDUMP = /opt/local/bin/avr-objdump
SIZE = /opt/local/bin/avr-size
AR = /opt/local/bin/avr-ar rcs
NM = /opt/local/bin/avr-nm