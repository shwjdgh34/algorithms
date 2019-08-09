# Graph, DFS, BFS에 대한 기초내용

문제 : <백준 1260번 DFS와 BFS> <br/>
<https://www.acmicpc.net/problem/1260>

- [Graph, DFS, BFS에 대한 기초내용](#graph-dfs-bfs%ec%97%90-%eb%8c%80%ed%95%9c-%ea%b8%b0%ec%b4%88%eb%82%b4%ec%9a%a9)
  - [File read](#file-read)
  - [DFS](#dfs)
  - [BFS](#bfs)
  - [Vector](#vector)
  - [Array](#array)
  - [KeepInMind](#keepinmind)

## File read

- 1.1 If you have a lot of inputs, you better use 'std::freopen()
> Sometimes freopen( ) cant be used. Must use freopen_s() due to a safety problem. But you dont like this, just use <fstream.h>

```C++
freopen("input.txt", "r", stdin);
```

- 1.2 In C++, <fstream.h> 
```C++
#include <fstream.h>
int main(){
    int n;
    ifstream myText("input.txt");
    if(myText.fail()){
        cout<< "File stream error" << endl;
        return -1;
    }
    myText >> n ;
    myText.close();
}
```


## DFS

- 2.1 DFS by stack

```C++
void dfs_stack(int start)
{
    stack<int> s;
    s.push(start);
    check.arr[start] = true;
    printf("%d ", start);

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
                check.arr[next] = true;
                s.push(cur);
                s.push(next);
                break;
            }
        }
    }
}
```

- 2.2 DFS by recursive

```C++
void dfs_recursive(int cur)
{
    //check = init_arr; // 재귀함수기 때문에 이곳에 초기화를 하면 안된다!!!!
    printf("%d ", cur);
    check.arr[cur] = true;
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
```

## BFS

- 3.1 BFS by queue

```C++
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
```

## Vector

- 4.1 Re-initialize

```C++

vector<int> graph[MAXSIZE];

for (int i = 0; i < MAXSIZE; i++)
{
    graph[i].clear();
}
```

- 4.2 .begin & .end

> begin() 함수는 벡터의 데이터가 있는 리스트의 시작 주소를 리턴하는데, 첫 번째 값 주소를 반환한다.
> end() 함수는 리스트의 끝 주소를 리턴하는데, 마지막 값보다 한 칸 뒤 값의 주소를 반환한다.

```C++
for (int i = 0; i < n; i++)
{
    sort(graph[i].begin(), graph[i].end());
}
```

## Array

- 5.1 Initialize array by struct. When you can't use <string.h>, this method will works good. Because Array is reference type, it is impossible to assign. But struct is value type, so it is possible

```C++
typedef struct
{
    bool arr[MAXSIZE];
} Arr;

Arr init_arr;
Arr check;
//initialize
check = init_arr;
```

> When you can use <string.h>

```C++
#include <cstring>
#include <cstdio>
int main (){

    int check[MAXSIZE];

    // 4바이트마다 모두 0로 초기화
    // 배열을 채울 때는 memset()함수를 사용하면 됩니다.
    // sizeof 함수 - 배열의 전체 바이트 크기를 반환한다.
    memset(check, 0, sizeof(check));
}
```

## KeepInMind

- 6.1 Initialize 를 해줘야 하는 부분
- 6.2 DFS by stack에서 push의 순서
