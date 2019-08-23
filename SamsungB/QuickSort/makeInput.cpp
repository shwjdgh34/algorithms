#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#define TESTCASE 1
#define N 280000       // RANDMAX 보다 작아야 된다
#define RANDMAX 300000 // 3,000,000정도가 Max
using namespace std;
unsigned int randNum;
int main()
{
    if (RANDMAX <= N)
        throw "take lower N";
    srand((unsigned int)time(0));
    ofstream output("input.txt");
    output << TESTCASE << endl;

    for (int i = 0; i < TESTCASE; i++)
    {
        int n = 0;
        output << N << endl;
        while (n < N)
        {
            randNum = (rand()) % RANDMAX; // 중복 허용
            output << randNum << " ";
            n++;
        }
        output << endl;
    }
    return 0;
}