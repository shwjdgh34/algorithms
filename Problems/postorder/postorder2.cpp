#include <stack>
#include <iostream>
#include <vector>
using namespace std;
void cal(vector<int> &answer, char op)
{
    int operand2 = answer.back();
    answer.pop_back();
    int operand1 = answer.back();
    answer.pop_back();
    switch (op)
    {
    case '+':
        answer.push_back(operand1 + operand2);
        break;
    case '-':
        answer.push_back(operand1 - operand2);
        break;
    case '*':
        answer.push_back(operand1 * operand2);
        break;
    case '/':
        answer.push_back(operand1 / operand2);
        break;
    }
}
int main()
{
    string str = "5+3*(5-1)/2";
    vector<int> answer;
    stack<int> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            answer.push_back(str[i] - '0');
        }
        else
        {
            switch (str[i])
            {
            case '+':
            case '-':
                while (!s.empty() && s.top() != '(')
                {
                    cal(answer, s.top());
                    s.pop();
                }
                s.push(str[i]);
                break;
            case '*':
            case '/':
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    cal(answer, s.top());
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
                    cal(answer, s.top());
                    s.pop();
                }
                s.pop();
                break;
            }
        }
    }
    while (!s.empty())
    {
        cal(answer, s.top());

        s.pop();
    }
    cout << answer.back() << endl;
}