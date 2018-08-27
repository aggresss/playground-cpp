#include <iostream>
#include <string>
#include <vector>
using namespace std;
  
int main()
{
    vector<string> vec;
    
    vec.push_back("C++");
    vec.push_back("Java");
    vec.push_back("PHP");
    
    string* pStr = vec.data();
    for (size_t n = 0; n < vec.size(); n++, pStr++)
    {
        cout << "vec.data() = " << *pStr << endl;
    }
    return 0;
}
