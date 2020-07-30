#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef struct
{
  int idx;
  int h;
} Info;
// 완전탐색

// stack
vector<int> solution(vector<int> heights)
{
  vector<int> answer(heights.size());
  stack<Info> s;
  Info tmp;
  for (int i = heights.size() - 1; i >= 0; i--)
  {
    while (!s.empty() && heights[i] > s.top().h)
    {
      answer[s.top().idx] = i + 1;
      s.pop();
    }
    tmp.h = heights[i];
    tmp.idx = i;
    s.push(tmp);
  }
  return answer;
}

int main()
{
  vector<int> heights{6, 9, 5, 7, 4};
  vector<int> answer = solution(heights);
  for (int i = 0; i < answer.size(); i++)
  {
    printf("%d", answer[i]);
  }
}