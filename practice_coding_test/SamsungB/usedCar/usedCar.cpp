#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct CAR
{
    int age;       // 0 ~ 19
    int passenger; // 2 ~ 12
    int engine;    // 1000 ~ 4999
    int price;     // 10000 ~ 39999
};

void buy(CAR car);

void filter_by_age(int from, int to);
void filter_by_passenger(int from, int to);
void filter_by_engine(int from, int to);
void filter_by_price(int from, int to);

int sell(void);
void refund(int order_number);
int empty(void);
//-----------------------user code-----------------------------

//--------------------------------------------------------------
static void build(CAR *car)
{
    car->age = rand() % 20;
    car->passenger = 2 + (rand() % 11);
    car->engine = 1000 + (rand() % 4000);
    car->price = 10000 + (rand() % 30000);
}

static const int MAX_CAR = 1000000;

int main(void)
{
    setbuf(stdout, NULL);
    srand(3);

    int PERFORMANCE = 0;
    int order_number = -1;

    for (int TRY = 1; TRY <= 10; TRY++)
    {
        printf("%d: ", TRY);
        time_t start = clock();

        for (int c = 0; c < MAX_CAR; c++)
        {
            CAR car;

            build(&car);
            buy(car);

            if ((rand() % 100) == 0)
            {
                filter_by_age(rand() % 20, rand() % 20);
                filter_by_passenger(2 + (rand() % 11), 2 + (rand() % 11));
                filter_by_engine(1000 + (rand() % 4000), 1000 + (rand() % 4000));
                filter_by_price(10000 + (rand() % 30000), 10000 + (rand() % 30000));
                int ret = sell();
                if ((rand() % 10) == 0)
                    order_number = ret;
            }

            if ((rand() % 10000) == 0)
            {
                if (order_number != -1)
                {
                    refund(order_number);
                    order_number = -1;
                }
            }
        }

        int RESULT = empty();
        order_number = -1;
        PERFORMANCE += ((clock() - start) / (CLOCKS_PER_SEC / 1000));
        printf("STOCK = %d\n", RESULT);
    }

    printf("PERFORMANCE = %d\n", PERFORMANCE);

    return 0;
}

//------------------------user code----------------------
void buy(CAR car)
{
}

void filter_by_age(int from, int to)
{
}

void filter_by_passenger(int from, int to)
{
}

void filter_by_engine(int from, int to)
{
}

void filter_by_price(int from, int to)
{
}

int sell(void)
{
    return 0; // order_number ( >= 0)
}

void refund(int order_number)
{
}

int empty(void)
{
    return 0;
}
//--------------------------------------------------------------