// 28분

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> relation)
{
    vector<int> answerList;
    int answer = 0;
    int col = relation[0].size();
    int row = relation.size();
    int num = 1 << col;

    for (int i = 1; i < num; i++)
    {
        bool isMinimality = true;
        vector<string> rowTmp;
        // 최소성(minimality) 판별
        for (int z = 0; z < answerList.size(); z++)
        {
            if ((i & answerList[z]) == answerList[z])
                isMinimality = false;
        }
        if (!isMinimality)
            continue;
        bool isUnique = true;
        for (int j = 0; j < row; j++)
        {
            string tmp;

            for (int k = 0; k < col; k++)
            {
                if (i & (1 << k))
                {
                    tmp += relation[j][k];
                }
            }
            if (rowTmp.size() == 0)
            {
                rowTmp.push_back(tmp);
                continue;
            }
            for (int z = 0; z < rowTmp.size(); z++)
            {
                if (tmp == rowTmp[z])
                    isUnique = false;
            }
            if (!isUnique)
                break;
            rowTmp.push_back(tmp);
        }
        if (isUnique)
            answerList.push_back(i);
    }
    answer = answerList.size();
    return answer;
}
int main()
{
    vector<vector<string>> relation{{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};
    cout << solution(relation) << endl;
}