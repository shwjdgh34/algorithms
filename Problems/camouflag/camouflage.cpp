#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define HASH_SIZE 100
typedef struct
{
    string kind;
    int num;
} HashMap;
HashMap hashmap[HASH_SIZE];
int hashCode(string s)
{
    int i;
    int r = 0;

    // Special Prime Number
    int a = 13;

    for (i = 0; i < s.length(); i++)
    {
        r += r * a + s[i];
        r %= 99;
    }

    return r;
}
void init()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hashmap[i].kind = "nothing";
        hashmap[i].num = 0;
    }
}
int solution(vector<vector<string>> clothes)
{
    init();
    int answer = 1;

    for (int i = 0; i < clothes.size(); i++)
    {
        int hash = hashCode(clothes[i][1]);
        while (1)
        {
            if (hashmap[hash].num == 0)
            { // hash맵에 아무것도 없는경우
                hashmap[hash].kind = clothes[i][1];
                hashmap[hash].num++;
            }
            else
            { // hashmap에 이미 데이터가 들어있는 경우
                if (hashmap[hash].kind == clothes[i][1])
                { // 실제 종류가 일치하는경우 num++
                    hashmap[hash].num++;
                }
                else
                { // collision 발생할경우
                    hash++;
                    continue;
                }
            }
            break;
        }
    }
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (hashmap[i].num == 0)
            continue;
        answer *= (hashmap[i].num + 1);
    }
    answer -= 1;
    return answer;
}

int main()
{
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes) << endl;
}
