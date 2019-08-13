#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define INF 0x7FFFFFFF
typedef struct
{
    int arr[200000];
} Arr;

void init();
bool compare(int a, int b);
void placeDataset(int, int);
Arr check;
Arr flashDrive;
Arr dataSize;
Arr initArr;
int n;
int k;
int maxWear;
int ans; // memoization
int main()
{
    int T;
    ifstream myFile("sample_input.txt");
    myFile >> T;
    for (int testcase = 1; testcase <= T; testcase++)
    {
        init();
        myFile >> n >> k;
        for (int i = 0; i < n; i++)
        {
            myFile >> flashDrive.arr[i];
        }
        for (int i = 0; i < k; i++)
        {
            myFile >> dataSize.arr[i];
        }
        sort(dataSize.arr, dataSize.arr + k, compare);
        placeDataset(0, 0);

        cout << "#" << testcase << " :"
             << ans << endl;
    }
}
bool compare(int a, int b)
{
    return a > b;
}
void init()
{
    ans = INF;
    check = initArr;
    flashDrive = initArr;
    dataSize = initArr;
}

void placeDataset(int curDataIndex, int curMaxWear)
{
    // base case
    if (curDataIndex >= k)
    {
        if (ans > curMaxWear)
            ans = curMaxWear;
        return;
    }

    int curDataSize = dataSize.arr[curDataIndex];
    for (int i = 0; i < n - curDataSize + 1; i++)
    {
        bool crash = false;
        int tmpMaxWear = curMaxWear;
        for (int j = 0; j < curDataSize; j++)
        {
            if (check.arr[i + j])
            {
                crash = true;
                break;
            }

            if (tmpMaxWear < flashDrive.arr[i + j]) //
            {
                tmpMaxWear = flashDrive.arr[i + j];
            }
        }
        if (crash)
            continue;

        for (int j = 0; j < curDataSize; j++)
        {
            check.arr[i + j] = true;
        }
        placeDataset(curDataIndex + 1, tmpMaxWear);
        for (int j = 0; j < curDataSize; j++)
        {
            check.arr[i + j] = false;
        }
    }
}