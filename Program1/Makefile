SRC_DIR := src/
OUT_ROOT := output/

#DEBUG := 1
#RELEASE := 1

TITLE_NAME := Program1exec

SOURCES := \
		${SRC_DIR}*.cpp \


ifdef DEBUG
OUT_DIR := ${OUT_ROOT}debug/
else
ifdef RELEASE
OUT_DIR := ${OUT_ROOT}release/
endif
endif

MKDIR_P = mkdir -p

.PHONY: directories

directiories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}

build: directiories ${SOURCES}
	$(CXX) -Wall ${SOURCES} -o ${OUT_DIR}${TITLE_NAME}

clean:
	rm -rf ${OUT_ROOT}

all: clean build
