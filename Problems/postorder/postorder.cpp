#include <stack>
#include <iostream>

using namespace std;

int main()
{
    string str = "A+B*C-D/E";
    string answer = "";
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            answer += str[i];
        }
        else
        {
            switch (str[i])
            {
            case '+':
            case '-':
                while (!s.empty() && s.top() != '(')
                {
                    answer += s.top();
                    s.pop();
                }
                s.push(str[i]);
                break;
            case '*':
            case '/':
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    answer += s.top();
                    s.pop();
                }
                s.push(str[i]);
                break;
            case '(':
                s.push(str[i]);
                break;
            case ')':
                while (s.top() != '(')
                {
                    answer += s.top();
                    s.pop();
                }
                s.pop();
                break;
            }
        }
    }
    while (!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    cout << answer << endl;
}