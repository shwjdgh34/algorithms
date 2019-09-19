#include <string>
#include <vector>

using namespace std;
long long fibo[81];
long long fibonacci(int n)
{
    if (fibo[n] == 0)
    {
        fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return fibo[n];
}
long long solution(int N)
{
    long long answer = 0;
    fibo[1] = 1;
    fibo[2] = 1;

    answer = fibonacci(N) * 4 + fibonacci(N - 1) * 2;
    return answer;
}

int main()
{
    int n = 6;
    printf("%lld\n", solution(n));
}