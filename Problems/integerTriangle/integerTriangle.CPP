#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int triHeight = triangle.size();

    vector<vector<int>> ansTri(triHeight, vector<int>(triHeight));

    ansTri[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                ansTri[i][j] = ansTri[i - 1][j] + triangle[i][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                ansTri[i][j] = ansTri[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                ansTri[i][j] = max(ansTri[i - 1][j - 1], ansTri[i - 1][j]) + triangle[i][j];
            }
        }
    }
    for (int i = 0; i < triangle[triHeight - 1].size(); i++)
    {
        if (answer < ansTri[triHeight - 1][i])
            answer = ansTri[triHeight - 1][i];
    }
    return answer;
}
int main()
{
    vector<vector<int>> triangle{{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

    printf("%d\n", solution(triangle));
}