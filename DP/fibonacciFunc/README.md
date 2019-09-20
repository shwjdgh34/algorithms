# FIBONACCI FUNCTION

문제 : <백준 - 1003 피보나치 함수> <br/>
<https://www.acmicpc.net/problem/1003>

# Contents

- [FIBONACCI FUNCTION](#fibonacci-function)
- [Contents](#contents)
  - [DP, two ways.](#dp-two-ways)

## DP, two ways.

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
