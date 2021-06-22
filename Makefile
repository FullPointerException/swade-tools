SHELL = /bin/sh


.PHONY: all
all:
	$(MAKE) -C "./build" all

.PHONY: clean
clean:
	$(MAKE) -C "./build" clean

.PHONY: test
test: all
	$(MAKE) -C "./build" test

.PHONY: init
init:
	cmake -S . -B ./build -G "Unix Makefiles"

.PHONY: run
run: all
	./build/src/swade