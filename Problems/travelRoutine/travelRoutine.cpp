#include <string>
#include <vector>
#include <iostream>
//#include <stack>
using namespace std;
vector<bool> check(10000, false);
vector<vector<string>> answerList;
int numOfCities;
void dfs(vector<vector<string>> tickets, string curDest, vector<string> tmpAnswer)
{
    //base case
    if (tmpAnswer.size() == numOfCities)
    {
        answerList.push_back(tmpAnswer);
        return;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == curDest && check[i] == false)
        {
            string nextDest = tickets[i][1];
            check[i] = true;
            tmpAnswer.push_back(nextDest);
            dfs(tickets, nextDest, tmpAnswer);
            tmpAnswer.pop_back();
            check[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    vector<string> tmpAnswer;
    //stack<string> s;
    vector<bool> check(tickets.size(), false);
    numOfCities = tickets.size() + 1;
    string nextDest = "ICN";
    tmpAnswer.push_back(nextDest);
    dfs(tickets, nextDest, tmpAnswer);
    tmpAnswer.pop_back();

    for (int i = 1; answerList.size() > 1 && i < answerList[0].size(); i++)
    {
        for (auto itr = answerList.begin(); itr + 1 != answerList.end();)
        {
            string cur = (*itr)[i];
            string next = (*(itr + 1))[i];

            if ((*itr)[i].compare((*(itr + 1))[i]) > 0) // itr이 사전상 더 뒤에 있을 때
            {
                itr = answerList.erase(itr);
            }
            else if ((*itr)[i].compare((*(itr + 1))[i]) < 0) //  itr이 사전상 더 앞에 있을 때
            {
                answerList.erase(itr + 1);
            }
            else // 똑같을 때
            {
                itr += 1;
            }
        }
    }
    answer = answerList[0];
    return answer;
}

int main()
{
    vector<vector<string>> tickets{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    solution(tickets);
}