# Makefile (simple) for a "Hello World" program
SHELL = /bin/sh

NAME=helloworld
CXX=g++
BINDIR=/usr/local/bin

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f hello.o world.o main.o

install: $(NAME)
	cp $(NAME) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/$(NAME)

$(NAME): hello.o world.o main.o
	$(CXX) -o $(NAME) hello.o world.o main.o

hello.o: hello.cxx hello.hxx
	$(CXX) -c hello.cxx

world.o: world.cxx world.hxx
	$(CXX) -c world.cxx

main.o:	main.cxx
	$(CXX) -c main.cxx
