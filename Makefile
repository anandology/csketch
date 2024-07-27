
.PHONY: default build docs

default: build docs images

build:
	cd sketch && make

docs: images
	mkdocs build

images:
	cd docs/images && make
