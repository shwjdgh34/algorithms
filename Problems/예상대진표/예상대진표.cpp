#include <iostream>

using namespace std;
int getExp(int n)
{
    int exp = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        exp++;
    }
    return exp;
}
int solution(int n, int a, int b)
{
    int answer;
    int exp = getExp(n);
    for (int i = exp; i > 0; i--)
    {
        n /= 2;
        int aQuotient = (a - 1) / n;
        int bQuoteint = (b - 1) / n;
        if (aQuotient != bQuoteint)
        {
            answer = i;
            break;
        }
    }
    return answer;
}

int main()
{

    cout << solution(8, 4, 7) << endl;
}