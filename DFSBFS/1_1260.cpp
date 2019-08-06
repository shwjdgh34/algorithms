// https://www.acmicpc.net/problem/1260
// DFS BFS 기초내용. 그래프를 직접 만들고 탑색해보는 기초적인 내용

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> graph[1001];

void bfs(int start);
void dfs();
int main()
{
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v); // 이걸 생각못했다. 양방향임을 인지 못하고 해당 코드를 작성하지 않았다.
    }
    // 방문할 수 있는 정점이 여러 개인 경우 정점 번호가 작은 것을 먼저 방문한다고 했으니
    // sorting을 하여 정렬해주자!
    // sorting 종류들공부하기! 직접 코딩할 수 있게 하자
    // begin과 end에 대해서:
    // begin() 함수는 벡터의 데이터가 있는 리스트의 시작 주소를 리턴하는데, 첫 번째 값 위치입니다.
    // end() 함수는 리스트의 끝 주소를 리턴하는데, 마지막 값보다 한 칸 뒤 위치의 값을 리턴합니다.

    for (int i = 0; i < n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    bfs(start);
}
void bfs(int start)
{
    bool discovered[1001] = {
        0,
    }; // 배열을 0으로 초기화 하고 싶을 때 쓰는 방법(참조 https://www.uwangg.com/36)
    queue<int> q;
    discovered[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!discovered[next])
            {
                discovered[next] = true;
                q.push(next);
            }
        }
    }
}
