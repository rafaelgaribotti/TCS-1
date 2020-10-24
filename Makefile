# Travis example for Identifier created by Rafael Garibotti

GCCFLAGS = -g -Wall -Wfatal-errors -fsanitize=address
ALL = identifier
GCC = gcc

all: $(ALL)

identifier: identifier/src/identifier.c
	cppcheck $<
	$(GCC) $(GCCFLAGS) -o identifier/$@ $<
	valgrind --leak-check=full --show-leak-kinds=all ./identifier/$@

cov: identifier/src/identifier.c
	cd identifier && $(GCC) $(GCCFLAGS) -fprofile-arcs -ftest-coverage -o $@ src/identifier.c

clean:
	cd identifier && rm -fr $(ALL) *.o cov* *.dSYM *.gcda *.gcno *.gcov

test: all
	bash test
