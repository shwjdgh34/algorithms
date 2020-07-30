#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct cmp
{
  bool operator()(vector<int> t, vector<int> u)
  {
    return t[1] > u[1];
  }
};

bool cmp2(vector<int> t, vector<int> u)
{
  return t[0] < u[0];
}
int solution(vector<vector<int>> jobs)
{
  sort(jobs.begin(), jobs.end(), cmp2);
  int answer = 0;
  int currentIdx = 0;
  int currentTime = 0;
  priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
  while (currentIdx < jobs.size() || !pq.empty())
  {
    for (int i = currentIdx; i < jobs.size() && jobs[i][0] <= currentTime; i++)
    {
      pq.push(jobs[i]);
      currentIdx++;
    }
    if (pq.empty())
    {
      currentTime = jobs[currentIdx][0];
      continue;
    }

    vector<int> currentJob = pq.top();
    pq.pop();
    answer += currentTime - currentJob[0] + currentJob[1];
    currentTime += currentJob[1];
  }
  return answer / jobs.size();
}

int main()
{
  vector<vector<int>> jobs{{0, 9}, {0, 4}, {0, 5}, {0, 7}, {0, 3}};
  cout << solution(jobs);
}