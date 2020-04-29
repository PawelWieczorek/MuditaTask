SRC_DIR := src/
OUT_ROOT := output/

#DEBUG := 1
#RELEASE := 1

TITLE_NAME := Program_1

ifdef DEBUG
	TITLE_NAME += _DEBUG
else
ifdef RELEASE
	TITLE_NAME += _RELEASE
endif
endif

SOURCES := \
		${SRC_DIR}/Main.cpp \


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

main: directiories $(SRC_DIR)Main.cpp
	$(CXX) src/Main.cpp -o $(OUT_DIR)main

clean:
	rm -rf ${OUT_ROOT}
