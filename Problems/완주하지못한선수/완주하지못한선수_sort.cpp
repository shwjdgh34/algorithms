#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
  string answer = "";
  sort(participant.begin(), participant.end());
  sort(completion.begin(), completion.end());
  for (int i = 0; i < participant.size(); i++)
  {
    cout << participant[i] << endl;
  }
  for (int i = 0; i < completion.size(); i++)
  {
    cout << completion[i] << endl;
  }
  // for (int i = 0; i < completion.size(); i++)
  // {
  //   if (participant[i] != completion[i])
  //     return participant[i];
  // }
  // return participant[participant.size() - 1];
  return "The end";
}
int main()
{
  vector<string> participant{"mislav", "stanko", "mislav", "ana"};
  vector<string> completion{"stanko", "ana", "mislav"};
  cout << solution(participant, completion) << endl;
}