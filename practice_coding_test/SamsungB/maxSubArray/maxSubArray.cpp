#include <iostream>

using namespace std;

void init();
typedef struct
{
    int arr[200001];
} Arr;
Arr givenArray;
int n;
int sum;
int idx;
Arr answer;
int ans;
int main()

{
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> givenArray.arr[i];
        }
        for (int i = 1; i <= n; i++)
        {

            if (givenArray.arr[i] < 0)
            {
                //일단 지금까지 합한거 저장하고(0이면 저장 안한다.), 앞으로 저장할거 tmpSum의 부호에 따라sum = 0 으로 할지 sum = tmpSum로할지 선택

                if (sum > 0)
                {
                    answer.arr[idx] = sum;
                    idx++;
                }
                int tmpSum = sum + givenArray.arr[i];

                if (tmpSum < 0)
                {
                    sum = 0;
                }
                else
                {
                    sum = tmpSum;
                }
            }
            else
            {
                sum += givenArray.arr[i];
                if (i == n)
                    answer.arr[idx] = sum;
            }
        }
        for (int i = 1; i <= idx; i++)
        {
            if (ans < answer.arr[i])
                ans = answer.arr[i];
        }
        printf("#%d %d\n", testcase, ans);
    }
}
void init()
{
    sum = 0;
    idx = 1;
    ans = 0;
}