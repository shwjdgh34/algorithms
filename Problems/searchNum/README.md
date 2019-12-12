# 수 찾기

문제 : < 백준 - [수 찾기](https://www.acmicpc.net/problem/1920)> <br/>

문제푼 시간:

# Contents

- [수 찾기](#수-찾기)
- [Contents](#contents)
    - [binary search](#binary-search)

## binary search

- 1. Recursion

```C++
int bSearchRec(int low, int high, int target)
{
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    if (arrN[mid] == target)
        return 1;
    else if (arrN[mid] > target)
        return bSearchRec(low, mid - 1, target);
    else
        return bSearchRec(mid + 1, high, target);
}
```

- 2. Loop

```C++
int bSearchLoop(int n, int target)
{
    int start = 0;
    int end = n;
    int mid;
    while (end >= start)
    {
        mid = (end + start) / 2;
        if (arrN[mid] == target)
            return 1;
        else if (arrN[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}
```
