#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define MAXSIZE 1001

using namespace std;

// 구조체는 value type이라서 assign하면 값을 copy 하기 때문에초기화가 엄청 쉽다. 배열은 reference type이라서 assign이 불가하다.

typedef struct
{
    bool arr[MAXSIZE];
} Arr;

// to check answer
void answer_check(int your_answer);
void print_answer();
void bfs_queue(int);
void dfs_stack(int);
void dfs_recursive(int);

//initialize 해줘야 할 부분!!!!!
bool answer = true;
vector<int> graph[MAXSIZE];
vector<int> init_graph[MAXSIZE];
Arr init_arr;
Arr check;
int n, m, start;

int main()
{
    int test_case;
    int T;
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        // initialize
        cin >> n >> m >> start;
        for (int i = 0; i < m; i++)
        {
            int v, u;
            cin >> v >> u;
            graph[v].push_back(u);
            // 양방향임을 인지 못하고 아래 코드를 작성하지 않았다.
            graph[u].push_back(v);
        }
        // 방문할 수 있는 정점이 여러 개인 경우 정점 번호가 작은 것을 먼저 방문한다고 했기 때문에 오른차순 정렬을 해준다.
        for (int i = 0; i < n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
        }

        printf("# %d testcase\n", T);

        printf("dfs:");
        check = init_arr;
        dfs_recursive(start);
        //dfs_stack(start); // u can choose one between dfs_recursive and _stack
        print_answer();

        printf("bfs:");
        check = init_arr; // initialize, 구조체라서 가능한 배열 초기화 방식
        bfs_queue(start);
        print_answer();

        for (int i = 1; i <= n; i++)
        {
            graph[i].clear(); //graph 초기화
        }
    }
    return 0;
}
void bfs_queue(int start)
{
    queue<int> q;
    check.arr[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        answer_check(cur);

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!check.arr[next])
            {
                check.arr[next] = true;
                q.push(next);
            }
        }
    }
}

void dfs_stack(int start)
{
    stack<int> s;
    s.push(start);
    check.arr[start] = true;
    printf("%d ", start);
    answer_check(start);

    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!check.arr[next])
            {
                printf("%d ", next);
                answer_check(next);
                check.arr[next] = true;
                // cur 먼저 해줘야지 다음에 다시 돌아온다.(recursive)
                s.push(cur);
                s.push(next);
                // 이걸 해줘야 next로 가게 된다. 이걸 계속 빠뜨리는 실수를 자주 저지름
                break;
            }
        }
    }
}
void dfs_recursive(int cur)
{
    //check = init_arr; // 재귀함수기 때문에 이곳에 초기화를 하면 안된다!!!!
    printf("%d ", cur);
    check.arr[cur] = true;
    answer_check(cur);
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (!check.arr[next])
        {
            check.arr[next] = true;
            dfs_recursive(next);
        }
    }
}
void answer_check(int your_answer)
{
    int tempCin;
    cin >> tempCin;
    if (tempCin != your_answer)
        answer = false;
}
void print_answer()
{
    printf(answer ? " => true\n" : " => false\n");
    answer = true;
}
