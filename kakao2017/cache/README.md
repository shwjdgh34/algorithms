# 캐시

문제 : <kakao 2017 - 캐시<사이트주소>> <br/>

문제푼 시간:

# Contents

- [캐시](#%ec%ba%90%ec%8b%9c)
- [Contents](#contents)
  - [vector](#vector)
  - [list](#list)

## vector

- 1.1 find()
  > include<algorithm>

```C++
auto itr = find(cache.begin(), cache.end(), lowerString);
```

- 1.2 erase()
  > cache.end() return the next itr of the end index of vector</br>
  > but i think erase() allow erase(cache,end()) to erase last index</br>
  > == cache.erase(cache.end()-1) == cache.pop_back()

```C++
cache.erase(itr);
cache.erase(cache.end())    // == cache.erase(cache.end()-1) == cache.pop_back()
```

- 1.3 insert()

## list

- 2.1
- 2.2
