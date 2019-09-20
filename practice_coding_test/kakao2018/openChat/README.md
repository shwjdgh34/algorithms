# 오픈채팅방

문제 : <프로그래머스, kakao 2018 - [오픈채팅방](https://programmers.co.kr/learn/courses/30/lessons/42888)> <br/>

문제푼 시간: 36분

# Contents

- [오픈채팅방](#%ec%98%a4%ed%94%88%ec%b1%84%ed%8c%85%eb%b0%a9)
- [Contents](#contents)
  - [tokenization](#tokenization)
  - [map](#map)

## tokenization

- 1.1 Jeongho
  > stringstream can be used like 'cin' or 'cout'</br>
  > focus on ss >>nAct[i];

```C++
#include <sstream>

vector<string> solution(vector<string> record)
{
    int size = record.size();
    vector<string> nAct(size);
    vector<string> nUid(size);
    vector<string> nNickName(size);

    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        ss >> nAct[i];
        ss >> nUid[i];
        ss >> nNickName[i];
    }
}
```

- 1.2 Seongjun
  > focus on </br>
  > while (ss >> buf)

```C++
#include <sstream>
for (int i = 0; i < record.size(); i++)
{
    vector<string> solution(vector<string> record)
    {
        stringstream ss(record[i]);
        string buf;
        vector<string> tokens;
        while (ss >> buf)
            tokens.push_back(buf);
        if (tokens[0] == "Enter")
    }
}
```

## map

- 2.1

```C++
#include <map>

map<string, string> userMap;

userMap[nUid[i]] = nNickName[i];
tmpAnswer += userMap[ansList[i].uid]
```

> below two statements are same

```C++
userMap[key] </br>
userMap.find(key)->second </br>
```

- 2.2 [reference](https://modoocode.com/224)
