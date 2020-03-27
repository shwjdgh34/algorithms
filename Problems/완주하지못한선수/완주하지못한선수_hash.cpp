#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
  unordered_map<string, int> completionMap;
  string answer = "";
  for (int i = 0; i < completion.size(); i++)
  {
    string key = completion[i];
    completionMap[key] += 1;
  }
  for (int i = 0; i < participant.size(); i++)
  {
    string key = participant[i];
    if (completionMap[key] == 0)
    {
      answer = key;
      break;
    }
    else
      completionMap[key] -= 1;
  }
  return answer;
}
int main()
{
  vector<string> participant{"mislav", "stanko", "mislav", "ana"};
  vector<string> completion{"stanko", "ana", "mislav"};
  cout << solution(participant, completion) << endl;
}