#include <iostream>
#include <fstream>

using namespace std;

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
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int map[22][12];
int shooterY; // 1~width까지
int Bwidth;
int Bheight;
Pos bubble;
int bubbleCount; // checkThreeBubble
bool visited[22][12];

int main(void)
{
    //setbuf(stdout, NULL);
    ifstream myfile("sample_input2.txt");
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
            //           showMap(bubble, bubbleType);
            // 버블이랑 인접하거나 천장까지 도달했다면 break해주면 될듯!
            if (checkNear(bubble) || bubble.x == 1)
            {
                map[bubble.x][bubble.y] = bubbleType;
                if (checkThreeBubble(bubble, bubbleType))
                {
                    deleteBubble(bubble, bubbleType);
                }

                bubbleCount = 0;
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
    int count = 0;
    for (int i = 1; i <= Bheight; i++)
    {
        for (int j = 1; j <= Bwidth; j++)
        {

            if (map[i][j] != 0)
                count++;
        }
    }
    return count;
}

bool checkThreeBubble(Pos cur, int bubbleType)
{
    visited[cur.x][cur.y] = true;
    bubbleCount++;
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
    if (bubbleCount >= 3)
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