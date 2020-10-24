# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors
ALL = cppcheck identifier
GCC = gcc

all: $(ALL)

identifier: identifier/src/identifier.c
	$(GCC) $(GCCFLAGS) -o identifier/$@ $<

cov: identifier/src/identifier.c
	cd identifier && $(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o $@ src/identifier.c

cppcheck: identifier/src/identifier.c
	cppcheck $<

clean:
	cd identifier && rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov

test: all
	bash test
