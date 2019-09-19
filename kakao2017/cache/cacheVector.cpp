#include <string>
#include <vector>
#include <algorithm>
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
    vector<string> cache;
    for (int i = 0; i < cities.size(); i++)
    {

        string curString = cities[i];
        string lowerString = makeStringLower(curString);
        auto itr = find(cache.begin(), cache.end(), lowerString);

        if (itr == cache.end()) // 못찾은 경우
        {
            answer += 5;
            if (cache.size() == cacheSize && cacheSize != 0)
                cache.pop_back();
        }
        else
        {
            answer += 1; // 찾은경우
            cache.erase(itr);
        }
        if (cacheSize != 0) // 이걸 안해주면 테스트 케이스 두개 틀린다.
            cache.insert(cache.begin(), lowerString);
    }
    return answer;
}

int main()
{
    int cacheSize = 3;
    vector<string> cities{"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"};
    printf("%d\n", solution(cacheSize, cities));
}