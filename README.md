# algorithms

Solving algorithm problems with C++ language

# Contents

- [algorithms](#algorithms)
- [Contents](#contents)
  - [Queue](#queue)
  - [second](#second)

## Queue

- [1.1](DFSBFS/dijstra/README.md) If you can't use <queue.h> library, you can make yours (by array)

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

## second

- 2.1
- 2.2
