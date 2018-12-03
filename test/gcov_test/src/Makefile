all:
	# generate cno file
	gcc -fprofile-arcs -ftest-coverage gcov_test.c -o gcov_test.out
	# generate cda file
	./gcov_test.out
	# generate gcov file
	gcov -b gcov_test.c
	gcov gcov_test.c
clean:
	rm -rf *.out *.gcov *.gcno *.gcda
