CC = g++
CXX = g++

BUILDDIR=/data/xqx/tests/opencv-test/build
PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig
CFLAGS := -c -Wall $(shell pkg-config --cflags opencv)
LDFLAGS := $(shell pkg-config --static --libs opencv)

LD_LIBRARY_PATH=$(BUILDDIR)/install/lib
TEST_IMG=$(BUILDDIR)/.././opencv_extra/learning_opencv_v2/stereoData/left08.jpg

MAINPRO=31_boxFilter

.PHONY: main

all: opencv_test.elf 

opencv_test.elf: ${MAINPRO}.o; $(CC) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CC) $< -o $@ $(CFLAGS)

main:
	${CXX} ${MAINPRO}.cpp -o test-afl33.elf ${CFLAGS} ${LDFLAGS}
	#./test1  $(TEST_IMG)


afl:export BUILDDIR=/data/xqx/tests/opencv-test/aflbuild
afl:export PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig
afl:export CFLAGS =  $(shell export PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig; pkg-config --cflags opencv)
afl:export LDFLAGS = $(shell export PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig; pkg-config  --libs opencv)
afl:
	#@echo ${PKG_CONFIG_PATH}
	#@echo  ${CFLAGS}
	@echo ${LDFLAGS}
	AFL_USE_ASAN=1 afl-g++ ${MAINPRO}.cpp -o ${MAINPRO}-afl33.elf ${CFLAGS} ${LDFLAGS}

clean:
	rm -f *.elf
