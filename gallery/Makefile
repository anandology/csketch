
SOURCES=$(wildcard src/*.c)

SVG_TARGETS=$(SOURCES:src/%.c=images/%.svg)
MD_TARGETS=$(SOURCES:src/%.c=%.md)
TARGETS=$(SVG_TARGETS) $(EXE_TARGETS) $(MD_TARGETS)

SKETCH_PATH=../../sketch
CC=gcc -I$(SKETCH_PATH) -L $(SKETCH_PATH)

.PHONY: default

default: $(TARGETS)

images/%.svg: src/%.c
	@mkdir -p images
	$(CC) $<  -lm -l sketch -o /tmp/sketch_tmp
	cd images && /tmp/sketch_tmp
	-@rm /tmp/sketch_tmp

%.md: src/%.c
	python make_page.py $< > $@

clean:
	-rm -f $(TARGETS)

cleanx:
	-rm -f $(EXE_TARGETS)
