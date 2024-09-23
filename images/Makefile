
SOURCES=$(wildcard *.c)

EXE_TARGETS=$(SOURCES:%.c=bin/%)
SVG_TARGETS=$(SOURCES:%.c=%.svg)
TARGETS=$(SVG_TARGETS) $(EXE_TARGETS)

SKETCH_PATH=../../sketch
CC=gcc -I$(SKETCH_PATH) -L $(SKETCH_PATH)

.PHONY: default

default: $(TARGETS)

bin/%: %.c
	@mkdir -p bin
	$(CC) $<  -lm -l sketch -o $@

%.svg: bin/%
	./$<

clean:
	-rm -f $(TARGETS)

cleanx:
	-rm -f $(EXE_TARGETS)
