# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors
GCC = gcc
ALL = cppcheck identifier

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

test: all
	bash test
