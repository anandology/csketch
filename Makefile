
CSKETCH_VERSION=0.1.0

.PHONY: default build docs

default: build docs images

build:
	cd sketch && make

docs: images
	mkdocs build

images:
	cd docs/images && make

package:
	mkdir -p dist
	cd sketch && make clean
	-rf -f dist/csketch-$(CSKETCH_VERSION).zip dist/csketch-$(CSKETCH_VERSION).tar.gz
	zip -r dist/csketch-$(CSKETCH_VERSION).zip sketch
	tar cvzf dist/csketch-$(CSKETCH_VERSION).tar.gz sketch
	cd sketch && make

