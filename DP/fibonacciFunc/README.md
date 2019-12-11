# FIBONACCI FUNCTION

문제 : <백준 - 1003 피보나치 함수> <br/>
<https://www.acmicpc.net/problem/1003>

# Contents

- [FIBONACCI FUNCTION](#fibonacci-function)
- [Contents](#contents)
  - [Tail recursion](#tail-recursion)
  - [Loop](#loop)
  - [DP, two ways.](#dp-two-ways)
- [So, Which one should you choose](#so-which-one-should-you-choose)

## Tail recursion

> [재귀,반복,Tail recursion](https://homoefficio.github.io/2015/07/27/%EC%9E%AC%EA%B7%80-%EB%B0%98%EB%B3%B5-Tail-Recursion/)

기존에 recursive 함수를 짜거나 DP를 짠 경우 함수 호출이 너무 많이 일어나는 문제가 발생한다. 이를 해결하기 위해 Tail recursion 방식을 이용하거나 근본적으로는 loop를 사용하는게 제일 좋다.

Tail call이란 return후 원래 자리로 돌아와서 해야할 일이 남아 있지 않는 recursion 이다. 바꿔말하면 원래자리에서 해야할 일이 남아있지 않다면 돌아갈 원래 자리를 stack에 추가로 저장할 필요가 없다. 주의할 점은 어떤 함수를 호출하고 반환받은 후 아무일도 하지 않으려면 호출하려는 함수를 논리적으로 가장 마지막에 호출해야 한다.

요약하자면 Tail Call은 함수를 호출해서 값을 반환 받은 후 아무 일도 하지 않고 바로 반환하게 하기 위해 논리적으로 가장 마지막(꼬리) 위치에서 함수를 호출하는 방식을 말한다.

Tail recursion은 Tail Call로 호출하는 함수가 자기 자신인 경우입니다.

```C++
int fibonacciFunc(int n, int prev, int prevPrev)
{
    if (n == 1)
        return prevPrev;

    else
        return fibonacciFunc(n - 1, prev + prevPrev, prev);
}
```

## Loop

아무리 tail recursion을 사용하더라도 Tail Call Optimization을 지원해주지 않는다면 똑같이 stack overflow가 발생할 수 있다. 이런 문제를 피하기 위해 반복을 사용하는 것이 좋다.

```C++
int fibonacciFunc(int n)
{
    int prev, prevPrev, cur;
    if (n == 1)
    {
        cout << 0 << ' ';
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << ' ';
        return 1;
    }
    prev = 0;
    prevPrev = 1;
    for (int i = 3; i <= n; i++)
    {
        cur = prev + prevPrev;
        prevPrev = prev;
        prev = cur;
        cout << cur << ' ';
    }
    return cur;
}
```

## DP, two ways

- 1.1 Fibonacci problem(1)</br>
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

- 1.2 Fibonacci problem(2)</br>
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

## So, Which one should you choose

재귀호출은 두겹 이상으로 사용하면 함수 호출 횟수가 상상하지 못할 정도로 증가하는 무제가 발생하고, 깊이가 깊어지면 stack을 많이 사용하는 문제가 발생한다. 이럴 때는 재귀 호출 대신 loop나 tail recursion방식으로 구현하면 문제 상황을 피해갈 수 있다. 하지만 javascript처럼 실행환경에서 tail call optimization을 지원해주지 않으면 사실 상 유일한 해결책은 반복문 뿐이다.
