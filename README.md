# algorithms

Solving algorithm problems with C++ language

# Contents

- [algorithms](#algorithms)
- [Contents](#contents)
  - [Time check](#time-check)
  - [File read](#file-read)
  - [String](#string)
  - [StringStream](#stringstream)
  - [Vector](#vector)
  - [Array](#array)
  - [Queue](#queue)
  - [Heap](#heap)
  - [DFS](#dfs)
  - [BFS](#bfs)
  - [DP](#dp)

## Time check

- [1. Time Check](DP/jumpGame)
  > when you wanna check how much time the algorithm takes, use <time.h>(<ctime> in C++)

```C++
#include <ctime>

clock_t start = clock();
clock_t endC = clock();
printf("걸린시간 : %0.9f\n", float(endC - start) / CLOCKS_PER_SEC);
```

## File read

- [1. freopen()](DFSBFS/fundamentalGraph)
  > If you have a lot of inputs, you better use 'std::freopen()
  > Sometimes freopen( ) cant be used. Must use freopen_s() due to a safety problem. If you dont like this, just use <fstream.h>

```C++
freopen("input.txt", "r", stdin);
```

- [2. fstream](DFSBFS/fundamentalGraph)
  > But!!!! i think freopen is much better than fstream expecially in algorithms solving. Because when i submit my source code, i dont need to change code in 'freopen' code (입력받는 코드가 동일하다. scanf나 cin으로 그냥 받을 수 있다!!!!)
  > 따라서 freopen을 주로 쓰자

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

## String

- [1. '+=' instead of 'pushback'](practice_coding_test/kakao2017/secretMap)
  > same result

```C++
answer[k] += ('#');
answer[k].push_back('#');
```

## StringStream

- [1. sstream >> INT](practice_coding_test/kakao2017/dartGame)
  > num = 183</br>
  > if there are number characters like '1', '8', '3' in string, ss >> (int)num change number characters from char to int. So, you can get 183 integer in num variable;

```C++
string str = "183DF";
stringstream ss(str);
int num;
ss >> num;  // num = 183;
```

- [2. ss.get() & ss.unget()](practice_coding_test/kakao2017/dartGame)
  > ss.get() is same with ss >> c1

```C++
string str = "DF";
stringstream ss(str);
char c1;
char c2;

c1 = ss.get(); // c1 = D
c2 = ss.get(); // c2 = F
```

> ss.unget take cursor back

```C++
string str = "DFG";
stringstream ss(str);
char c1;
char c2;
char c3;

c1 = ss.get(); // c1 = D
c2 = ss.get(); // c2 = F
ss.unget();
c3 = ss.get(); // c3 = F not G
```

## Vector

- [1. Re-initialize](DFSBFS/fundamentalGraph)
  > to initialize, use .clear()

```C++
vector<int> graph[MAXSIZE];

for (int i = 0; i < MAXSIZE; i++)
{
    graph[i].clear();
}
```

- [2. .begin & .end](DFSBFS/fundamentalGraph)

> begin() 함수는 벡터의 데이터가 있는 리스트의 시작 주소를 리턴하는데, 첫 번째 값 주소를 반환한다.
> end() 함수는 리스트의 끝 주소를 리턴하는데, 마지막 값보다 한 칸 뒤 값의 주소를 반환한다.

```C++
for (int i = 0; i < n; i++)
{
    sort(graph[i].begin(), graph[i].end());
}
```

- [3. .find()](practice_coding_test/kakao2017/cache)

```C++
include<algorithm>
auto itr = find(v.begin(), v.end(), value);
```

- [4. .erase()](practice_coding_test/kakao2017/cache)
  > cache.end() return the next itr of the end index of vector</br>
  > but i think erase() allow erase(cache,end()) to erase last index</br>
  > == cache.erase(cache.end()-1) == cache.pop_back()
  > erase() return current iterator after erase the value and move all remain values to each 1 block left

```C++
v.erase(itr);
v.erase(v.end())
// == v.erase(v.end()-1)
// == v.pop_back()

// erase 0~5 idx and then return itr = 6
v.erase(v.begin(), v.begin()+5);
```

- [3. insert()](practice_coding_test/kakao2017/cache)
  > insert(itr, value) makes vector insert a value on the itr index. itr 위치에 삽입을 하면 itr부터 end까지의 모든 값들은 한칸씩 뒤로 이동된다.
  > O(n)의 시간복잡도가 들것이다. so if you would use insert frequently, use linked list

```C++
v.insert(v.begin(), value);
```

## Array

- [1. Initialize by struct](DFSBFS/fundamentalGraph) </br>
  > When you can't use <string.h>, this method will works good. Because Array is reference type, it is impossible to assign. But struct is value type, so it is possible

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

- [2. Initialize by memset()](DFSBFS/fundamentalGraph)
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

## Queue

- [1. by array](DFSBFS/dijstra)
  > If you can't use <queue.h> library, you can make yours (by array)
  > Q. QUEUE_SIZE 정하는 합리적인 근거?!
  > 이 경우는 queue가 꽉찼을 때 처리하는 코드가 없으므로queue size를 크게 잡아줘야한다.

```C++
int queue[QUEUE_SIZE]; // Q.크기 정하는 합리적인 근거?!
int front = 0;
int rear = 0;

queue[rear] = start // Enqueue
rear++;

while (front != rear)   // Empty;
{
    int cur = queue[front]; // Dequeue
    front++;
    for (int i = 0; i < 4; i++)
    {
        int next = cur + dx[i];
        if(CONDITION){
            queue[rear] = next; //Enqueue
            rear++;
        }
    }
}
```

- [2. by Dynamic Array](DFSBFS/dijstra)
  > you can define queue struct or class (by 동적배열!!)

```C++
class Queue
{
private:
    int A[QUEUE_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }
    bool empty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
    bool full()
    {
        if ((rear + 1) % QUEUE_SIZE == front)
            return true;
        else
            return false;
    }
    int front()
    {
        if (!empty())
            return A[front];
        else
            throw "empty!";
    }
    void pop()
    {
        if (!empty())
            front = (front + 1) % QUEUE_SIZE;
        else
            cout << "empty!";
    }
    void push(int value)
    {
        if (!full())
        {
            A[rear] = value;
            rear = (rear + 1) % QUEUE_SIZE;
        }
        else
            cout << "full!";
    }
};
```

## Heap

- [1. Priority queue](DFSBFS/dijstra)

  > 우선순위 큐를 구현하는 세가지 방법은 Array, Linkedlist, **Heap**을 이용하는 것이다. 배열이나 연결 리스트를 이용하면 우선순위 큐를 매우 간단히 구현할 수 있다.

  - 1.1 Array
    먼저 배열을 보면 데이터의 우선순위가 높을수록 배열의 앞쪽에 데이터를 위치시킨다. 이 경우 데이터를 삽입 및 삭제하는 과정에서 데이터가 밀려지거나 당겨지는 연산이 추가되는 단점이 있다. worst big-O(n<sup>2</sup>). 또한 배열에 길이가 정해져있다는 점도 큰 단점이다.
  - 1.2 Linked list
    연결 리스트의 경우 삽입의 위치를 찾기 위해서 모든 노드에 저장된 데이터와 우선순위를 비교해야 할 수 있다.
  - 1.3 Heap
    우선순위큐와 가장 잘 맞는 자료구조는 Heap이다.

- [2. Heap](DFSBFS/dijstra)
  > Heap is **Complete binary tree**
  - 2.1 Max heap
    루트 노드로 올라갈수록 저장된 값이 커진다.
  - 2.2 Min heap
    루트 노드로 올라갈수록 저장된 값이 작아진다.
  - 2.3 구현하기
    heap을 연결리스트를 기반으로 구현한다면 새로운 노드를 힙의 마지막 위치에 추가하는 것이 쉽지 않다. 따라서 힙은 배열을 기반으로 트리를 구현해야 한다.

배열과 연결리스트 중 하나를 선택해야하는데 연결 리스트를 기반으로 힙을 구현한다면, 새로운 노드를 힙의 '마지막 위치'에 추가하는 것이 쉽지 않다. 따라서 힙은 배열을 기반으로 트리를 구현해야 한다.

> left child = parent _ 2
> right child = parent _ 2 + 1
> parent = chile / 2

- [3. min heap implementation](heap/basicHeap)

```C++
class minHeap
{
private:
    int heap[HEAP_SIZE] = {0};
    int count;

public:
    minHeap()
    {
        count = 0;
    }
    void push(int newValue)
    {
        // heap index start from 1. 연산 쉽게 해줄려고!
        if (count + 1 == HEAP_SIZE)
        {
            cout << "FULL !!" << endl;
            return;
        }
        else
        {
            heap[++count] = newValue;
            int cur = count;
            int parent = cur / 2;
            // maxHeap이라면 부등호의 방향만 반대로 해주면 된다.
            while (parent && heap[parent] > heap[cur])
            {
                int tmp = heap[parent];
                heap[parent] = heap[cur];
                heap[cur] = tmp;
                cur = parent;
                parent = cur / 2;
            }
        }
    }
    int pop()
    {
        if (count == 0)
        {
            cout << "EMPTY !!" << endl;
            throw "error";
        }
        else
        {
            int ret = heap[1];
            // 맨 뒤에 있는 heap data를 가져온다.
            heap[1] = heap[count--];
            int cur = 1;
            // base로 left child를 선정한다.
            int child = cur * 2;
            // right child가 있는경우
            if (child + 1 <= count)
            {
                 // 더 작은 쪽의 child를 선택한다.
                child = heap[child] < heap[child + 1] ? child : child + 1;
            }
            while (child <= count && heap[cur] > heap[child])
            {
                int tmp = heap[cur];
                heap[cur] = heap[child];
                heap[child] = tmp;

                cur = child;
                child = cur * 2;

                if (child + 1 <= count)
                {
                    child = heap[child] < heap[child + 1] ? child : child + 1;
                }
            }

            return ret;
        }
    }
};

```

## DFS

- [1. DFS by stack](DFSBFS/fundamentalGraph)
  > remember this line!! must push 'cur' for back to 'cur'

```C++
void dfs_stack(int start)
{
    stack<int> s;
    s.push(start);
    check[start] = true;
    printf("%d ", start);

    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!check[next])
            {
                printf("%d ", next);
                check[next] = true;
                // remember this line!! must push 'cur' for back to 'cur'
                s.push(cur);
                s.push(next);
                break;
            }
        }
    }
}
```

- [2. DFS by recursive](DFSBFS/fundamentalGraph)

```C++
void dfs_recursive(int cur)
{
    //check = init_arr(); // 재귀함수기 때문에 이곳에서 초기화를 하면 안된다!!!!
    printf("%d ", cur);
    check[cur] = true;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (!check[next])
        {
            check[next] = true;
            dfs_recursive(next);
        }
    }
}
```

## BFS

- [1. BFS by queue](DFSBFS/fundamentalGraph)

```C++
void bfs_queue(int start)
{
    queue<int> q;
    check[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!check[next])
            {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
```

## DP

- [1. Fibonacci problem(1)](DP/fibonacciFunc)
  > my own way. I calculated about zeroNum and oneNum. But many people didnt like that. Because my way has same pattern.
  > caution: i abbereviated many code, so you should check real sourse code to fully understand!

```C++
void fibonacciFunc(){

    if (!cache[x].visited)
    {
        fibonacciFunc(x - 1);
        fibonacciFunc(x - 2);
        cache[x].zeroNum = cache[x - 1].zeroNum + cache[x - 2].zeroNum;
        cache[x].oneNum = cache[x - 1].oneNum + cache[x - 2].oneNum;
        cache[x].visited = true;
        return;
    }
}
int main(){
    fibonacciFunc(n);
    cout << cache[n].zeroNum << " " << cache[n].oneNum << endl;
}
```

- [2. Fibonacci problem(2)](DP/fibonacciFunc)
  > others's way. they excluded redundancy. So code can became shorter and easier.

```C++
int fibonacciFunc(int x)
{
    if (cache[x] != -1)
        return cache[x];
    return cache[x] = fibonacciFunc(x - 1) + fibonacciFunc(x - 2);
}
int main(){
    fibonacciFunc(n + 1);

    cout << cache[n] << " " << cache[n + 1] << endl;
}
```

- [3. DP vs DFS](DP/jumpGame)(다시풀어봐도 좋을 문제)

> cacheMap에 가능 여부에 대한 데이터를 저장해준다.

```C++
int dp(int x, int y)
{
    // basecase : 게임판 범위를 벗어난 경우
    if (x >= n || y >= n)
        return 0;
    // basecase : 마지막칸에 도착한 경우
    if (x == n - 1 && y == n - 1)
        return 1;

    int jumpSize = map.arr[x][y];
    // 배열을 계속 쓰면 인덱스 실수나 의미가 점점 애매해져서 reference 변수로 참조하는게 더 좋다.
    int &ret = cacheMap.arr[x][y];
    if (ret != -1)
        return ret;

    return ret = dp(x + jumpSize, y) || dp(x, y + jumpSize);

}
```

> memoization이 없기 때문에 매번 반복해서 계산을 해줘야 한다.

```C++
bool dfs(int x, int y)
{
    // basecase : 게임판 범위를 벗어난 경우
    if (x >= n || y >= n)
        return false;
    // basecase : 마지막칸에 도착한 경우
    if (x == n - 1 && y == n - 1)
        return true;
    int jumpSize = map.arr[x][y];
    return dfs(x + jumpSize, y) || dfs(x, y + jumpSize); // readme작성
}
```

> 차이점 1 : dfs는 도달했는가 에 대한 정보만 true or false로 전달하면 되지만 dp는 최종적으로 도달할 수 있는지에 대한 정보(true or false)와 memoization에 도달 정보가 저장 되었는지(-1)를 표시 해줘야 하므로 int 형으로 선언해야 한다.

```C++
int dp(int x, int y);
bool dfs(int x, int y);
```

> 차이점 2 : memoization 에 저장되어 있다면(ret != -1) 저장된 값을 반환하고, 저장되어 있지 않다면 recursive하게 값을 구하고 ret 에 저장한 후 반환한다.

> Tip: // 배열을 계속 써야 하는 경우, 인덱스 실수를 저지를 수 있고 뒤로갈수록 해당 배열의 의미를 한눈에 볼 수 없기 때문에 reference 변수로 참조하는게 더 좋다.

```C++
int &ret = cacheMap.arr[x][y];
if (ret != -1)
        return ret;
// || 를 이용하여 손쉽게 반환하는 것을 잘 익히면 많이 편해질 것같다.
return ret = dp(x + jumpSize, y) || dp(x, y + jumpSize);
```
