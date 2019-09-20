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

```C++
include<algorithm>
auto itr = find(cache.begin(), cache.end(), value);
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
  > insert(itr, value) makes vector insert a value on the itr index. itr 위치에 삽입을 하면 itr부터 end까지의 모든 값들은 한칸씩 뒤로 이동된다.

```C++
cache.insert(cache.begin(), lowerString);
```

## list

- 2.1
- 2.2
