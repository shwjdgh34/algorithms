#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void check();
void init();
string s1, s2;
int numOfChar[30];
int ans;

int main()
{
    int T;
    ifstream myFile("sample_input.txt");
    myFile >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        init();
        int idx;
        myFile >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++)
        {
            int idx = s1[i] - 'a';
            numOfChar[idx]++;
        }
        int head = 0;
        int tail;
        for (tail = 0; tail < s1.size(); tail++)
        {
            idx = s2[tail] - 'a';
            numOfChar[idx]--;
        }
        tail--;
        check();
        for (int i = 0; i < s2.size() - s1.size(); i++)
        {
            idx = s2[head] - 'a';
            numOfChar[idx]++;
            head++;
            tail++;
            idx = s2[tail] - 'a';
            numOfChar[idx]--;
            check();
        }

        cout
            << "#" << testcase << " :"
            << ans << endl;
    }
}

void init()
{
    ans = 0;
    for (int i = 0; i < 30; i++)
        numOfChar[i] = 0;
}
void check()
{

    for (int i = 0; i < 30; i++)
    {
        if (numOfChar[i] != 0)
            return;
    }
    ans++;
}