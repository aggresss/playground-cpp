#include <iostream>
using namespace std;

int main(void) {
	int variable = 21;
	const int* const_p = &variable;
    // int* modifier = const_p;
	int* modifier = const_cast<int *>(const_p);

	*modifier = 7;
	cout << "variable:" << variable << endl;

	return 0;
}
