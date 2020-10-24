# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors
ALL = identifier
GCC = gcc

all: $(ALL)

identifier: src/identifier.c
	$(GCC) $(GCCFLAGS) -o $@ src/$@.c

cov: identifier.c
	$(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o $@ identifier.c

clean:
	rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov

test: all
	bash test
