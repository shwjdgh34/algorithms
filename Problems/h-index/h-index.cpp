#include <string>
#include <vector>

using namespace std;

bool desc(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end(), desc);
    for (int i = 0; i < citations.size(); i++)
    {
        int more = 0;
        int less = 0;
        int pivot = citations[i];
        for (int j = 0; j < citations.size(); j++)
        {
            if (pivot < citations[j])
                more++;
            if (pivot > citations[j])
                less++;
            if (pivot == citations[j])
            {
                more++;
                less++;
            }
        }
        if (more >= pivot && less <= pivot)
            return pivot;
        more = 0;
        less = 0;
    }
    return 0;
}
int main()
{
    vector<int> citations{3, 0, 6, 1, 5};
    printf("%d\n", solution(citations));
}