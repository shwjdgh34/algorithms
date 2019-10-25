#include <string>
#include <iostream>

#define U 1
#define R 2
#define D 4
#define L 8

using namespace std;
typedef struct
{
    int x;
    int y;
} Pos;
int map[11][11];
bool range(Pos cur)
{
    if (cur.x > 10 || cur.x < 0 || cur.y > 10 || cur.y < 0)
        return false;
    return true;
}

Pos move(char dir, Pos cur, int &count)
{
    Pos next = cur;
    switch (dir)
    {
    case 'U':
        next.y += 1;
        if (!range(next))
            return cur;

        if (!(map[cur.x][cur.y] & U))
        {
            map[cur.x][cur.y] += U;
            map[next.x][next.y] += D;
            count++;
        }
        break;
    case 'R':
        next.x += 1;
        if (!range(next))
            return cur;

        if (!(map[cur.x][cur.y] & R))
        {
            map[cur.x][cur.y] += R;
            map[next.x][next.y] += L;
            count++;
        }
        break;
    case 'D':
        next.y -= 1;
        if (!range(next))
            return cur;
        if (!(map[cur.x][cur.y] & D))
        {
            map[cur.x][cur.y] += D;
            map[next.x][next.y] += U;
            count++;
        }
        break;
    case 'L':
        next.x -= 1;
        if (!range(next))
            return cur;
        if (!(map[cur.x][cur.y] & L))
        {
            map[cur.x][cur.y] += L;
            map[next.x][next.y] += R;
            count++;
        }
        break;
    default:
        break;
    }
    return next;
}
int solution(string dirs)
{
    int answer;
    // start point : 5,5
    Pos cur = {5, 5};

    for (int i = 0; i < dirs.size(); i++)
    {
        cur = move(dirs[i], cur, answer);
    }
    return answer;
}

int main()
{
    string dirs = "ULURRDLLU";
    cout << solution(dirs);
}