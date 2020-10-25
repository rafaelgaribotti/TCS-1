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

CFLAGS=-std=c99
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
  identifier/src/identifier.c \
	identifier/test/TestIdentifier.c \
  identifier/test/test_runners/TestIdentifier_Runner.c \
  identifier/test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=
all: clean cppcheck compile valgrind clean cppcheck compile addressSanitizer run cov

cppcheck:
	@echo "  "
	@echo "  "
	@echo "********  cppcheck  *******"
	cppcheck identifier/src/identifier.c

compile:
	@echo "  "
	@echo "  "
	@echo "********  compile  *******"
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

run: 
	@echo "  "
	@echo "  "
	@echo "********  run  *******"
	./$(TARGET1) -v

valgrind:
	@echo "  "
	@echo "  "
	@echo "********  valgrind  *******"
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET1)

cov: 
	@echo "  "
	@echo "  "
	@echo "********  cov  *******"
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -fprofile-arcs -ftest-coverage -o cov

addressSanitizer:
	@echo "  "
	@echo "  "
	@echo "********  addressSanitizer  *******"
	$(C_COMPILER) $(CFLAGS) -fsanitize=address $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

clean:
	@echo "  "
	@echo "  "
	@echo "********  clean  *******"
	$(CLEANUP) $(TARGET1)
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov

ci: CFLAGS += -Werror	cd identifier && $(CLEANUP) $(TARGET1)
