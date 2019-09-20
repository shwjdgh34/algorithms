# 네트워크

문제 : <프로그래머스 - [네트워크](https://programmers.co.kr/learn/courses/30/lessons/43162)> <br/>

문제푼 시간: 13분

# Contents

- [네트워크](#%eb%84%a4%ed%8a%b8%ec%9b%8c%ed%81%ac)
- [Contents](#contents)
  - [vector 초기화](#vector-%ec%b4%88%ea%b8%b0%ed%99%94)

## vector 초기화

- 1.1
  > 1번째 문장은 int 2차원 벡터를 3X3 사이즈로 크기를 규정하는 것이다.
  > 2번째 문장은 1로 초기화 하는거다.

```C++
vector<vector<int>> v(3, vector<int>(3));
vector<vector<int>> v(3, vector<int>(3,1));
```

- 1.2

> row x col 크기의 벡터를 1로 초기화 하는거다.

```C++
vector<vector<int>> v
int row = 15;
int col = 10;
table.assign(row, vector<int>(col, 1));
```
