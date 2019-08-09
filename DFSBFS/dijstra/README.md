# 가중치 그래프 빠른길찾기 by BFS, Dijstra Heap

문제 : <1249. [S/W 문제해결 응용] 4일차 - 보급로> <br/>
<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD>

## Contents

- [가중치 그래프 빠른길찾기 by BFS, Dijstra Heap](#%ea%b0%80%ec%a4%91%ec%b9%98-%ea%b7%b8%eb%9e%98%ed%94%84-%eb%b9%a0%eb%a5%b8%ea%b8%b8%ec%b0%be%ea%b8%b0-by-bfs-dijstra-heap)
  - [Contents](#contents)
  - [Queue](#queue)
  - [Heap & priority queue](#heap--priority-queue)
  - [Dijstra](#dijstra)

## Queue

- 1.1 If you can't use <queue.h> library, you can make yours (by array)

> Q. QUEUE_SIZE 정하는 합리적인 근거?!

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

- 1.2 you can define queue struct or class (by 동적배열!!)

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

- 1.3 Queue by linked list

... 추가 예정

## Heap & priority queue

- 2.1 Priority queue
우선순위 큐를 구현하는 세가지 방법은 Array, Linkedlist, **Heap**을 이용하는 것이다. 배열이나 연결 리스트를 이용하면 우선순위 큐를 매우 간단히 구현할 수 있다. 
  - 2.1.1 Array
먼저 배열을 보면 데이터의 우선순위가 높을수록 배열의 앞쪽에 데이터를 위치시킨다. 이 경우 데이터를 삽입 및 삭제하는 과정에서 데이터가 밀려지거나 당겨지는 연산이 추가되는 단점이 있다. worst big-O(n<sup>2</sup>). 또한 배열에 길이가 정해져있다는 점도 큰 단점이다.
  - 2.1.2  Linked list
연결 리스트의 경우 삽입의 위치를 찾기 위해서 모든 노드에 저장된 데이터와 우선순위를 비교해야 할 수 있다.
  - 2.1.3 Heap
우선순위큐와 가장 잘 맞는 자료구조는 Heap이다.

- 2.2 **Heap**
Heap is **Complete binary tree**
  - 2.2.1 Max heap
루트 노드로 올라갈수록 저장된 값이 커진다.
  - 2.2.2 Min heap
루트 노드로 올라갈수록 저장된 값이 작아진다.
  - 2.2.3 구현하기
heap을 연결리스트를 기반으로 구현한다면 새로운 노드를 힙의 마지막 위치에 추가하는 것이 쉽지 않다. 따라서 힙은 배열을 기반으로 트리를 구현해야 한다.

배열과 연결리스트 중 하나를 선택해야하는데 연결 리스트를 기반으로 힙을 구현한다면, 새로운 노드를 힙의 '마지막 위치'에 추가하는 것이 쉽지 않다. 따라서 힙은 배열을 기반으로 트리를 구현해야 한다.


> left child = parent * 2
> right child = parent * 2 + 1
> parent = chile / 2

## Dijstra

- 3.1 Dijstra
- 3.2 Dijstra with heap
