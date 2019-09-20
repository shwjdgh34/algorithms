#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    stringstream ss(dartResult);

    int score[3];
    for (int j = 0; j < 3; j++)
    {
        int num = 0;
        char bonus = 0;
        char option = 0;
        // 점수(숫자)
        ss >> num;
        // 보너스(문자)
        ss >> bonus;
        ss >> option;
        if (option != '*' && option != '#')
        {
            ss.unget();
        }

        switch (bonus)
        {
        case 'S':
            score[j] = pow(num, 1);
            break;
        case 'D':
            score[j] = pow(num, 2);
            break;
        case 'T':
            score[j] = pow(num, 3);
            break;
        default:
            break;
        }
        switch (option)
        {
        case '*':
            score[j] *= 2;
            if (j != 0)
            {
                score[j - 1] *= 2;
            }
            break;
        case '#':
            score[j] *= -1;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        answer += score[i];
    }
    return answer;
}
int main()
{
    string dartResult = "1S2D*3T";
    printf("%d\n", solution(dartResult));
}