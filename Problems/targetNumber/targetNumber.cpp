#include <string>
#include <vector>

using namespace std;

vector<int> globalN;
void dfs(int target, int idx, int sum, int *pAnswer)
{
    if (globalN.size() == idx)
    {
        if (sum == target)
            *pAnswer += 1;
        return;
    }
    dfs(target, idx + 1, sum + globalN[idx], pAnswer);
    dfs(target, idx + 1, sum - globalN[idx], pAnswer);
}
int solution(vector<int> numbers, int target)
{
    int answer = 0;
    globalN = numbers;
    dfs(target, 0, 0, &answer);

    return answer;
}

int main()
{
    vector<int> numbers{1, 1, 1, 1, 1};
    int target = 3;
    printf("%d\n", solution(numbers, target));
    return 0;
}