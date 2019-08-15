// Dijstra
#if 1
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#define INF 0x7fffffff
#define TRUE 1
#define FALSE 0
using namespace std;

typedef struct
{
    int d;
    int x;
    int y;
} Info;
static bool operator<(const Info &a1, const Info &a2)
{
    return a1.d > a2.d;
}
typedef struct
{
    int arr[101][101];
} Arr;
Arr initArr;
Arr costMap;
Arr dist;
Arr visited;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;

void init();
bool inRange(Info next);
int dijstra(Info);

int main()
{
    int T;

    ifstream myFile("input.txt");
    if (myFile.fail())
    {
        throw "Failed to open input.txt";
    }
    myFile >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        string tmp;
        init();
        myFile >> n;
        for (int i = 0; i < n; i++)
        {
            myFile >> tmp;
            for (int j = 0; j < n; j++)
            {

                costMap.arr[i][j] = tmp[j] - '0';
                dist.arr[i][j] = INF;
            }
        }
        Info start;
        start.x = 0;
        start.y = 0;
        start.d = 0;
        cout << "#" << testcase << " :" << dijstra(start) << endl;
    }
}
void init()
{
    costMap = initArr;
    dist = initArr;
    visited = initArr;
}
int dijstra(Info start)
{
    priority_queue<Info> pq;

    dist.arr[start.x][start.y] = 0;
    pq.push(start);
    int tmp = 0;
    while (1)
    {

        Info cur;
        cur = pq.top();
        pq.pop();
        // if(visited.arr[cur.x][cur.y]) continue; 이거 있어야되는거 아닌가?
        visited.arr[cur.x][cur.y] = TRUE;
        if (cur.x == n - 1 && cur.y == n - 1)
            return dist.arr[n - 1][n - 1];
        for (int i = 0; i < 4; i++)
        {
            Info next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            if (visited.arr[next.x][next.y]) // visited 가 굳이 필요할까?? 어차피 최소 거리기 때문에 pq에 push 할 일 없지 않나 visited 안해줘도?
                continue;
            if (inRange(next) && dist.arr[next.x][next.y] > costMap.arr[next.x][next.y] + dist.arr[cur.x][cur.y])
            {
                dist.arr[next.x][next.y] = costMap.arr[next.x][next.y] + dist.arr[cur.x][cur.y];
                next.d = dist.arr[next.x][next.y];
                pq.push(next);
            }
        }
    }
    return INF;
}
#endif

bool inRange(Info next)
{
    if (next.x >= 0 && next.y >= 0 && next.x < n && next.y < n)
        return true;
    return false;
}
// BFS
#if 0
#include <iostream>
#define INF 0x7fffffff
#define QUEUE_SIZE 100000 // Q.크기 정하는 합리적인 근거?!
using namespace std;
void init();
void input();
void BFS(int, int);
bool checkRange(int, int);

typedef struct // this is for initialization on Samsung swtest which dont allow any library
{
    int arr[101][101];
} Arr;

Arr map;
Arr dist;
Arr init_arr;
int queueX[QUEUE_SIZE];
int queueY[QUEUE_SIZE];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

int main()
{

    int T;
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        init();
        input();
        BFS(0, 0);
        cout << "#" << testcase << ": " << dist.arr[n - 1][n - 1] << endl;
    }
}

void init()
{
    for (int i = 0; i < QUEUE_SIZE; i++) // Not essential
    {
        queueX[i] = 0;
        queueY[i] = 0;
    }
    map = init_arr;
    dist = init_arr;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &map.arr[i][j]);
            dist.arr[i][j] = INF;
        }
    }
}

void BFS(int start_x, int start_y)
{
    int front = 0;
    int rear = 0;
    queueX[rear] = start_x;
    queueY[rear] = start_y;
    dist.arr[0][0] = 0;
    rear = (rear + 1) % QUEUE_SIZE;

    while (front != rear)
    {
        int curX = queueX[front];
        int curY = queueY[front];
        front = (front + 1) % QUEUE_SIZE;
        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (checkRange(nextX, nextY) &&
                (dist.arr[nextX][nextY] > dist.arr[curX][curY] + map.arr[nextX][nextY]))
            {
                dist.arr[nextX][nextY] = dist.arr[curX][curY] + map.arr[nextX][nextY];
                queueX[rear] = nextX;
                queueY[rear] = nextY;
                rear = (rear + 1) % QUEUE_SIZE;
            }
        }
    }
}

bool checkRange(int x, int y) // Check whether in or out of range
{
    if (x >= 0 && y >= 0 && x < n && y < n)
        return true;
    return false;
}
#endif