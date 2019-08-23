#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

typedef unsigned long long ulong;

//-----------------------------------
//	User API
#define KEY_NUM 1500000
#define HASH_SIZE KEY_NUM / 15
typedef struct _node
{
    ulong k;
    struct _node *next;
    struct _node *prev;
} Node;

class Linkedlist
{
public:
    Node *head;
    Node *itr;
    Linkedlist()
    {
        head = NULL;
        itr = NULL;
    }
    // checkKey
    int check(ulong key)
    {
        Node *tmp = new Node;
        tmp->k = key;
        tmp->prev = NULL;
        tmp->next = NULL;

        // 해당 linked list 가 비어 있을 경우.
        if (head == NULL)
        {
            head = tmp;
            return 1;
        }
        // itr init;
        itr = head;
        // 다 순회하면서 있는지 검사
        while (itr != NULL)
        {
            if (key == itr->k)
                return 0;
            itr = itr->next;
        }
        // 끝끝내 안나왔을 때 추가해주고 return
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
        return 1;
    }

    void clear()
    {
        itr = head;
        while (itr != NULL)
        {
            Node *tmpDel = itr;
            itr = itr->next;
            delete tmpDel;
        }
        head = NULL;
    }
};
Linkedlist hash[HASH_SIZE];
void init()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash[i].clear();
    }
}
int hashFunc(ulong key)
{
    return key % HASH_SIZE;
}
int checkKey(ulong key)
{
    int h = hashFunc(key);
    return hash[h].check(key);
}
//-----------------------------------

static int run(int Ans)
{
    init();

    int N, ret = 0;
    ulong key;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %d", &key, &ret);

        if (ret != checkKey(key))
            Ans = 0;
    }
    return Ans;
}
int main()
{
    //setbuf(stdout, NULL);
    freopen("key_input_score.txt", "r", stdin);
    int T, Ans = 100;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        printf("#%d %d\n", tc, run(Ans));
    }

    return 0;
}