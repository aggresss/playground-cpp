all:
	gcc args.c mygetopt.c -o arg_test.out
test: all
	./arg_test.out -idh192.168.1.1 -p3456 -u admin -w admin
clean:
	rm -rf *.out

