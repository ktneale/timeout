#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMEOUT_PERIOD 60  //In seconds

int main()
{
        time_t t0, t1, t2;

        time(&t0);  //Current time in seconds    
        t1 = t0 + TIMEOUT_PERIOD;  //Time period = 60 seconds
        printf("start: %d\n", (int)t1);

        while (1 )
        {
            time(&t2);

            if ( t2 >= t1 ) {
                t1 = t2 + TIMEOUT_PERIOD;
                printf("1 minute has passed: %d\n", (int)t1);
                printf("FLUSH:<message id=2324 attr><intamac-ping></intamac-ping>\n");
                printf("<message id=2134><intamac-alert>hub-recovery-mode</intamac-alert></message>\n");
            }        
        }
}
