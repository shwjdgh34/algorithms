#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
  string answer = "";
  vector<bool> check(completion.size(), false);
  bool isCompleted;
  for (int i = 0; i < participant.size(); i++)
  {
    isCompleted = false;
    for (int j = 0; j < completion.size(); j++)
    {
      if (participant[i] == completion[j] && !check[j])
      {
        check[j] = true;
        isCompleted = true;
        break;
      }
    }
    if (!isCompleted)
    {
      answer = participant[i];
      break;
    }
  }
  return answer;
}
int main()
{
  vector<string> participant{"mislav", "stanko", "mislav", "ana"};
  vector<string> completion{"stanko", "ana", "mislav"};
  cout << solution(participant, completion) << endl;
}