#define MAX 100
class queue
{
private:
    int front;
    int rear;
    int queueArr[MAX];

public:
    queue()
    {
        front = 0;
        rear = 0;
    }
    // enqueue, dequeue, isFull, isEmpty
    bool isFull()
    {
        if (front == rear)
            return true;
        return false;
    }
    bool isEmpty()
    {
        if ((rear + 1) % MAX == front)
            return true;
        return false;
    }
    // enqueue랑 dequeue랑 비슷하다.
    void enqueue(int newdata)
    {
        if (isFull())
            throw "Full Queue";
        queueArr[rear] = newdata;
        rear++;
        if (rear == MAX)
            rear = 0;
    }
    int dequeue()
    {
        if (isEmpty())
            throw "EMPTY!!";
        int ret = queueArr[front];
        front++;
        if (front == MAX)
            front = 0;
        return ret;
    }
};