#include <iostream>

using namespace std;
int n;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }