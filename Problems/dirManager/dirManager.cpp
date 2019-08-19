
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
//------------user define------------
#define NULL 0
#define MAX_LEN 21
#define MAX_NUM 27010
#define ROOT "/"
#define UPPER ".."
#define STAR "*"
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

// User API
void strcpy(char *target, char *source);
bool strcmp(char *target, char *source);
void init();
void make(char keyword[]);
void change(char keyword[]);
int remove(char keyword[]);
int find(char keyword[]);

int curDir;
int dirTotalNum;
char upper[MAX_LEN] = UPPER;
char root[MAX_LEN] = ROOT;
char star[MAX_LEN] = STAR;
int removeCount;
typedef struct _node
{
    char name[MAX_LEN];
    int idx;
    struct _node *prev;
    struct _node *next;
} Node;
class Linkedlist
{
public:
    int parent;
    int idx;
    int childNum; // 자식 dir의 개수
    Node *head;
    Node *tail;
    Node *itr;
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
        itr = NULL;
        childNum = 0;
    }
    void add(char keyword[]);

    // keyword와 같은 폴더명이 있는지 찾고, 찾았다면 curDir를 해당 idx로 바꿔주고 true 반환
    bool find(char keyword[])
    {
        while (itr != NULL)
        {
            if (strcmp(itr->name, keyword))
            {
                return true;
            }

            itr = itr->next;
        }
        return false;
    }
    void change(char keyword[])
    {
        if (strcmp(keyword, upper))
            curDir = parent;
        else if (strcmp(keyword, root))
            curDir = 0;
        else if (find(keyword))
        {
            curDir = itr->idx;
            itr = head;
        }
    }
    void removeNodes(char keyword[]);
};
Linkedlist fileList[MAX_NUM];

void Linkedlist::add(char keyword[])
{
    if (find(keyword)) // 해당 dir이 있다면 바로 return
        return;
    else // 해당 이름의 dir이 없다면 만들어준다.
    {
        Node *newNode = new Node;
        strcpy(newNode->name, keyword);
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->idx = dirTotalNum++;
        fileList[newNode->idx].parent = idx;       // parent's idx
        fileList[newNode->idx].idx = newNode->idx; // child'x idx;

        if (head == NULL) // 처음 만들어 주는 경우
        {
            head = newNode;
            tail = newNode;
            itr = head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        childNum++;
    }
}
void Linkedlist::removeNodes(char keyword[])
{
    if (head == NULL)
    {
        removeCount++;
        return;
    }
    while (find(keyword))
    {
        Node *delTmp = itr;

        fileList[itr->idx].removeNodes(star);
        if (itr != head && itr != tail)
        {
            Node *tmpPrev = itr->prev;
            Node *tmpNext = itr->next;
            tmpPrev->next = tmpNext;
            tmpNext->prev = tmpPrev;
            itr = tmpNext;
            delete delTmp;
            childNum--;
        }
        else if (itr == head)
        {
            head =
        }
    }
}
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
    dirTotalNum = 1;
    curDir = 0; // root 폴더
    fileList[0].idx = 0;
    fileList[0].parent = -1; // 최상위라 parent가 없다.
    //--------------------------------
}
void make(char keyword[])
{
    //--------------------------------
    //  코드 작성
    fileList[curDir].add(keyword);

    //--------------------------------
}
void change(char keyword[])
{
    //--------------------------------
    //  코드 작성
    fileList[curDir].change(keyword);
    //--------------------------------
}
int remove(char keyword[])
{
    //--------------------------------
    //  코드 작성
    removeCount = 0;
    fileList[curDir].removeNodes(keyword);
    return removeCount;
    //--------------------------------
}
int find(char keyword[])
{
    //--------------------------------
    //  코드 작성
    //--------------------------------
    return 0;
}
void strcpy(char *target, char *source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
}
bool strcmp(char *target, char *source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        if (source[i] == '*')
            return true;
        if (source[i] != target[i])
            return false;

        i++;
    }
    if (target[i] != '\0')
        return false;
    return true;
}