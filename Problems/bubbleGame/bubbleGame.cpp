#include <iostream>
#include <fstream>

using namespace std;

#define CROSSBUBBLE 7
#define BARRICADEBUBBLE 6
#define MOVE_LEFT 100
#define MOVE_RIGHT 200
typedef struct
{
    int x;
    int y;
} Pos;
void init(int width, int height);
int shoot(int bubbleType, int direction);
void move(int direction);
bool checkNear(Pos);
int howMany();

bool checkThreeBubble(Pos bubble, int bubbbleType);
void deleteBubble(Pos bubble, int bubbleType);
bool checkConnected(Pos bubble, int bubbleType);
void deleteUnconnectedBubble();
void crossBomb(Pos bubble);
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int map[22][12];
int shooterY; // 1~width까지
int Bwidth;
int Bheight;
Pos bubble;
int Bcount; // checkThreeBubble
bool visited[22][12];

int main(void)
{
    //setbuf(stdout, NULL);
    ifstream myfile("sample_input5.txt");
    int totalTC;
    int totalScore = 0;

    myfile >> totalTC;
    for (int tc = 1; tc <= totalTC; ++tc)
    {
        int boardWidth, boardHeight, bubbleCount;
        myfile >> boardWidth >> boardHeight >> bubbleCount;
        init(boardWidth, boardHeight);

        int score = 0;
        for (int i = 0; i < bubbleCount; ++i)
        {
            int d;
            while (1)
            {
                myfile >> d;
                if (d == MOVE_LEFT || d == MOVE_RIGHT)
                    move(d);
                else
                    break;
            }

            int bubbleType, answer, result;
            myfile >> bubbleType >> answer;
            result = shoot(bubbleType, d);
            if (answer == result)
            {
                ++score;
            }
        }
        score = score * 100 / bubbleCount;
        cout << "# " << tc << " " << score << endl;
        totalScore += score;
    }

    cout << "Total Score : " << totalScore / totalTC << endl;

    return 0;
}

void init(int width, int height)
{
    for (int i = 0; i <= width + 1; i++)
        map[0][i] = -1;
    for (int i = 0; i <= width + 1; i++)
        map[height + 1][i] = -1;
    for (int i = 1; i <= height; i++)
    {
        map[i][0] = -1;
        map[i][width + 1] = -1;
        for (int j = 1; j <= width; j++)
        {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            visited[i][j] = false;
        }
    }

    shooterY = 1;
    Bwidth = width;
    Bheight = height;
    bubble.x = height + 1;
}
int shoot(int bubbleType, int direction)
{
    bubble.y = shooterY;
    bubble.x = Bheight + 1;

    if (shooterY == 1 && direction == 0)
        return howMany();
    else if (shooterY == Bwidth && direction == 2)
        return howMany();
    else
    {
        while (1)
        {
            switch (direction)
            {
            case 0:

                bubble.x--;
                bubble.y--;
                if (bubble.y == 1) // 왼쪽벽에 부딪힌경우
                    direction = 2;
                break;
            case 1:
                bubble.x--;
                break;
            case 2:
                bubble.x--;
                bubble.y++;
                if (bubble.y == Bwidth) // 오른쪽벽에 부딪힌경우
                    direction = 0;
                break;
            }
            // 버블이랑 인접하거나 천장까지 도달했다면 break해주면 될듯!
            if (checkNear(bubble) || bubble.x == 1)
            {
                map[bubble.x][bubble.y] = bubbleType;
                //showMap();
                if (bubbleType == CROSSBUBBLE)
                {
                    crossBomb(bubble);
                    deleteUnconnectedBubble();
                }
                else if (checkThreeBubble(bubble, bubbleType))
                {
                    deleteBubble(bubble, bubbleType);
                    //showMap();
                    deleteUnconnectedBubble();
                    //showMap();
                }

                Bcount = 0;
                break;
            }
        }
    }
    return howMany();
}
void move(int d)
{
    if (d == MOVE_LEFT && shooterY > 1)
        shooterY--;
    if (d == MOVE_RIGHT && shooterY < Bwidth)
        shooterY++;
    return;
}

bool checkNear(Pos bubble)
{
    for (int i = 0; i < 8; i++)
    {
        Pos near;
        near.x = bubble.x + dx[i];
        near.y = bubble.y + dy[i];
        if (map[near.x][near.y] == -1)
            continue;
        else if (map[near.x][near.y] != 0)
        {
            return true;
        }
    }
    return false;
}
int howMany()
{
    int Bcount = 0;
    for (int i = 1; i <= Bheight; i++)
    {
        for (int j = 1; j <= Bwidth; j++)
        {

            if (map[i][j] != 0)
                Bcount++;
        }
    }
    return Bcount;
}

bool checkThreeBubble(Pos cur, int bubbleType)
{
    if (bubbleType == BARRICADEBUBBLE)
        return false; // 방해버블일 때는 세개 이상인지 체크하지 않으면 된다!
    visited[cur.x][cur.y] = true;
    Bcount++;
    for (int i = 0; i < 8; i++)
    {
        Pos next;
        next.x = cur.x + dx[i];
        next.y = cur.y + dy[i];
        if (map[next.x][next.y] == bubbleType && !visited[next.x][next.y])
        {
            checkThreeBubble(next, bubbleType);
        }
    }
    visited[cur.x][cur.y] = false;
    if (Bcount >= 3)
        return true;
    return false;
}
void deleteBubble(Pos cur, int bubbleType)
{
    visited[cur.x][cur.y] = true;
    map[cur.x][cur.y] = 0;

    for (int i = 0; i < 8; i++)
    {
        Pos next;
        next.x = cur.x + dx[i];
        next.y = cur.y + dy[i];
        if (map[next.x][next.y] == bubbleType && !visited[next.x][next.y])
        {
            deleteBubble(next, bubbleType);
        }
    }
    visited[cur.x][cur.y] = false;
}

bool checkConnected(Pos cur, int bubbleType)
{
    visited[cur.x][cur.y] = true;
    if (cur.x == 1)
    {
        visited[cur.x][cur.y] = false;
        return true;
    }

    for (int i = 0; i < 8; i++)
    {
        Pos next;
        next.x = cur.x + dx[i];
        next.y = cur.y + dy[i];
        if (next.x < 1 || next.y < 1 || next.x > Bheight || next.y > Bwidth)
            continue;
        if (map[next.x][next.y] != 0 && !visited[next.x][next.y])
        {
            if (checkConnected(next, bubbleType))
            {
                visited[cur.x][cur.y] = false;
                return true;
            }
        }
    }
    visited[cur.x][cur.y] = false;
    return false;
}
void deleteUnconnectedBubble()
{
    for (int i = 1; i <= Bheight; i++)
    {
        for (int j = 1; j <= Bwidth; j++)
        {
            if (map[i][j] == 0)
                continue;
            int bubbleType = map[i][j];
            if (!checkConnected({i, j}, bubbleType))
            {
                deleteBubble({i, j}, bubbleType); // 지금 이건 하나씩 지우는거다. 연결된것들은 한번에 delete하는 함수를 만들면 성능이 개선된다.
            }
        }
    }
}
void crossBomb(Pos bubble)
{
    for (int i = 1; i <= Bwidth; i++)
        map[bubble.x][i] = 0;
    for (int i = 0; i <= Bheight; i++)
        map[i][bubble.y] = 0;
}
