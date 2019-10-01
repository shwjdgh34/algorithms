#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    map<string, bool> wordMap;
    int i;
    for (i = 0; i < words.size(); i++)
    {
        //끝말 이었는지
        if (i != 0)
        {
            if (words[i - 1].back() != words[i].front())
                break;
        }
        // 이미 말한건 아닌지
        auto itr = wordMap.find(words[i]);
        if (itr == wordMap.end())
            wordMap[words[i]] = true;
        else
            break;
    }
    if (i == words.size())
        answer = {0, 0};
    else
        answer = {(i % n) + 1, (i / n) + 1};

    return answer;
}
int main()
{
    vector<int> answer;
    int n = 2;
    vector<string> words{"hello", "one", "even", "never", "now", "world", "draw"};
    answer = solution(n, words);
    cout << answer[0] << answer[1];
}