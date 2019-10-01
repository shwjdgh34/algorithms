#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball)
{
    int answer = 0;
    int s;
    int b;

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            for (int k = 1; k < 10; k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                bool flag = true;
                for (int z = 0; z < baseball.size(); z++)
                {

                    vector<int> arr1{i, j, k};
                    s = 0;
                    b = 0;
                    int strike = baseball[z][1];
                    int ball = baseball[z][2];
                    int num = baseball[z][0];
                    vector<int> arr2{num / 100, (num / 10) % 10, num % 10};
                    for (int l = 0; l < 3; l++)
                    {
                        for (int m = 0; m < 3; m++)
                        {
                            if (arr1[l] == arr2[m] && l == m)
                            {
                                s++;
                            }
                            else if (arr1[l] == arr2[m] && l != m)
                            {
                                b++;
                            }
                        }
                    }
                    if (s != strike || b != ball)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    answer++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> baseball{{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};
    printf("%d\n", solution(baseball));
}