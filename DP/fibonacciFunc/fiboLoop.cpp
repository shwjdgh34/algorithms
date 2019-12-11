#include <iostream>

using namespace std;
int fibonacciFunc(int n)
{
    int prev, prevPrev, cur;
    if (n == 1)
    {
        cout << 0 << ' ';
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << ' ';
        return 1;
    }
    prev = 0;
    prevPrev = 1;
    for (int i = 3; i <= n; i++)
    {
        cur = prev + prevPrev;
        prevPrev = prev;
        prev = cur;
        cout << cur << ' ';
    }
    return cur;
}
int main()
{

    int n;
    cin >> n;
    fibonacciFunc(n + 1);
    //cout << fibonacciFunc(n + 1) << endl;
}