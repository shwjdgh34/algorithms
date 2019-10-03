#include <iostream>
#include <string>
#include <vector>

using namespace std;
int comb[60001][60001];
int combination(int n, int r)
{
    if (r == n || r == 0)
        comb[n][r] = 1;
    if (comb[n][r] == 0)
        comb[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
    return comb[n][r];
}
int solution(int n)
{
    int answer = 0;
    int r = n;
    while (r >= 0)
    {

        answer += combination(n, r);
        r -= 2;
        n -= 1;
    }
    return answer;
}
int main()
{
    int n = 4;
    cout << solution(n) << endl;
}