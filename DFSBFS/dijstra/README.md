# 가중치 그래프 빠른길찾기 by BFS, Dijstra Heap

문제 : <1249. [S/W 문제해결 응용] 4일차 - 보급로> <br/>
<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD>

## Contents

- [가중치 그래프 빠른길찾기 by BFS, Dijstra Heap](#%ea%b0%80%ec%a4%91%ec%b9%98-%ea%b7%b8%eb%9e%98%ed%94%84-%eb%b9%a0%eb%a5%b8%ea%b8%b8%ec%b0%be%ea%b8%b0-by-bfs-dijstra-heap)
  - [Contents](#contents)
  - [Queue](#queue)
  - [Mistakes](#mistakes)
  - [KeepInMind](#keepinmind)
  - [Todolist](#todolist)

## Queue

- 1.1 If you can't use <queue.h> library, you can make yours by array

  ```C++
    int queue[1000000]; // Q.크기 정하는 합리적인 근거?!
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

- 1.2 If you can't use <queue.h> library, you can make yours by array

## Mistakes

- 6.1

## KeepInMind

- 7.1 Initialize 를 해줘야 하는 부분
- 7.2 DFS by stack에서 push의 순서

## Todolist

- 8.1 // sorting 종류들공부하기! 직접 코딩할 수 있게 하자
