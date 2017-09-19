CC = g++
CXX = g++


BUILDDIR=/data/xqx/tests/opencv-test/build
LD_LIBRARY_PATH=$(BUILDDIR)/install/lib
TESTIMG=$(BUILDDIR)/../pics/p13.jpg

MAINPRO=resize

.PHONY: main clean test

export PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig
CFLAGS := -c -Wall $(shell export PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig; pkg-config --cflags opencv)
LDFLAGS := $(shell export PKG_CONFIG_PATH=${BUILDDIR}/install/lib/pkgconfig; pkg-config --static --libs opencv)
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
afl:export AFL_PATH=/data/xqx/projects/afl-test/aflfast
afl:export PATH:=${PATH}:/data/xqx/projects/afl-test/aflfast
afl:
	@echo ${LDFLAGS}
	AFL_USE_ASAN=1 afl-g++ -D AFL_FUZZ ${MAINPRO}.cpp -o ${MAINPRO}-afl33.elf ${CFLAGS} ${LDFLAGS}

test:
	export LD_LIBRARY_PATH=${BUILDDIR}/install/lib ; ./opencv_test.elf ${TESTIMG}

afltest:export BUILDDIR=/data/xqx/tests/opencv-test/aflbuild
afltest:
	export LD_LIBRARY_PATH=${BUILDDIR}/install/lib ; ./${MAINPRO}-afl33.elf ${TESTIMG}


clean:
	rm -f *.elf
	rm -f *.o
