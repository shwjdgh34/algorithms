#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

typedef struct
{
  int l;
  int p;
} Info;

int solution(vector<int> priorities, int location)
{
  int answer = 0;
  Info tmpInfo;
  deque<Info> dq;
  priority_queue<int> pq;
  for (int i = 0; i < priorities.size(); i++)
  {
    tmpInfo.l = i;
    tmpInfo.p = priorities[i];
    dq.push_back(tmpInfo);
    pq.push(priorities[i]);
  }
  while (1)
  {
    while (pq.top() != dq.front().p)
    {
      tmpInfo = dq.front();
      dq.push_back(tmpInfo);
      dq.pop_front();
    }
    answer++;
    pq.pop();
    if (location == dq.front().l || pq.empty())
      break;
    dq.pop_front();
  }
  return answer;
}
int main()
{
  vector<int> priorities{1, 1, 9, 1, 1, 1};
  int location = 0;
  cout << solution(priorities, location);
}