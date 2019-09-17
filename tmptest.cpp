#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string dartResult = "DFG";
    stringstream ss(dartResult);
    char c1;
    char c2;
    char c3;

    c1 = ss.get(); // c1 = D
    c2 = ss.get(); // c2 = F
    ss.unget();
    c3 = ss.get(); // c3 = F
    cout << c1 << c2 << c3 << endl;
}
