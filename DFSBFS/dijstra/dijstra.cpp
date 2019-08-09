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