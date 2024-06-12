CFLAGS ?= -O2 -g

CFLAGS += -std=gnu99

CFLAGS += -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self \
	-Wswitch-default -Wpointer-arith -Wtype-limits -Wempty-body \
	-Wstrict-prototypes -Wold-style-declaration -Wold-style-definition \
	-Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs \
	-Wstack-usage=4096 -Wmissing-prototypes -Wfloat-equal -Wabsolute-value

CFLAGS += -fsanitize=undefined -fsanitize-undefined-trap-on-error

CC += -m32 -no-pie -fno-pie

CCX32 += -no-pie -fno-pie

LDLIBS = -lm

ENTRY_FILE = main
OBJECTS = ./build/func-A.o \
		./build/func-B.o  \
		./build/func-C.o  \
		./build/macros.o \
		./build/integral.o \
		./build/root.o \
		./build/utils.o \
		./build/load-flags.o \
		./build/main.o 

TEST = ./build/func-A.o \
		./build/func-B.o  \
		./build/func-C.o  \
		./build/macros.o \
		./build/integral.o \
		./build/root.o \
		./build/utils.o \
		./build/load-flags.o \
		./build/test.o

.PHONY: all build dev

.SILENT: clear build

# link all object files and build a binary
all: $(OBJECTS)
	rm -f ./build/test.o
	cc $(CCX32) -w $(shell find ./build -name '*.o') -o ./integral

# link all object files and build and launch a test binary
test: $(TEST)
	rm -f ./build/main.o
	cc $(CCX32) -w $(shell find ./build -name '*.o') -o ./test
	./build/test

build/%.o: ./src/nasm-functions/%.asm
	mkdir -p build
	nasm -g -f elf -o $@ $<

build/%.o: ./src/%.c
	mkdir -p build
	cc $(CCX32) -c -o $@ $<

# start binary
start: ./integral
	./integral -i -r

# development build and run
dev: ./src/$(ENTRY_FILE).c
	make clear
	make all
	make start
	make clear

# delete all object files generated during build
clear: ./src/$(ENTRY_FILE).c
	rm -f $(OBJECTS) ./build/test.o
