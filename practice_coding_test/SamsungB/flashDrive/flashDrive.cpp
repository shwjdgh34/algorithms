#include <iostream>
#include <fstream>

using namespace std;
#define SIZE 200000
#define INF 0x7fffffff
typedef struct
{
    int arr[SIZE];
} Arr;

void init();
bool placeDataset(int);
void binary_search();

Arr flashDrive;
Arr dataSize;
Arr initArr;

int n;
int k;

int possibleMinWear;

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
        binary_search();

        cout << "#" << testcase << " "
             << possibleMinWear << endl;
    }
}

void init()
{
    possibleMinWear = INF;
    flashDrive = initArr;
    dataSize = initArr;
}

void binary_search()
{
    int maxWear = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (flashDrive.arr[i] > maxWear)
            maxWear = flashDrive.arr[i];
    }
    int high = maxWear;
    int low = 1;
    int mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (placeDataset(mid))
        { // 현재의
            high = mid - 1;
            possibleMinWear = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
}
bool placeDataset(int maxWear)
{
    int driveIdx = 0;
    for (int i = 0; i < k; i++)
    {
        int curSize = dataSize.arr[i];
        int count = 0;

        while (curSize != count)
        {
            if (driveIdx == n)
                return false;
            if (flashDrive.arr[driveIdx] <= maxWear)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            driveIdx++;
        }
    }
    return true;
}