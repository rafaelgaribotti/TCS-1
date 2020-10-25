# Travis example for Identifier created by Rafael Garibotti
# Updated by Samuel Finatto and Luís Becker
GCCFLAGS = -g -Wall -Wfatal-errors
GCC = gcc
ALL = cppcheck identifier
MAKETESTS =

all: $(ALL)

identifier: identifier/src/identifier.c
	$(GCC) $(GCCFLAGS) -o identifier/$@ $<

cov:
	cd identifier && $(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o identifier identifier/src/identifier.c

cppcheck:
	cppcheck identifier/src/identifier.c --error-exitcode=1

valgrid: identifier
	valgrind --leak-check=full --show-leak-kinds=all identifier/identifier

addressSanitizer:
	$(GCC) $(GCCFLAGS) -fsanitize=address identifier/src/identifier.c -o identifier/identifier
	./identifier/identifier

clean:
	cd identifier && rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov
	cd identifier && make clean

test:
	cd identifier && make
