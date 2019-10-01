#include <vector>
#include <iostream>
using namespace std;
// un visited => 0
// if n is prime => 1
// else n is not prime => 2
int prime[3000];
bool isPrime(int n)
{

    if (prime[n] == 0)
    {
        prime[n] = 1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                prime[n] = 2;
                break;
            }
        }
    }

    if (prime[n] == 1)
        return true;
    else
        return false;
}
int solution(vector<int> nums)
{
    int answer = 0;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (isPrime(nums[i] + nums[j] + nums[k]))
                {
                    answer++;
                }
            }
        }
    }
    return answer;
}
int main()
{
    vector<int> nums{1, 2, 3, 4};
    cout << solution(nums) << endl;
}