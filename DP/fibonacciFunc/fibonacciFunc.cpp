#include <iostream>
#define SIZE 41
using namespace std;

/*
typedef struct
{
    int zeroNum;
    int oneNum;
    bool visited;

} Ans;
Ans cache[41];
*/
int fibonacciFunc(int x);
// void fibonacciFunc(int x);
void init();
int cache[SIZE + 1];
int main()
{
    int T;

    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        init();
        int n;
        cin >> n;
        fibonacciFunc(n + 1);
        // cout << cache[n].zeroNum << " " << cache[n].oneNum << endl;
        cout << cache[n] << " " << cache[n + 1] << endl;
    }
}
void init()
{

    for (int i = 0; i < SIZE + 1; i++)
    {
        cache[i] = -1;
    }
    //basecase
    cache[0] = 1;
    cache[1] = 0;
}
int fibonacciFunc(int x)
{
    if (cache[x] != -1)
        return cache[x];
    return cache[x] = fibonacciFunc(x - 1) + fibonacciFunc(x - 2);
}
/*
void init()
{
    for (int i = 0; i < 41; i++)
    {
        cache[i].zeroNum = -1;
        cache[i].oneNum = -1;
        cache[i].visited = false;
    }
    return;
}
void fibonacciFunc(int x)
{
    //basecase
    if (x == 0)
    {
        cache[x].zeroNum = 1;
        cache[x].oneNum = 0;
        cache[x].visited = true;
        return;
    }
    if (x == 1)
    {
        cache[x].zeroNum = 0;
        cache[x].oneNum = 1;
        cache[x].visited = true;
        return;
    }

    if (!cache[x].visited)
    {
        fibonacciFunc(x - 1);
        fibonacciFunc(x - 2);
        cache[x].zeroNum = cache[x - 1].zeroNum + cache[x - 2].zeroNum;
        cache[x].oneNum = cache[x - 1].oneNum + cache[x - 2].oneNum;
        cache[x].visited = true;
        return;
    }

    return;
}
*/