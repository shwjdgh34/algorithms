#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> answer;

void printAnswer()
{
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    cout << endl;
}
void dfs(int n, int k)
{
    if (n == 6)
    {
        printAnswer();
        return;
    }
    for (int i = k; i < arr.size(); i++)
    {
        answer.push_back(arr[i]);
        dfs(n + 1, i + 1);
        answer.pop_back();
    }
}
int main()
{
    int k;
    while (1)
    {

        cin >> k;
        if (k == 0)
            return 1;

        for (int i = 0; i < k; i++)
        {
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }
        dfs(0, 0);
        cout << endl;
        arr.clear();
        answer.clear();
    }
}