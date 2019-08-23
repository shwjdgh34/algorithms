////////////////////////////////////////////////////////

// just completed make() change() functions.

///////////////////////////////////////////////////////

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
//-------------------------
#define MAX_NUM 27010
#ifndef NULL
#define NULL 0
#endif
#define ROOT 0
//-------------------------
typedef enum
{
    MAKE = 1,
    CHANGE,
    REMOVE,
    FIND
} COMMAND;

//-----------------------------------------------
// User API

typedef struct _node
{
    char dirName[21];
    int idx;
    struct _node *next;
    struct _node *prev;
} Node;

int curDir;
int curDirNum;
char rootString[] = "/";
char parentString[] = "..";
void init();
void make(char keyword[]);
void change(char keyword[]);
int remove(char keyword[]);
int find(char keyword[]);
int strcmp(char s[], char t[]);
void strcpy(char s[], char t[]);

class Linkedlist
{
public:
    Node *head;
    Node *itr;
    int parent;
    int idx; // 전에 짰던 코드에선 이게 있었나;;
    Linkedlist()
    {
        head = NULL;
        itr = NULL;
        parent = 0;
        idx = 0;
    }
    bool isExistInThisDir(char keyword[])
    {
        itr = head;
        while (itr != NULL)
        {
            if (strcmp(keyword, itr->dirName) == 0) // 같다면
                return true;
            itr = itr->next;
        }
        return false;
    }
    void add(char keyword[]);
    void changeDir(char keyword[])
    {
        // ".."
        // "/"
        if (strcmp(parentString, keyword) == 0)
        {
            curDir = parent;
        }
        else if (strcmp(rootString, keyword) == 0)
        {
            curDir = ROOT;
        }
        else
        {
            if (!isExistInThisDir(keyword))
                return;
            curDir = itr->idx;
        }
    }
};
Linkedlist dirList[MAX_NUM];
void Linkedlist::add(char keyword[])
{
    if (isExistInThisDir(keyword))
        return;
    Node *tmpAdd = new Node; // new Node -> static
    strcpy(keyword, tmpAdd->dirName);
    tmpAdd->next = NULL;
    tmpAdd->prev = NULL;
    tmpAdd->idx = curDirNum;
    dirList[curDirNum].idx = curDirNum;
    dirList[tmpAdd->idx].parent = idx;
    curDirNum++;

    if (head == NULL)
    {
        head = tmpAdd;
    }
    else
    {
        tmpAdd->next = head;
        head->prev = tmpAdd;
        head = tmpAdd;
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
    curDir = ROOT;
    curDirNum = 1;
}
void make(char keyword[])
{

    dirList[curDir].add(keyword);
}
void change(char keyword[])
{
    dirList[curDir].changeDir(keyword);
}
int remove(char keyword[])
{
    return 1;
}
int find(char keyword[])
{
    return 1;
}
int strcmp(char s[], char t[])
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
            return 0;
    }
    return s[i] - t[i];
}
void strcpy(char s[], char t[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}