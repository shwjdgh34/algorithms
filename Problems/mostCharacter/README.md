# 가장많은글자

문제 : <백준 - [가장많은글자](https://www.acmicpc.net/problem/1371)> <br/>

문제푼 시간:

# Contents

- [가장많은글자](#%ea%b0%80%ec%9e%a5%eb%a7%8e%ec%9d%80%ea%b8%80%ec%9e%90)
- [Contents](#contents)
  - [String](#string)

## String

- 1.1 read several line strings

```C++
while (cin >> str) // 더이상 입력이 안되면 조건문을 빠져나온다.
    {
        str = ""; // 이걸 추가 안해주면 마지막 문자열이 계속 반복해서 들어와서 끝나질 않는다.
    }
```
