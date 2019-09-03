#include <string>
#include <vector>

using namespace std;
#define pivot 333333333
bool dsc(int a, int b)
{
    return a > b;
}
int solution(vector<int> scoville, int K)
{
    int answer = 0;
    sort(scoville.begin(), scoville.end(), dsc);
    while (1)
    {
        int size = scoville.size();

        if (size == 0)
            return answer;

        if (scoville.back() > K)
            return answer;
        if (size == 1)
            return -1;
        if (scoville.back() < pivot)
        {
            int mix = scoville[size - 1] + scoville[size - 2] * 2;
            scoville.pop_back();
            scoville.pop_back();
            scoville.push_back(mix);
        }
        else
        {
            scoville.pop_back();
            scoville.pop_back();
        }
        answer++;
        sort(scoville.begin(), scoville.end(), dsc);
    }

    return answer;
}
int main()
{
    vector<int> scoville{1, 2, 3, 9, 10, 12};
    int K = 7;
    printf("%d\n", solution(scoville, K));
}