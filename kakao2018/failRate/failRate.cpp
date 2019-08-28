// 50 분
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct
{
    float fail;
    int idx;
} Info;
bool desc(Info a, Info b)
{
    if (a.fail == b.fail)     // 같은 failRate가졌을 경우!!
        return a.idx < b.idx; // idx가 작을 수록 더 낮은 stage다.
    return a.fail > b.fail;
}
vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<bool> visited(stages.size(), false);
    vector<Info> answerList;
    vector<int> none;
    int stage = 1;
    int num = stages.size(); // user number
    float failRate;
    int sameStageNum = 0;
    sort(stages.begin(), stages.end());
    for (int i = 0; i < stages.size(); i++)
    {

        if (visited[stages[i]] == true)
            continue;
        while (stage != stages[i])
        {
            none.push_back(stage);
            stage++;
        }
        if (stages[i] == N + 1)
            break;
        for (int j = 0; stages[i + j] == stages[i]; j++)
        {
            sameStageNum++;
        }

        failRate = (float)sameStageNum / (float)(num - i);
        answerList.push_back({failRate, i});
        visited[stages[i]] = true;
        sameStageNum = 0;
        stage++;
    }
    sort(answerList.begin(), answerList.end(), desc);
    for (int i = 0; i < answerList.size(); i++)
    {
        answer.push_back(stages[answerList[i].idx]);
    }
    for (int i = 0; i < none.size(); i++)
    {
        answer.push_back(none[i]);
    }
    return answer;
}
int main()
{
    vector<int> stages{2, 1, 2, 6, 2, 4, 3, 3};
    vector<int> answer = solution(5, stages);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
}