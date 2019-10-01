# 끝말잇기

문제 : <프로그래머스 - [끝말잇기](https://programmers.co.kr/learn/courses/30/lessons/12981)> <br/>

문제 푼시간:

# Contents

- [끝말잇기](#%eb%81%9d%eb%a7%90%ec%9e%87%ea%b8%b0)
- [Contents](#contents)
  - [map](#map)


## map
- 1.1 find()
> 'itr == wordMap.end()' means the map doesn't have 'key' data
```C++
#include <map>
map<string, bool> wordMap;
auto itr = wordMap.find(key);
if (itr == wordMap.end())
    wordMap[key] = true;
```