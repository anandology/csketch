
CSKETCH_VERSION=0.1.2

.PHONY: default build docs

default: build docs images

build:
	cd sketch && make

docs: images
	mkdocs build

images:
	cd docs/images && make

package:
	-rm -f dist/*
	mkdir -p dist/package
	cd sketch && make clean
	cp -r sketch examples/circle.c dist/package/
	cp  Makefile.sample dist/package/Makefile
	-rf -f dist/csketch-$(CSKETCH_VERSION).zip dist/csketch-$(CSKETCH_VERSION).tar.gz
	cd dist/package && zip -r ../csketch-$(CSKETCH_VERSION).zip *
	cd dist/package && tar cvzf ../csketch-$(CSKETCH_VERSION).tar.gz *
	cd sketch && make

