#include <string>
#include <vector>
#include <stack>
using namespace std;
typedef struct
{
    int p; //price
    int i; //idx
    int t; //time
} Info;
int globalT;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    answer.resize(prices.size());
    stack<Info> s;
    globalT = -1;
    for (int i = 0; i < prices.size(); i++)
    {
        globalT++;
        Info cur;
        cur.p = prices[i];
        cur.i = i;
        cur.t = globalT;
        while (!s.empty() && s.top().p > cur.p)
        {
            Info droppedPrice = s.top();
            s.pop();
            answer[droppedPrice.i] = globalT - droppedPrice.t;
        }
        s.push(cur);
    }
    while (!s.empty()) // 들어있는거 다 빼준다.
    {
        Info save = s.top();
        s.pop();
        answer[save.i] = globalT - save.t;
    }

    return answer;
}

int main()
{

    vector<int> prices{1, 2, 3, 2, 3};
    for (int i = 0; i < prices.size(); i++)
    {
        printf("%d\n", solution(prices)[i]);
    }
}