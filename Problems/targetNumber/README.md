# 타겟넘버

문제 : <프로그래머스 - [타겟넘버](https://programmers.co.kr/learn/courses/30/lessons/43165)> <br/>

문제푼 시간: 13분

# Contents

- [타겟넘버](#%ed%83%80%ea%b2%9f%eb%84%98%eb%b2%84)
- [Contents](#contents)
  - [다양한 풀이](#%eb%8b%a4%ec%96%91%ed%95%9c-%ed%92%80%ec%9d%b4)

## 다양한 풀이

- 1.1 DFS
- 1.2 Bit연산

```C++
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = 1 << numbers.size();

    for(int i = 1 ; i < size ; i++){
        int temp = 0;
        for(int j = 0 ; j < numbers.size() ; j++)
        {  
            if(i &(1 << j)){
                temp -= numbers[j];
            }
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }
    return answer;
}
```

