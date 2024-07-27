
SOURCES=$(wildcard *.c)

EXE_TARGETS=$(SOURCES:%.c=%)
SVG_TARGETS=$(SOURCES:%.c=%.svg)
TARGETS=$(SVG_TARGETS) $(EXE_TARGETS)

.PHONY: default

default: $(TARGETS)

%: %.c
	gcc -I ../sketch/ -L ../sketch/  $<  -lm -l sketch -o $@

%.svg: %
	./$<

clean:
	-rm -f $(TARGETS)

cleanx:
	-rm -f $(EXE_TARGETS)
