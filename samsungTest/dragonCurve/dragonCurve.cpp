#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;
#define RIGHT 0
#define UP 1
#define LEFT 2
#define DOWN 3
int map[101][101];
int dragonCurve(int n, vector<vector<int>> input);
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> input(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> input[i][j];
        }
    }
    cout << dragonCurve(n, input) << endl;
}

int dragonCurve(int n, vector<vector<int>> input)
{
    int answer = 0;
    vector<int> newS;
    vector<int> tmpS;

    for (int i = 0; i < n; i++)
    {
        int g = input[i][3];
        int d = input[i][2];
        int x = input[i][0];
        int y = input[i][1];
        newS.push_back(d);
        for (int j = 0; j < g; j++)
        {
            tmpS = newS;
            while (!tmpS.empty())
            {
                newS.push_back((tmpS.back() + 1) % 4);
                tmpS.pop_back();
            }
        }
        map[x][y] = 1;
        for (int j = 0; j < newS.size(); j++)
        {
            int curD = newS[j];
            switch (curD)
            {
            case RIGHT:
                x = x + 1;
                break;
            case UP:
                y = y - 1;
                break;
            case LEFT:
                x = x - 1;
                break;
            case DOWN:
                y = y + 1;
                break;
            default:
                break;
            }
            map[x][y] = 1;
        }
        newS.clear();
        tmpS.clear();
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {

            if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
                answer++;
        }
    }
    return answer;
}
