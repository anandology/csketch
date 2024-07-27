
SOURCES=$(wildcard *.c)

TARGETS=$(SOURCES:%.c=%)

.PHONY: default

default: $(TARGETS)

%: %.c
	gcc -I ../sketch/ -L ../sketch/  $<  -lm -l sketch -o $@


clean:
	-rm -f $(TARGETS)
