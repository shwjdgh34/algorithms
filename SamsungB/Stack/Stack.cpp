#define MAX 100
class stack
{
private:
    int top;
    int stackArr[MAX];
    //push, pop, init, isFull, isEmpty
public:
    stack()
    {
        top = 0;
    }
    bool isEmpty()
    {
        if (top == 0)
            return true;
        return false;
    }
    bool isFull()
    {
        if (top == MAX)
            return true;
        return false;
    }
    void push(int newData)
    {
        if (isFull())
            throw "stack overflow";
        stackArr[top] = newData;
        top++; // 값을 먼저 넣고 top++ 을 해줘야된다.
    }
    int pop()
    {
        if (isEmpty())
            throw "Empty!";
        top--; // top-- 먼저 해줘야 한다.
        return stackArr[top];
    }
};
