// 1시간 10분
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int val;
    int key;
} Info;
bool sortByVal(Info a, Info b)
{
    return a.val < b.val;
}
bool sortByKey(Info a, Info b)
{
    return a.key < b.key;
}

int solution(vector<int> food_times, long long k)
{
    int answer = 0;
    int curIdx = 0;
    long long curCycle = 0;
    int length = food_times.size();
    long long curLen = length - curIdx;
    vector<Info> food_times_sort_val(length);
    for (int i = 0; i < food_times.size(); i++)
    {
        Info tmpInfo;
        tmpInfo.val = food_times[i];
        tmpInfo.key = i + 1;
        food_times_sort_val[i] = tmpInfo;
    }
    sort(food_times_sort_val.begin(), food_times_sort_val.end(), sortByVal);

    while (k >= curLen && curIdx < length)
    {

        long long timeCount = (food_times_sort_val[curIdx].val - curCycle) * curLen;
        if (timeCount > k)
        {
            k %= curLen;
        }
        else if (timeCount <= k)
        {
            k -= timeCount;
            curCycle = food_times_sort_val[curIdx].val;
        }

        while (food_times_sort_val[curIdx].val <= curCycle)
        {
            curIdx++;
            if (curIdx >= length)
                return -1;
        }
        curLen = length - curIdx;
    }

    vector<Info> food_times_sort_key(curLen);
    for (int i = 0; i < curLen; i++)
    {
        food_times_sort_key[i] = food_times_sort_val[i + curIdx];
    }
    sort(food_times_sort_key.begin(), food_times_sort_key.end(), sortByKey);
    answer = food_times_sort_key[k].key;
    return answer;
}
int main()
{
    vector<int> food_times{7, 6, 5};
    long long k = 5;
    printf("%d\n", solution(food_times, 16));
    return 0;
}