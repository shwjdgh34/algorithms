#include <stack>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
void cal(vector<double> &answer, char op)
{
    double operand2 = answer.back();
    answer.pop_back();
    double operand1 = answer.back();
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

    string str = "5-(4-1)/2";
    stringstream ss(str);
    vector<double> answer;
    stack<char> s;
    char op;
    double tmpNum;

    while (ss >> op)
    {
        if (op >= '0' && op <= '9')
        {
            ss.unget();
            ss >> tmpNum;
            answer.push_back(tmpNum);
        }
        else
        {
            switch (op)
            {
            case '+':
            case '-':
                while (!s.empty() && s.top() != '(')
                {
                    cal(answer, s.top());
                    s.pop();
                }
                s.push(op);
                break;
            case '*':
            case '/':
                while (!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    cal(answer, s.top());
                    s.pop();
                }
                s.push(op);
                break;
            case '(':
                s.push(op);
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