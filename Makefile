include Settings.mk

# Modules list
MODULES += bdc
MODULES += bmp280
MODULES += cycle
MODULES += ds3231
MODULES += i2c
MODULES += pcd8544
MODULES += ssd1306


# Library directory
LIBDIR = lib
LIBLIST = $(addprefix lib,$(MODULES))
CLEANLIST = $(addprefix clean,$(MODULES))

# Include directory
INCDIR = include

lib%: %
	@echo
	@echo --- Make $< ---
	$(MAKE) lib -f ../Library.mk -C $<
	cp $</bin/lib$<.a $(LIBDIR)
	cp $</*.h $(INCDIR)

clean%: %
	@echo
	@echo --- Clean $< ---
	$(MAKE) clean -f ../Library.mk -C $<


all: $(LIBLIST)

clean: $(CLEANLIST)
	rm -rf $(LIBDIR)
	rm -rf $(INCDIR)


# Create object files directory
$(shell mkdir $(LIBDIR) 2>/dev/null)

# Create binary files directory
$(shell mkdir $(INCDIR) 2>/dev/null)
