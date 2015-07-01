#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_PERIOD 10

unsigned int get_current_time(void)
{
    struct timespec ts = {0};

    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec + (ts.tv_nsec / 1000000000ULL));
}

int main()
{
    unsigned int t1=0, t2=0;

    t1 = get_current_time();
    t1 += TIME_PERIOD;


    int x=3;

    int y= 7;

    float result = y/x;

    printf("result1: %f\n", result);


    while (1)
    {
        t2 = get_current_time();

        if ( t2 >= t1 )
        {
            t1 = t2 + TIME_PERIOD;
            printf("TIMER EXPIRED! %d seconds have passed. t1 = %d\n", TIME_PERIOD, t1);
        }           
    }

    return 0;
}

/*EOF*/
