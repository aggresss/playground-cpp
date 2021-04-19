all:
	# generate cno file by arg: -ftest-coverage
	gcc -fprofile-arcs -ftest-coverage gcov_test.c -o gcov_test.out
	# generate cda file by arg: -fprofile-arcs
	./gcov_test.out
	# generate gcov file
	gcov -b gcov_test.c
	gcov gcov_test.c
clean:
	rm -rf *.out *.gcov *.gcno *.gcda
