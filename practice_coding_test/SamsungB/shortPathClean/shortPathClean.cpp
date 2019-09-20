#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
#define INF 0x7FFFFFFFFFFFFFFF // INF for long long 'd'
#define HOME 1
#define MAX_NODE 1000100
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
typedef struct _node
{
    GraphInfo data;
    struct _node *next;
} Node;
typedef struct
{
    int use;
    Node node;
} ListNodeArray;

ListNodeArray nodeArray[MAX_NODE];

void dijstra(int);
void init();
long long sumWeight();
Node *getNode();
void initListNode(Node *);

int nodeIdxCount;
int n, m;
int countUntilN; // <= 이 카운트가 n과 같아질때 이제 슬~ 슬 정리할 준비하면 될듯?마지막 node의 distance보다 pq에 저장되어있는 제일 작은 distance가 '커지는 순간' 종료하면 된다.
Info initInfo;
Info info[200001]; // 각자의 노드는 자기랑 직접 연결되어 있는 노드와의 w만 저장ㄹ해주면된다. 이 w를 sum 해줄것이다.
//vector<GraphInfo> graph[200001];

class linkedlist
{
private:
    Node *head;
    Node *tail;
    Node *cur;
    int size;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
        cur = NULL;
        size = 0;
    }
    GraphInfo getnext()
    {
        if (cur == NULL)
        {
            cur = head;
            return cur->data;
        }
        else
        {
            cur = cur->next;
            return cur->data;
        }
    }
    void add(GraphInfo newdata)
    {
        Node *tmp = getNode();
        tmp->data.h = newdata.h;
        tmp->data.w = newdata.w;
        tmp->next = NULL;
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
        size++;
    }
    int getSize()
    {
        return size;
    }
    void initCur()
    {
        cur = NULL;
    }
    void clear()
    {
        size = 0;
        head = NULL;
        cur = NULL;
        tail = NULL;
    }
};

linkedlist graph[200001];

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
            // graph[u].push_back({v, w});
            // graph[v].push_back({u, w});
            graph[u].add({v, w});
            graph[v].add({u, w});
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
        graph[cur.h].initCur();
        for (int i = 0; i < graph[cur.h].getSize(); i++)
        {

            GraphInfo next = graph[cur.h].getnext();

            if (info[next.h].d >= info[cur.h].d + next.w) // 등호를 넣어주는게 포인트! 똑같은 거리라도 나중에 온걸로 갈아 치워야 한다. 그래야 w는 더 작은걸로 교체 되므로!
            {
                if (info[next.h].d == info[cur.h].d + next.w && next.w >= info[next.h].minW)
                    continue;
                info[next.h].d = info[cur.h].d + next.w;
                info[next.h].minW = next.w;
                pq.push(next);
            }
        }
    }
}
void init()
{
    for (int i = 0; i < nodeIdxCount; i++)
    {
        nodeArray[i].use = 0;
    }
    nodeIdxCount = 0;
    countUntilN = 1;
    for (int i = 0; i <= n; i++)
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
Node *getNode()
{
    int whileCount = 0;
    while (whileCount < MAX_NODE)
    {
        whileCount++;
        if (nodeArray[nodeIdxCount].use == 0)
        {
            nodeArray[nodeIdxCount].use = 1;
            initListNode(&nodeArray[nodeIdxCount].node);
            return &nodeArray[nodeIdxCount].node;
        }
        nodeIdxCount++;
        if (nodeIdxCount == MAX_NODE)
        {
            nodeIdxCount = 0;
        }
    }
    throw "error";
}
void initListNode(Node *curNode)
{
    curNode->data.h = 0;
    curNode->data.w = 0;
    curNode->next = 0;
}