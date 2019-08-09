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

- 2.2 Heap
Heap is 



힙은 '이진 트리'이되 '완전 이진 트리'이다.



위와 같이 루트 노드로 올라갈수록 저장된 값이 커지는 완전트리를 '최대 힙(max heap)'이라 하고,

루트 노드로 올라갈수록 저장된 값이 작아지는 완전트리를 '최소 힙(min heap)'이라 한다.

이렇듯 힙은 루트 노드에 우선순위가 가장 높은 데이터를 위치시킬 수 있는 자료구조라 우선순위 큐를 구현하기 쉽다.



힙에서 데이터를 저장하고 삭제하는 과정이다.



 

먼저 데이터를 저장하는 과정을 살펴보자.

새로운 데이터는 우선순위가 가장 낮다는 가정하에 마지막위치에 저장된다.

그 다음 부모 노드와 비교해서 위치가 바뀌어야 하다면 바꿔준다.



 

다음으로 데이터를 삭제하는 과정(루트 노드)을 살펴보자.

마지막 노드를 루트 노드의 자리로 옮긴 다음, 자식 노드와의 비교를 통해 제자리를 찾아간다.



지금까지 힙으로 우선순위 큐를 구현하는 과정을 확인했다.

이제는 힙의 구현방법을 생각해보자.

배열과 연결리스트 중 하나를 선택해야하는데 연결 리스트를 기반으로 힙을 구현한다면, 새로운 노드를 힙의 '마지막 위치'에 추가하는 것이 쉽지 않다.

따라서 힙은 배열을 기반으로 트리를 구현해야 한다.





자식 노드와 부모 노드를 구하는 식이다.



 



위 그림에서 데이터의 값 = 인덱스 값 이라고 보면(구현의 편의를 위해 인덱스 0은 사용 x)

 

왼쪽 자식 노드의 인덱스 값            부모 노드의 인덱스 값 * 2
오른쪽 자식 노드의 인덱스 값         부모 노드의 인덱스 값 *2 + 1
부모 노드의 인덱스 값                   자식 노드의 인덱스 값 / 2

으로 간단히 구할 수 있다. 

class Main{ 
public static void main(String[] args){ 
Heap heap=new Heap(); 
heap.hInsert(1,1); 
heap.hInsert(2,2); 
heap.hInsert(3,3); 
System.out.println(heap.hDelete()); 
heap.hInsert(1,1); 
heap.hInsert(2,2); 
heap.hInsert(3,3); 

## Dijstra

- 3.1 Dijstra
- 3.2 Dijstra with heap
