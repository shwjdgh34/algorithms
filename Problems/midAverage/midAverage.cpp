#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++)
    {
        int answer;
        int sum = 0;
        int min = 100000;
        int max = 0;
        int tmp;
        for (int i = 0; i < 10; i++)
        {
            cin >> tmp;
            sum += tmp;
            if (tmp < min)
                min = tmp;
            if (tmp > max)
                max = tmp;
        }
        sum -= min + max;
        answer = (int)round((double)sum / 8);

        printf("#%d %d\n", t, answer);
    }
}
