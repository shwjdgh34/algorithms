#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAX 30000

int base[MAX], diff[MAX], sum[MAX], ss[MAX];
bool chk[MAX];
vector<int> mp[MAX];
pair<int, int> vec[MAX];
int get_idx(int x)
{
    int it = lower_bound(ss, ss + MAX, x) - ss;
    if (it == MAX || ss[it] != x)
        return -1;
    return it;
}
void flip(int mat[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        swap(mat[i][0], mat[i][3]);
        swap(mat[i][1], mat[i][2]);
    }
}
void rotate(int mat[4][4])
{
    int temp[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            temp[j][3 - i] = mat[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = temp[i][j];
        }
    }
}
int makeBlock(int module[][4][4])
{
    for (int i = 0; i < MAX; i++)
        mp[i].clear();
    for (int i = 0; i < MAX; i++)
    {
        chk[i] = false;
        base[i] = 10;
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                base[i] = min(base[i], module[i][j][k]);
            }
        }
        diff[i] = 0;
        sum[i] = 0;
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int now = module[i][j][k] - base[i];
                sum[i] = sum[i] * 3 + now;
                diff[i] = max(diff[i], module[i][j][k] - base[i]);
            }
        }
        vec[i] = {base[i] + diff[i], i};
        ss[i] = sum[i];
    }
    sort(vec, vec + MAX);
    sort(ss, ss + MAX);
    for (int i = 0; i < MAX; i++)
    {
        int idx = vec[i].second;
        mp[get_idx(sum[idx])].push_back(idx);
    }
    int ret = 0;
    for (int i = MAX - 1; i >= 0; i--)
    {
        int idx = vec[i].second;
        if (chk[idx])
            continue;
        mp[get_idx(sum[idx])].pop_back();
        chk[idx] = true;
        int temp[4][4];
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                temp[j][k] = module[idx][j][k];
        flip(temp);
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if (j)
                rotate(temp);
            int tsum = 0;
            for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++)
                {
                    int now = diff[idx] - (temp[x][y] - base[idx]);
                    tsum = tsum * 3 + now;
                }
            tsum = get_idx(tsum);
            if (tsum == -1 || mp[tsum].empty())
                continue;
            int it = mp[tsum].back();
            chk[it] = true;
            ret += base[idx] + base[it] + diff[it];
            mp[tsum].pop_back();
            flag = true;
            break;
        }
    }
    return ret;
}

int main(void)
{
    static int module[MAX][4][4];

    srand(3); // 3 will be changed

    for (int tc = 1; tc <= 10; tc++)
    {
        for (int c = 0; c < MAX; c++)
        {
            int base = 1 + (rand() % 6);
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 4; x++)
                {
                    module[c][y][x] = base + (rand() % 3);
                }
            }
        }
        cout << "#" << tc << " " << makeBlock(module) << endl;
    }

    return 0;
}