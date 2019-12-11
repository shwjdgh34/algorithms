#include <iostream>

using namespace std;
int fibonacciFunc(int n, int prev, int prevPrev)
{
    if (n == 1)
        return prevPrev;

    else
        return fibonacciFunc(n - 1, prev + prevPrev, prev);
}
int main()
{
    while (1)
    {
        int n;
        cin >> n;
        cout << fibonacciFunc(n, 1, 0);
    }
}