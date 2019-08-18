
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
//------------user define------------
#define NULL 0
#define MAX_LEN 21

//------------------------------------

#include <stdio.h>

typedef enum
{
    MAKE = 1,
    CHANGE,
    REMOVE,
    FIND
} COMMAND;

//-----------------------------------------------
typedef struct _node
{
    char name[MAX_LEN];
    struct _node *prev;
    struct _node *next;
} Node;
class Linkedlist
{
private:
    char dirName[MAX_LEN];
    int num;
    Node *head;
    Node *tail;
    Node *itr;

public:
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
        itr = NULL;
        num = 0;
    }
    void add(char keyword[])
    {
        if (find(keyword)) // 해당 dir이 있다면 바로 return
            return;
        else // 해당 이름의 dir이 없다면 만들어준다.
        {
            if (head == NULL) // 처음 만들어 주는 경우
            {
                Node *newNode = new Node;
            }
        }
    }
};

// User API

void init();
void make(char keyword[]);
void change(char keyword[]);
int remove(char keyword[]);
int find(char keyword[]);
//-----------------------------------------------

static int run(int Ans)
{
    int N = 0;
    scanf("%d", &N);

    init();

    int cmd, ret;
    char keyword[21];
    int score = 0, cnt = 0, answer;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d %s", &cmd, keyword);

        switch (cmd)
        {
        case MAKE:
            make(keyword);
            break;

        case CHANGE:
            change(keyword);
            break;

        case REMOVE:
            scanf("%d", &answer);
            ret = remove(keyword);
            if (answer != ret)
                Ans = 0;
            break;

        case FIND:
            scanf("%d", &answer);
            ret = find(keyword);
            if (answer != ret)
                Ans = 0;
            break;

        default:
            break;
        }
    }
    return Ans;
}

int main()
{
    //setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

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
    //--------------------------------
    //  코드 작성
    //--------------------------------
}
void make(char keyword[])
{
    //--------------------------------
    //  코드 작성
    //--------------------------------
}
void change(char keyword[])
{
    //--------------------------------
    //  코드 작성
    //--------------------------------
}
int remove(char keyword[])
{
    //--------------------------------
    //  코드 작성
    //--------------------------------

    return 0;
}
int find(char keyword[])
{
    //--------------------------------
    //  코드 작성
    //--------------------------------
    return 0;
}
