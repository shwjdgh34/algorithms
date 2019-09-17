#include <string>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    int i = 0;
    int tmpNum[3];
    int num[3];
    for (int j = 0; j < 3; j++)
    {
        // 점수(숫자)
        tmpNum[j] = 0;
        while (dartResult[i] <= '9' && dartResult[i] >= '0')
        {
            tmpNum[j] *= 10;
            tmpNum[j] += dartResult[i] - '0';
            i++;
        }
        // 보너스(문자)
        switch (dartResult[i])
        {
        case 'S':
            num[j] = tmpNum[j];
            break;
        case 'D':
            num[j] = tmpNum[j] * tmpNum[j];
            break;
        case 'T':
            num[j] = tmpNum[j] * tmpNum[j] * tmpNum[j];
            break;
        default:
            break;
        }
        i++;
        if (i >= dartResult.size())
            break;
        // 옵션(특수문자)
        else if (dartResult[i] == '*')
        {
            num[j] *= 2;
            if (j != 0)
            {
                num[j - 1] *= 2;
            }
            i++;
        }
        else if (dartResult[i] == '#')
        {
            num[j] *= -1;
            i++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        answer += num[i];
    }
    return answer;
}
int main()
{
    string dartResult = "1S2D*3T";
    printf("%d\n", solution(dartResult));
}