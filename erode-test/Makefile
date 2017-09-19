CC = g++
CXX = g++

BUILDDIR=/data/xqx/tests/opencv-test/build
PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig
CFLAGS += -c -Wall $(shell pkg-config --cflags opencv)

LDFLAGS += $(shell pkg-config --libs opencv)

LD_LIBRARY_PATH=$(BUILDDIR)/install/lib
TEST_IMG=$(BUILDDIR)/.././opencv_extra/learning_opencv_v2/stereoData/left08.jpg


.PHONY: main

all: opencv_test

opencv_test: test.o; $(CC) $< -o $@ $(LDFLAGS)

%.o: %.c; $(CC) $< -o $@ $(CFLAGS)

main:
	${CXX} 3_ImageErode.cpp -o test1 $(shell pkg-config --cflags --libs opencv)
	#./test1  $(TEST_IMG)


afl:
	@echo ${PKG_CONFIG_PATH}

clean:
	rm test1 
