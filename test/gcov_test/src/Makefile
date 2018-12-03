all:
	gcc -fprofile-arcs -ftest-coverage gcov_test.c -o gcov_test.out
	./gcov_test.out
	gcov -b gcov_test.c
	gcov gcov_test.c
clean:
	rm -rf *.out *.gcov *.gcno *.gcda
