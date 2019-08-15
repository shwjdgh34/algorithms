#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
#define INF 0x7FFFFFFFFFFFFFFF // INF for long long 'd'
#define HOME 1
typedef struct
{
    int h;       // house number
    int w;       // minimum weight => this will get summed
    long long d; // distance
} Info;

static bool operator<(const Info &a1, const Info &a2)
{
    return a1.d > a2.d;
}

void dijstra(int);
void init();
long long sumWeight();

int n, m;
int countUntilN; // <= 이 카운트가 n과 같아질때 이제 슬~ 슬 정리할 준비하면 될듯?마지막 node의 distance보다 pq에 저장되어있는 제일 작은 distance가 '커지는 순간' 종료하면 된다.
Info initInfo = {0, 0, INF};
Info info[200001]; // 각자의 노드는 자기랑 직접 연결되어 있는 노드와의 w만 저장ㄹ해주면된다. 이 w를 sum 해줄것이다.
vector<Info> graph[200001];

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
            graph[u].push_back({v, w, INF});
            graph[v].push_back({u, w, INF});
        }
        dijstra(HOME);

        printf("#%d %lld\n", testcase, sumWeight());
    }
    return 0;
}
void dijstra(int start)
{
    long long lastDistance = INF;
    priority_queue<Info> pq;
    pq.push({start, 0, 0});

    while (1)
    {
        Info cur = pq.top();
        pq.pop();
        if (info[cur.h].d == INF)
        {
            countUntilN++; // 아직 저장된 적이 없다면 count ++ count가 N이 되면 모두 한번씩 방문한거다.
            if (countUntilN == n)
            {
                lastDistance = cur.d;
            }
        }
        if (lastDistance < cur.d)
            return;
        if (info[cur.h].d >= cur.d)
            info[cur.h] = cur;

        // 이곳에서 sum은 진행해도 될듯 그게 더 빠를거같은데 일단 쉽게 이해할 수 있도록 sum()함수를 만들것이다.

        for (int i = 0; i < graph[cur.h].size(); i++)
        {
            Info next = graph[cur.h][i];

            if (next.d >= cur.d + next.w) // 등호를 넣어주는게 키포인트! 똑같은 거리라도 나중에 온걸로 갈아 치워야 한다. 그래야 w는 더 작은걸로 교체 되므로!
            {
                next.d = cur.d + next.w;
                pq.push(next);
            }
        }
    }
}
void init()
{
    countUntilN = 0;
    for (int i = 0; i <= 200000; i++)
    {
        info[i] = initInfo;
        graph[i].clear();
    }
}
long long sumWeight()
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (long long)info[i].w;
    }
    return sum;
}