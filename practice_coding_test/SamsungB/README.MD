# SAMSUNG SW TEST LEVEL B



# Contents

- [SAMSUNG SW TEST LEVEL B](#samsung-sw-test-level-b)
- [Contents](#contents)
  - [problems](#problems)
  - [data structure & algorithms](#data-structure--algorithms)
  - [time limitation](#time-limitation)

## problems

- 1.1 big integer calculator 
- 1.2 중고차문제 (x)
- 1.3 블록맞추기 (x) - time limitation. hash to 
- 1.4 폴더관리자 (o)
- 1.5 수열합치기 (o)
- 1.6 key 조사 (o)

## data structure & algorithms

> swexpert 사이트에서 제공하는 [reference code](https://swexpertacademy.com/main/code/referenceCode/referenceCodeList.do)를 적극적으로 참조하여 시간을 줄이는게 필요
> heap(priority queue)를 비롯하여 몇몇 자료구조는 굉장히 효과적이다.
- 2.1 linked list
- 2.2 hash
- 2.3 heap
  
## time limitation

- 3.1 register
use register int than int especially in for loop
```C++
for(register int i = 0 ; i < n ; i++)
```
- 3.2 scanf printf
scanf, printf is fatser than cin and cout

- 3.3 Optimization
optimize my solution like DP or backtracking

- 3.4 Static data structure
dynamic structure take much more time than static

- 3.5 Binary search.
called by 이분탐색, parametric search.
especially when data wet is sorted, it can be used.

- 3.6 Coordinate compression
([reference](https://www.quora.com/What-are-some-problems-that-can-be-solved-with-coordinate-compression))

Coordinate Compression is mainly used to map larger values to smaller values to remove the vacant space.

**For example**: if a = 5, b = 122, c = 122 and d = 3333 then, we can map a = 1, b = 2, c = 2 and d = 3.

**Algorithm**: Simply store all the values in a set, then iterate it and assign values to the elements one by one and increment counter at each step (counter = 0 or 1 or any Integer at the beginning).

[helpLink](https://jason9319.tistory.com/m/356)
[helpLink2](https://baactree.tistory.com/53)
