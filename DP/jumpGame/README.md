# JUMP GAME

문제 : <ALGOSPOT - jump game> <br/>
<https://algospot.com/judge/problem/read/JUMPGAME>

# Contents

- [JUMP GAME](#jump-game)
- [Contents](#contents)
  - [time](#time)
  - [DP](#dp)

## time

- 1.1 when you wanna check how much time the algorithm takes, use <time.h>(<ctime> in C++)

```C++
#include <ctime>

    clock_t start = clock();
    clock_t endC = clock();
    printf("걸린시간 : %0.9f\n", float(endC - start) / CLOCKS_PER_SEC);
```

## DP

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
    int &ret = cacheMap.arr[x][y]; // 배열을 계속 쓰면 인덱스 실수나 의미가 점점 애매해져서 reference 변수로 참조하는게 더 좋다.
    if (ret != -1)
        return ret;

    return ret = dp(x + jumpSize, y) || dp(x, y + jumpSize);

}
```

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

- 2.1 차이점 1 : dfs는 도달했는가 에 대한 정보만 true or false로 전달하면 되지만 dp는 최종적으로 도달할 수 있는지에 대한 정보(true or false)와 memoization에 도달 정보가 저장 되었는지(-1)를 표시 해줘야 하므로 int 형으로 선언해야 한다.

```C++
int dp(int x, int y);
bool dfs(int x, int y);
```

- 2.2 차이점 2 : memoization 에 저장되어 있다면(ret != -1) 저장된 값을 반환하고, 저장되어 있지 않다면 recursive하게 값을 구하고 ret 에 저장한 후 반환한다.

> Tip: // 배열을 계속 써야 하는 경우, 인덱스 실수를 저지를 수 있고 뒤로갈수록 해당 배열의 의미를 한눈에 볼 수 없기 때문에 reference 변수로 참조하는게 더 좋다.

```C++
int &ret = cacheMap.arr[x][y];
if (ret != -1)
        return ret;
// || 를 이용하여 손쉽게 반환하는 것을 잘 익히면 많이 편해질 것같다.
return ret = dp(x + jumpSize, y) || dp(x, y + jumpSize);
```
