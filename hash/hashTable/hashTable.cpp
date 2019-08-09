#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#define NULL 0
#include <stdio.h>

typedef unsigned long long ulong;
typedef struct node
{
    ulong data;
    struct node *next;
} Node;

class linked_list
{
private:
    Node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(ulong key)
    {
        Node *tmp = new Node;
        tmp->data = key;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    bool isExist(ulong key)
    {
        Node *cur;
        cur = head;
        while (cur != NULL)
        {
            if (cur->data == key)
                return true;
            else
            {
                cur = cur->next;
            }
        }

        return false;
    }
    void clear()
    {
        Node *tmp;
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = NULL;
    }
};

typedef unsigned long long ulong;
//-----------------------------------
//	User API
void init();
int checkKey(ulong key);
//-----------------------------------
linked_list hash_memory[1000000];
static int run(int Ans) // Q.static 하는 이유?
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
    setbuf(stdout, NULL);
    freopen("key_input_score.txt", "r", stdin);
    int T, Ans = 100;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        printf("#%d %d\n", tc, run(Ans));
    }

    return 0;
}

void init()
{
    for (int i = 0; i < 1000000; i++)
    {
        hash_memory[i].clear();
    }
}

int checkKey(ulong key)
{
    ulong hash_key = key % 1000000;

    if (!hash_memory[hash_key].isExist(key))
    {
        hash_memory[hash_key].add_node(key);
        return 1;
    }
    else
    {
        return 0;
    }
}