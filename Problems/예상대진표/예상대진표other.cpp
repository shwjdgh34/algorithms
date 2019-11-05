#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b)
    {
        a = (a + 1) >> 1; // 2 1 1
        b = (b + 1) >> 1; // 4 2 1
        ++answer;
    }

    return answer;
}

int main()
{
    cout << solution(8, 4, 7);
}