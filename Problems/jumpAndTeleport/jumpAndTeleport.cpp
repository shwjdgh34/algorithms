#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n != 0)
    {
        while (n % 2 == 0)
        {
            n /= 2;
        }
        n -= 1;
        ans++;
    }
    return ans;
}
int main()
{
    int n = 5000;
    cout << solution(n) << endl;
}