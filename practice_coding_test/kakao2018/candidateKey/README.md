# 후보키

문제 : <프로그래머스, kakao 2018 - [후보키](https://programmers.co.kr/learn/courses/30/lessons/42890)> <br/>

문제푼 시간: 28분

# Contents

- [후보키](#%ed%9b%84%eb%b3%b4%ed%82%a4)
- [Contents](#contents)
  - [Bitmasking](#bitmasking)
  - [Time complexity](#time-complexity)

## Bitmasking
- 1.1 Consider all case
> 'num' is total num of cases </br>
> from 00000001 to 11111111 (when column is 8)</br>
> i start from 1 because 0 means 00000000, none of Attributes is included.
```C++
int num = 1 << col;
for (int i = 1; i < num; i++){
    ...
}
```
- 1.2 add attribute to tmp
>> when i is 10011101 in bit, (i & (1 << k)) makes me add relation[j][k] to tmp only when bit is 1.
```C++
for (int i = 1; i < num; i++){
    for (int k = 0; k < col; k++)
    {
        if (i & (1 << k))
        {
            tmp += relation[j][k];
        }
    }
}

```

## Time complexity

- 2.1 2^column x row

in this problem, max of column is 8.
max of row is 20.
so 2^8 x 20 is about 5000
it is so short even if exhaustive search