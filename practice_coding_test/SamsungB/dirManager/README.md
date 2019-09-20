# 폴더 관리자

문제 : samsung sw codebattle - [폴더 관리자](https://swexpertacademy.com/main/talk/codeBattle/problemDetail.do?contestProbId=AWxQqPTKN78DFAWL&categoryId=AWyDQGPqDUYDFAVP&categoryType=BATTLE) <br/>



# Contents

- [폴더 관리자](#%ed%8f%b4%eb%8d%94-%ea%b4%80%eb%a6%ac%ec%9e%90)
- [Contents](#contents)
  - [ESSENTIAL](#essential)
  - [string function](#string-function)

## ESSENTIAL

- 1.1 This is for B type samsung swtest.
- 1.2 Linked list
- 1.3 Tree (not binary)
- 1.4 String

## string function

- 2.1 strcmp
```C++
  int strcmp(char s[], char t[])
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
            return 0;
    }
    return s[i] - t[i];
}
```

- 2.2 strcpy
```C++
void strcpy(char s[], char t[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}
```
