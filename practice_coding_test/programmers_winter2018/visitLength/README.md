# visitLength

문제 : < programmers_winter2018 - [방문길이](https://programmers.co.kr/learn/courses/30/lessons/49994?language=cpp)> <br/>

문제푼 시간: 30m

# Contents

\$../gh-md-toc

## first

- 1.1 Bitmask
  > 좌표점이 아니라 좌표 선분을 체크해야 할 때는 bitmask를 이용하면 수월하게 문제를 해결해 나갈 수 있다.

```C++
#define U 1 // 0001
#define R 2 // 0010
#define D 4 // 0100
#define L 8 // 1000

if (!(map[cur.x][cur.y] & U))
{
    map[cur.x][cur.y] += U;
    map[next.x][next.y] += D;   // 처음 문제 풀 때 해당 라인을 추가 하지 않아서 틀렸다. 좌표점이 아니라 좌표 선분이기 때문에 지나온길을 체크 해주려면 next Pos 입장에서도 체크해줘야 한다.
    count++;
}
```
