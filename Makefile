.PHONY: all altered original

# The default target
all: altered original

# Target to build the Makefile in the Alterado directory
altered:
	$(MAKE) -C Alterado

# Target to build the Makefile in the Original directory
original:
	$(MAKE) -C Original

clean: clean_altered clean_original

clean_altered:
	$(MAKE) -C Alterado clean

clean_original:
	$(MAKE) -C Original clean