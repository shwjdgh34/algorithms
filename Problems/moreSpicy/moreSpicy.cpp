#include <string>
#include <vector>
#include <queue>
using namespace std;
#define pivot 333333333
bool dsc(int a, int b)
{
    return a > b;
}
int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // pq 쓰는법 공부
    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    while (pq.top() < K)
    {
        if (pq.size() == 1)
            return -1;
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        if (tmp1 < pivot)
        {
            int mix = tmp1 + tmp2 * 2;
            pq.push(mix);
        }
        answer++;
        if (pq.size() == 0)
            return answer;
    }

    return answer;
}
int main()
{
    vector<int> scoville{1, 2, 3, 9, 10, 12};
    int K = 7;
    printf("%d\n", solution(scoville, K));
}