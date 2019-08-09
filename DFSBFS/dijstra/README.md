# 가중치 그래프 빠른길찾기 by BFS, Dijstra Heap

문제 : <1249. [S/W 문제해결 응용] 4일차 - 보급로> <br/>
<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD>

## Contents

- [가중치 그래프 빠른길찾기 by BFS, Dijstra Heap](#%ea%b0%80%ec%a4%91%ec%b9%98-%ea%b7%b8%eb%9e%98%ed%94%84-%eb%b9%a0%eb%a5%b8%ea%b8%b8%ec%b0%be%ea%b8%b0-by-bfs-dijstra-heap)
  - [Contents](#contents)
  - [Queue](#queue)
  - [Dijstra](#dijstra)
  - [Mistakes](#mistakes)
  - [KeepInMind](#keepinmind)
  - [Todolist](#todolist)

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

## Dijstra

- 2.1 Dijstra
- 2.2 Dijstra with heap

## Mistakes

## KeepInMind

## Todolist
