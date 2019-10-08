#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s)
{
    string answer = "";
    // 짝수
    if (s.size() % 2 == 0)
    {
        answer += s[s.size() / 2 - 1];
        answer += s[s.size() / 2];
    }
    // 홀수
    else
    {
        answer = s[s.size() / 2];
    }
    return answer;
}
int main()
{
    string s = "abcde";
    string answer;
    answer = solution(s);
    cout << answer << endl;
}