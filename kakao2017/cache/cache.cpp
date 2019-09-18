#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    vector<string> q;
    for (int i = 0; i < cities.size(); i++)
    {
        bool hit = false;
        string curString = cities[i];
        for (int j = 0; j < cacheSize; j++)
        {
            if (q.size() == 0)
                break;
            int endIdx = q.size() - 1;
            if (q[endIdx - j] == curString)
            {
                hit = true;
            }
        }
        if (!hit)
        {
            answer += 5;
            q.push_back(curString);
        }
        else
            answer += 1;
    }
    return answer;
}

int main()
{
    int cacheSize = 3;
    vector<string> cities{"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    printf("%d\n", solution(cacheSize, cities));
}