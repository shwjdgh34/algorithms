#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arrN;

int bSearchRec(int low, int high, int target)
{
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    if (arrN[mid] == target)
        return 1;
    else if (arrN[mid] > target)
        return bSearchRec(low, mid - 1, target);
    else
        return bSearchRec(mid + 1, high, target);
}
int bSearchLoop(int n, int target)
{
    int start = 0;
    int end = n;
    int mid;
    while (end >= start)
    {
        mid = (end + start) / 2;
        if (arrN[mid] == target)
            return 1;
        else if (arrN[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}
int main()
{
    int n, m;

    int tmp;
    vector<int> arrM;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        arrN.push_back(tmp);
    }
    scanf("%d", &m);

    sort(arrN.begin(), arrN.end());
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        printf("%d\n", bSearchLoop(n - 1, tmp));
    }
}