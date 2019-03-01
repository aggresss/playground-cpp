# Makefile (advanced) for a "Hello World" program
SHELL = /bin/sh
# clear and redefine suffix list:
.SUFFIXES:
.SUFFIXES: .o .cxx .hxx

NAME=helloworld
CXX=g++
BINDIR=/usr/local/bin
#added:
OBJECTS=hello.o world.o main.o		

all: $(NAME)				

clean:
	rm -f $(NAME)
	rm -f $(OBJECTS)

install: $(NAME)
	cp $(NAME) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/$(NAME)

# changed:
$(NAME): $(OBJECTS)			
	$(CXX) -o $(NAME) $(OBJECTS)	

# changed:
%.o:	%.cxx 	%.hxx				
	$(CXX) -c $< -o $@              

main.o:	main.cxx				
	$(CXX) -c $< -o $@              
