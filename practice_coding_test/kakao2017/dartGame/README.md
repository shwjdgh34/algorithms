# 다트게임

문제 : <kakao2017 - [다트게임](https://programmers.co.kr/learn/courses/30/lessons/17682)> <br/>

문제푼 시간:

# Contents

- [다트게임](#%eb%8b%a4%ed%8a%b8%ea%b2%8c%ec%9e%84)
- [Contents](#contents)
  - [string stream](#string-stream)

## string stream

- 1.1 sstream >> INT
> num = 183</br>
> if there are number characters like '1', '8', '3' in string, ss >> (int)num change number characters from char to int. So, you can get 183 integer in num variable; 
```C++
string dartResult = "183DF";
stringstream ss(dartResult);
int num;

ss >> num;
```
- 1.2 ss.get() & ss.unget()
> ss.get() is same with ss >> c1
```C++
string dartResult = "DF";
stringstream ss(dartResult);
char c1;
char c2;

c1 = ss.get(); // c1 = D
c2 = ss.get(); // c2 = F
```

> ss.unget take cursor back 
```C++
string dartResult = "DFG";
stringstream ss(dartResult);
char c1;
char c2;
char c3;

c1 = ss.get(); // c1 = D
c2 = ss.get(); // c2 = F
ss.unget();
c3 = ss.get(); // c3 = F
```
