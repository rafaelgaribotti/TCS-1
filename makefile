# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT= Unity
CODE_ROOT= sort

CFLAGS  = -std=c99
CFLAGS += -w
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  $(CODE_ROOT)/src/sort.c \
	$(CODE_ROOT)/test/TestSelectionSort.c \
	$(CODE_ROOT)/test/TestInsertionSort.c \
	$(CODE_ROOT)/test/TestShellSort.c \
	$(CODE_ROOT)/test/TestQuickSort.c \
	$(CODE_ROOT)/test/TestHeapSort.c \
	$(CODE_ROOT)/test/TestMergeSort.c \
	$(CODE_ROOT)/test/TestSortArray.c \
  $(CODE_ROOT)/test/test_runners/TestSort_Runner.c \
  $(CODE_ROOT)/test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=
all: clean cppcheck unitTests valgrind addressSanitizer cov

cppcheck:
	@echo "  "
	@echo "  "
	@echo "********  cppcheck  *******"
	cppcheck sort/src/* sort/test/*

compile:
	@echo "  "
	@echo "  "
	@echo "********  compile  *******"
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

unitTests: compile
	@echo "  "
	@echo "  "
	@echo "********  UnitTests  *******"
	./$(TARGET1) -v

valgrind: compile
	@echo "  "
	@echo "  "
	@echo "********  valgrind  *******"
	valgrind --leak-check=full --show-leak-kinds=all ./all_tests.out

cov:
	@echo "  "
	@echo "  "
	@echo "********  cov  *******"
	$(C_COMPILER) $(CFLAGS) -fprofile-arcs -ftest-coverage $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	./$(TARGET1)
	rm -r unity*
	gcov ***.gcno
	gcovr -r .
	gcovr -r . --html --html-details -o coverage/gcoverage.html

addressSanitizer:
	@echo "  "
	@echo "  "
	@echo "********  addressSanitizer  *******"
	$(C_COMPILER) $(CFLAGS) -fsanitize=address -fno-omit-frame-pointer $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	./all_tests.out heap_leak
	./all_tests.out heap_buffer_overflow

clean:
	@echo "  "
	@echo "  "
	@echo "********  clean  *******"
	$(CLEANUP) $(TARGET1)
	rm -fr *.o *.dSYM *.gcda *.gcno *.gcov
	rm -f coverage/*.html
	cd sort && make clean

ci: CFLAGS += -Werror	cd sort && $(CLEANUP) $(TARGET1)
