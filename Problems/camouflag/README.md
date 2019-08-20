# 위장

문제 : <프로그래머스 해쉬 - 위장> <br/>
<https://programmers.co.kr/learn/courses/30/lessons/42578#>

문제푼 시간: 50분

# Contents

- [위장](#%ec%9c%84%ec%9e%a5)
- [Contents](#contents)
  - [error](#error)
  - [hash](#hash)

## error

- 1.1 실패 (signal: segmentation fault (core dumped))

> just modified r range from 100 to 99
> i took HASH_SIZE to 100. so if r %= 100 or more, it makes segmentation fault. because hashCode() return values would be used as idx value of hashmap[HASH_SIZE]
```C++
#define HASH_SIZE 100

int hashCode(string s)
{
    int i;
    int r = 0;

    // Special Prime Number
    int a = 13;

    for (i = 0; i < s.length(); i++)
    {
        r += r * a + s[i];
        r %= 99;    // just modified r range from 100 to 99
    }

    return r;
}
```

- 1.2

## hash

- 2.1
- 2.2