#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << endl;
}
