#include <iostream>
#include <string>
#include <vector>
//#include <fstream>
using namespace std;

int countChar[26];
int main()
{
    //ifstream myfile("input.txt");
    string str;
    vector<char> answer;
    int max = 0;
    while (cin >> str) // 더이상 입력이 안되면 조건문을 빠져나온다.
    {
        char c;
        if (str[0] == EOF)
            break;
        for (int i = 0; i < str.size(); i++)
        {
            c = str[i];
            countChar[c - 'a']++;
        }
        str = ""; // 이걸 추가 해줘야 빠져나올 수 있다.
    }
    for (int i = 0; i < 26; i++)
    {
        if (countChar[i] > max)
        {
            max = countChar[i];
            answer.clear();
            answer.push_back(i + 'a');
        }
        else if (countChar[i] == max)
        {
            answer.push_back(i + 'a');
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
    }
}