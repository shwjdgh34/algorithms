#include <vector>
#include <iostream>
using namespace std;
bool d[50001] = {
    false,
}; // d[N] == false 라면 N은 소수
vector<int> gNums;
int N;
int ans;
void solve(int nowIdx, int choiceCnt, int sum)
{
   // 3개를 골라서 합이 소수가 될때 카운팅한다.
   if (nowIdx == N)
   {
      if (choiceCnt == 3)
      {
         if (d[sum] == false)
         {
            ans++;
         }
      }
   }
   else
   {
      solve(nowIdx + 1, choiceCnt + 1, sum + gNums[nowIdx]);
      solve(nowIdx + 1, choiceCnt, sum);
   }
}
int solution(vector<int> nums)
{
   int answer = -1;
   gNums = nums;
   N = nums.size();
   d[1] = true;
   for (int i = 2; i * i <= 3000; i++)
   {
      if (d[i] == true)
      {
         continue;
      }
      for (int j = i + i; j <= 3000; j += i)
      {
         d[j] = true; // 소수가 아닌 것 true
      }
   }
   solve(0, 0, 0);
   answer = ans;
   printf("%d\n", answer);
   return answer;
}