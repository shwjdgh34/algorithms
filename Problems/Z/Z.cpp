#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// zigzag 0->1->2->3 순서
typedef struct
{
    int r;
    int c;
} Pos;
int answer = 0;
Pos target;
int zRecur(int nSize, Pos curTarget)
{

    if (nSize == 0)
    {
        return answer;
    }
    int nextN = nSize - 1;
    if (curTarget.r / (1 << nextN) == 0 && curTarget.c / (1 << nextN) == 0)
    {
        zRecur(nextN, curTarget);
    }

    else if (curTarget.r / (1 << nextN) == 0 && curTarget.c / (1 << nextN) == 1)
    {
        answer += 1 << 2 * nextN;
        zRecur(nextN, {curTarget.r, curTarget.c % (1 << nextN)});
    }

    else if (curTarget.r / (1 << nextN) == 1 && curTarget.c / (1 << nextN) == 0)
    {
        answer += 2 << 2 * nextN;
        zRecur(nextN, {curTarget.r % (1 << nextN), curTarget.c});
    }

    else if (curTarget.r / (1 << nextN) == 1 && curTarget.c / (1 << nextN) == 1)
    {
        answer += 3 << 2 * nextN;
        zRecur(nextN, {curTarget.r % (1 << nextN), curTarget.c % (1 << nextN)});
    }

    return answer;
};
int main()
{
    int n;

    int r, c;
    cin >> n >> r >> c;
    target = {r, c};

    cout << zRecur(n, target);
}
