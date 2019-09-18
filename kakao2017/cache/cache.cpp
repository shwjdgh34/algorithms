#include <string>
#include <vector>

using namespace std;
string makeStringLower(string curString)
{
    for (int i = 0; i < curString.size(); i++)
    {
        if (curString[i] < 'a')
            curString[i] += 32;
    }
    return curString;
}
int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    vector<string> q;
    for (int i = 0; i < cities.size(); i++)
    {
        bool hit = false;
        string curString = cities[i];
        string lowerString = makeStringLower(curString);
        for (int j = 0; j < cacheSize; j++)
        {
            if (q.size() == 0)
                break;
            int endIdx = q.size() - 1;
            if (q[endIdx - j] == lowerString)
            {
                hit = true;
            }
        }
        if (!hit)
        {
            answer += 5;
            q.push_back(lowerString);
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