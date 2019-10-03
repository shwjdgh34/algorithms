#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dp[60001];

int solution(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    if (dp[n] == 0)
        dp[n] = solution(n - 1) + solution(n - 2);
    dp[n] %= 1000000007;
    return dp[n];
}
int main()
{
    int n = 4;
    cout << solution(n) << endl;
}