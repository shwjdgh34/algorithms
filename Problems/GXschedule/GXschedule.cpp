#include <stdio.h>

#define GXMAX 1000
#define USERMAX 1000
#define MANMAX 40
//  #define NULL 0  // 코드 제출할때 첨가
typedef enum
{
    CMD_SEARCH = 1,
    CMD_ADD,
    CMD_MODIFY,
    CMD_DELETE,
    CMD_REGISTER,
    CMD_CANCEL,
} CMD;

enum
{
    ALLTYPE = 0,
    YOGA,
    STRETCH,
    PILATES,
    SPINNING,
    PUMP,
    CIRCUIT,
    STEP,
    TABATA,
    TYPE_MAX,
};

enum
{
    ALLDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    DAY_MAX,
};

enum
{
    ALLTIME = 0,
    TIME1,
    TIME2,
    TIME3,
    TIME4,
    TIME_MAX,
};

//////////////////mycode///////////////////

typedef struct _gxnode
{
    int gxId;
    int type;
    int day;
    int time;
    int maxNum;
    struct _gxnode *next;
} GXNode;

class linkedlist
{
private:
    GXNode *head;
    GXNode *tail;
    GXNode *cur;
    int GXnum;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
        GXnum = 0;
    }
    void init()
    {
        clear();
        GXnum = 0; // 이걸 초기화 안해서 한참 고생했다.
    }
    void push(int gxId, int type, int day, int time, int maxNum)
    {
        if (maxNum <= GXnum)
            return;
        GXnum++;
        GXNode *tmp = new GXNode;
        tmp->gxId = gxId; // 좀 더 쉬운 assign 없을까?
        tmp->type = type;
        tmp->day = day;
        tmp->time = time;
        tmp->maxNum = maxNum;
        tmp->next = NULL;
        if (head == NULL) // first case
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
    int sumAll()
    {
        cur = head;
        int sum = 0;
        if (cur == NULL)
            return 0;
        while (cur != NULL)
        {
            sum += cur->gxId;
            cur = cur->next;
        }
        return sum;
    }
    void clear()
    {
        GXNode *tmp;
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = NULL;
    }
};

linkedlist GXlist[9][6][5];
bool userMap[1001]; // 수강신청했다면 true
////////////////////////////////////////////////

void init_user();
void addGX_user(int gxId, int type, int day, int time, int maxNum);
int searchGX_user(int type, int day, int time);

static int Score;

static void init()
{
    Score = 0;
    init_user();
}

static void addGX()
{
    int gxID, type, day, time, maxNum;
    scanf("%d %d %d %d %d", &gxID, &type, &day, &time, &maxNum);
    addGX_user(gxID, type, day, time, maxNum);
}

static void searchGX()
{
    int type, day, time, checkSum;
    scanf("%d %d %d %d", &type, &day, &time, &checkSum);
    int userSum = searchGX_user(type, day, time);
    if (userSum == checkSum)
        Score++;
    else
        printf("[Error:Search] type:%d, day:%d, time:%d, checkSum:%d, userSum:%d \n", type, day, time, checkSum, userSum);
}

void run()
{
    init();

    int N;
    scanf("%d", &N);
    while (N--)
    {
        int cmd;
        scanf("%d", &cmd);
        if (N == 162)
        {
            int no = 0;
        }
        switch (cmd)
        {
        case CMD_ADD:
            addGX();
            break;
        case CMD_SEARCH:
            searchGX();
            break;
        }
    }
}

int main(void)
{
    //setbuf(stdout, NULL);
    freopen("input1.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    int TotalScore = 0;
    for (int tc = 1; tc <= T; tc++)
    {
        run();
        printf("#%d %d\n", tc, Score);
        TotalScore += Score;
    }
    printf("Total Score is %d\n", TotalScore);
    return 0;
}
///////////////////////my code //////////////////////////
void init_user()
{
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            for (int k = 1; k < 5; k++)
            {
                GXlist[i][j][k].init();
            }
        }
    }
    return;
}
void addGX_user(int gxId, int type, int day, int time, int maxNum)
{
    if (gxId < 1 || gxId > 1000)
        return;
    GXlist[type][day][time].push(gxId, type, day, time, maxNum);
}
int searchGX_user(int type, int day, int time)
{
    return GXlist[type][day][time].sumAll();
}
////////////////////////////////////////////////////////