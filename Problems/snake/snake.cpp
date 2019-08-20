#include <iostream>
#include <queue>
using namespace std;

#define APPLE 9
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
typedef struct
{
    int t; // time
    char changeD;

} Route;
typedef struct
{
    int x;
    int y;
} Pos;
void run();
int curD;
int map[102][102];
Route route[101];
int n, k, l;
int timeCount;
int main()
{

    cin >> n >> k;
    for (int i = 0; i < n + 2; i++)
    {
        if (i == 0 || i == n + 1)
        {
            for (int j = 0; j < n + 2; j++)
            {
                map[i][j] = -1;
            }
        }
        else
        {
            map[i][0] = -1;
            map[i][n + 1] = -1;
            for (int j = 1; j < n + 1; j++)
            {
                map[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = APPLE;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> route[i].t >> route[i].changeD;
    }
    run();
}
void run()
{
    queue<Pos> q;
    Pos head;
    head.x = 1;
    head.y = 1;
    q.push(head);
    curD = RIGHT;
    timeCount = 0;
    int r = 0;
    while (map[head.x][head.y] != -1)
    {
        Pos tail = q.front();
        q.pop();
        map[tail.x][tail.y] = 0;

        if (route[r].t == timeCount)
        {
            switch (route[r].changeD)
            {
            case 'D':
                curD = (curD + 1) % 4;
                break;
            case 'L':
                curD = (curD + 3) % 4;
                break;
            default:
            }
            r++;
        }
        switch (curD)
        {
        case RIGHT:
            head.y++;
            break;
        case LEFT:
            head.y--;
            break;
        case UP:
            head.x--;
            break;
        case DOWN:
            head.x++;
            break;
        default:
        }
        timeCount++;
        q.push(head);
    }
    cout << timeCount;
}
