#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
#define INF 0x7FFFFFFFFFFFFFFF // INF for long long 'd'
#define HOME 1
typedef struct
{
    int minW;    // minimum weight => this will get summed
    long long d; // distance
} Info;
typedef struct
{
    int h; // house
    int w;
} GraphInfo;

void dijstra(int);
void init();
long long sumWeight();

int n, m;
int countUntilN; // <= 이 카운트가 n과 같아질때 이제 슬~ 슬 정리할 준비하면 될듯?마지막 node의 distance보다 pq에 저장되어있는 제일 작은 distance가 '커지는 순간' 종료하면 된다.
Info initInfo;
Info info[200001]; // 각자의 노드는 자기랑 직접 연결되어 있는 노드와의 w만 저장ㄹ해주면된다. 이 w를 sum 해줄것이다.
vector<GraphInfo> graph[200001];

static bool
operator<(const GraphInfo &a1, const GraphInfo &a2)
{
    return info[a1.h].d > info[a2.h].d;
}
int main()
{
    ifstream myFile("sample_input.txt");

    int T;
    myFile >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        myFile >> n >> m;
        init();

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            myFile >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        dijstra(HOME);

        printf("#%d %lld\n", testcase, sumWeight());
    }
    return 0;
}
void dijstra(int start)
{
    long long lastDistance = INF;
    priority_queue<GraphInfo> pq;

    pq.push({start, 0});
    info[HOME].d = 0;
    while (!pq.empty())
    {
        GraphInfo cur = pq.top();
        pq.pop();

        for (int i = 0; i < graph[cur.h].size(); i++)
        {
            GraphInfo next = graph[cur.h][i];

            if (info[next.h].d >= info[cur.h].d + next.w) // 등호를 넣어주는게 포인트! 똑같은 거리라도 나중에 온걸로 갈아 치워야 한다. 그래야 w는 더 작은걸로 교체 되므로!
            {
                info[next.h].d = info[cur.h].d + next.w;
                info[next.h].minW = next.w;
                pq.push(next);
            }
        }
    }
}
void init()
{
    countUntilN = 1;
    for (int i = 0; i <= 200000; i++)
    {
        info[i].d = INF;
        info[i].minW = 0;
        graph[i].clear();
    }
}
long long sumWeight()
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (long long)info[i].minW;
    }
    return sum;
}