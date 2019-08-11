#include <iostream>
#include <string>
#include <cstring>

using namespace std;
void init();
bool dfs(int x, int y);
int dp(int x, int y);
void showmap();
typedef struct
{
    int arr[101][101];

} Arr;
Arr map;
Arr initArr;
Arr routeMap;
Arr cacheMap;

int n;
int routeCount;

int main()
{

    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        init();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map.arr[i][j];
            }
        }

        string ans = dp(0, 0) ? "YES" : "NO";
        //string ans = dfs(0, 0) ? "YES" : "NO";

        cout << ans << endl;
        //showmap();
    }
}
void init()
{
    routeCount = 0;
    map = initArr;
    //    routeMap = initArr;
    memset(cacheMap.arr, -1, sizeof(cacheMap.arr));
}

bool dfs(int x, int y)
{
    // basecase : 게임판 범위를 벗어난 경우
    if (x >= n || y >= n)
        return false;
    // basecase : 마지막칸에 도착한 경우
    if (x == n - 1 && y == n - 1)
        return true;
    int jumpSize = map.arr[x][y];
    return dfs(x + jumpSize, y) || dfs(x, y + jumpSize); // readme작성
}

int dp(int x, int y)
{
    // basecase : 게임판 범위를 벗어난 경우
    if (x >= n || y >= n)
        return 0;
    // basecase : 마지막칸에 도착한 경우
    if (x == n - 1 && y == n - 1)
    {
        // routeCount = 1;
        // routeMap.arr[x][y] = routeCount;

        return 1;
    }
    int jumpSize = map.arr[x][y];
    int &ret = cacheMap.arr[x][y]; // 배열을 계속 쓰면 인덱스 실수나 의미가 점점 애매해져서 reference 변수로 참조하는게 더 좋다.
    if (ret == -1)
    {

        return ret = dp(x + jumpSize, y) || dp(x, y + jumpSize);
        // ret = dp(x + jumpSize, y) || dp(x, y + jumpSize);
        // if (ret == 1)
        //     routeCount++;
        // routeMap.arr[x][y] = routeCount;
        // return ret;
    }

    return ret;
}
void showmap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << routeMap.arr[i][j] << " ";
        }
        cout << endl;
    }
}