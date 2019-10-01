#include <iostream>
#include <vector>
using namespace std;

// true = 퀸이 놓여져 있음
// flase = 퀸이 없음
vector<vector<bool>> map;
bool check(int row, int col, int n)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (map[i][col])
            return false;
    }
    for (int i = 1; row - i >= 0 && col - i >= 0; i++)
    {
        if (map[row - i][col - i])
            return false;
    }
    for (int i = 1; row - i >= 0 && col + i < n; i++)
    {
        if (map[row - i][col + i])
            return false;
    }
    return true;
}
int nqueen(int n, int row)
{
    int answer = 0;

    if (row == n)
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (check(row, i, n))
        {
            map[row][i] = true;
            answer += nqueen(n, row + 1);
            map[row][i] = false;
        }
    }
    return answer;
}
int main()
{
    int n;
    cin >> n;
    map.assign(n, vector<bool>(n, false));
    cout << nqueen(n, 0) << endl;
}