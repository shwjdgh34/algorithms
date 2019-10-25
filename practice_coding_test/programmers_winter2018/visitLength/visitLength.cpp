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
Pos move(char dir, Pos cur, int &count)
{
    switch (dir)
    {
    case 'U':
        if (cur.y >= 10)
            return cur;
        if (!(map[cur.x][cur.y] & U))
        {
            map[cur.x][cur.y] += U;
            count++;
        }
        cur.y += 1;
        break;
    case 'R':
        if (cur.x >= 10)
            return cur;
        if (!(map[cur.x][cur.y] & R))
        {
            map[cur.x][cur.y] += R;
            count++;
        }
        cur.x += 1;

        break;
    case 'D':
        if (cur.y <= 0)
            return cur;
        if (!(map[cur.x][cur.y] & D))
        {
            map[cur.x][cur.y] += D;
            count++;
        }
        cur.y -= 1;
        break;
    case 'L':
        if (cur.x <= 0)
            return cur;
        if (!(map[cur.x][cur.y] & L))
        {
            map[cur.x][cur.y] += L;
            count++;
        }
        cur.x -= 1;
        break;
    default:
        break;
    }
    return cur;
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