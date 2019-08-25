#include <string>
#include <vector>

using namespace std;
void dfs(vector<vector<int>> v, vector<bool> &visited, int idx)
{
    for (int i = 0; v[idx].size(); i++)
    {
        int next = v[idx][i];
        if (visited[next] == false)
        {
            dfs(v, visited, next);
            visited[next] = true;
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<vector<int>> v(computers.size());
    vector<bool> visited(computers.size());

    for (int i = 0; i < computers.size(); i++)
    {

        visited[i] = false;
    }
    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (i == j)
                continue;
            if (computers[i][j] == 1)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < computers.size(); i++)
    {
        if (visited[i] == false)
        {
            dfs(v, visited, i);
            visited[i] = true;
            answer++;
        }
    }

    return answer;
}
int main()
{
    vector<vector<int>> computers(3, vector<int>(3));
    // {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}
    computers[0][0] = 1;
    computers[0][1] = 1;
    computers[0][2] = 0;
    computers[1][0] = 1;
    computers[1][1] = 1;
    computers[1][2] = 0;
    computers[2][0] = 0;
    computers[2][1] = 0;
    computers[2][2] = 1;

    int n;
    printf("%d\n", solution(n, computers));
    return 0;
}