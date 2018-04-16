#include "hello.hxx"
#include "world.hxx"
#include "config.h" // added

int main()
{
	hello first_word;
	world second_word;

	std::cout<<PACKAGE_STRING<<" "; // added
	first_word.print();
	second_word.print();
	return 0;
}
