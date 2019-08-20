# 위장

문제 : <프로그래머스 해쉬 - 위장> <br/>
<https://programmers.co.kr/learn/courses/30/lessons/42578#>

문제푼 시간: 50분

# Contents

- [위장](#%ec%9c%84%ec%9e%a5)
- [Contents](#contents)
  - [error](#error)
  - [스터디원님들의 방식](#%ec%8a%a4%ed%84%b0%eb%94%94%ec%9b%90%eb%8b%98%eb%93%a4%ec%9d%98-%eb%b0%a9%ec%8b%9d)

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

- 1.2 segmentation fault란?
> 참조 : <https://hashcode.co.kr/questions/403/segmentation-fault%EB%8A%94-%EB%AD%94%EA%B0%80%EC%9A%94>

segmentation fault란 허용되지 않은 방법으로 메모리에 접근할 때, 허용되지 않은 메모리 영역에 접근할 때 발생해서 사용자가 메모리를 오염시키는 걸 막아주고, 디버깅 하기 힘든 메모리 버그를 알려주는 역할을 합니다.


## 스터디원님들의 방식

- 2.1 hashmap STL?
- 2.2 power set