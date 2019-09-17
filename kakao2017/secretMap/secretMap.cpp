#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer(n);
    int arrSize = arr1.size();
    vector<int> arrAnswer(arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        arrAnswer[i] = arr1[i] | arr2[i];
    }
    int j = 1 << (n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (arrAnswer[k] & j)
                answer[k] += ('#');
            else
                answer[k] += (' ');
        }
        j = j >> 1;
    }
    return answer;
}
int main()
{
    int n = 5;
    vector<int> arr1{9, 20, 28, 18, 11};
    vector<int> arr2{30, 1, 21, 17, 28};
    vector<string> answer = solution(n, arr1, arr2);
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << endl;
    }
}