#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int idx, int sum, int *pAnswer)
{
    if (numbers.size() == idx)
    {
        if (sum == target)
            *pAnswer += 1;
        return;
    }
    dfs(numbers, target, idx + 1, sum + numbers[idx], pAnswer);
    dfs(numbers, target, idx + 1, sum - numbers[idx], pAnswer);
}
int solution(vector<int> numbers, int target)
{
    int answer = 0;
    dfs(numbers, target, 0, 0, &answer);

    return answer;
}

int main()
{
    vector<int> numbers{1, 1, 1, 1, 1};
    int target = 3;
    printf("%d\n", solution(numbers, target));
    return 0;
}