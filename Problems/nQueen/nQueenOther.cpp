#include <iostream>
#include <cmath>
using namespace std;
int queen[17];
int N;
int cnt;
bool isPossible(int nextRow)
{
    for (int i = nextRow - 1; i >= 0; i--)
    {
        if (queen[i] == queen[nextRow] || (nextRow - i) == (abs(queen[i] - queen[nextRow])))
            return false;
    }
    return true;
}
void dfs(int row)
{
    if (row == N - 1)
    {
        cnt++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            queen[row + 1] = i;
            if (isPossible(row + 1))
            {
                dfs(row + 1);
            }
        }
    }
}
int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        queen[0] = i;
        dfs(0);
    }
    cout << cnt;
    return 0;
}