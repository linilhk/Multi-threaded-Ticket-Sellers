#include <stdio.h>
#include <pthread.h>
#include "Theater.c"

struct customer
{
    int arrive_time;
    int wait_time;  //time to process ordering
    int index;      //mark the order in the queue in order to print e.g. H101, 101 is the index
};

bool run = true;    //when theater full, it will be false, then no more running

void * sellerH1(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_H = 'H';

    //set seed for random arrive_time and processing time
    int seed = time(NULL);
	srand(seed);

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 3;
        if (cus[i].wait_time == 0)
            cus[i].wait_time =1;
    }

    /*
    //checking the values
    for(i = 0; i < *n; i++)
    {
        printf("H1 %d arrive time: %d\n", i, cus[i].arrive_time);
        printf("H1 %d wait time: %d\n", i, cus[i].wait_time);
    }
    */

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 1;
    }


    /*
    printf("H1 sorted\n");
    for(i = 0; i < *n; i++)
    {
        printf("H1 %d arrive time: %d\n", i, cus[i].arrive_time);
        printf("H1 %d wait time: %d\n", i, cus[i].wait_time);
        printf("H1 %d index: %d\n", i, cus[i].index);
    }
    */


    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_H, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerM1(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_M = 'M';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 3;
        cus[i].wait_time = cus[i].wait_time + 2;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 101;
    }

    /*
    printf("M1 sorted\n");
    for(i = 0; i < *n; i++)
    {
        printf("M1 %d arrive time: %d\n", i, cus[i].arrive_time);
        printf("M1 %d wait time: %d\n", i, cus[i].wait_time);
        printf("M1 %d index: %d\n", i, cus[i].index);
    }
    */

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_M, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }


    return NULL; // thread exits
}

void * sellerM2(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_M = 'M';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 3;
        cus[i].wait_time = cus[i].wait_time + 2;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 201;
    }

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_M, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerM3(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_M = 'M';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 3;
        cus[i].wait_time = cus[i].wait_time + 2;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 301;
    }

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_M, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerL1(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_L = 'L';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 4;
        cus[i].wait_time = cus[i].wait_time + 4;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 101;
    }

    /*
    printf("L1 sorted\n");
    for(i = 0; i < *n; i++)
    {
        printf("L1 %d arrive time: %d\n", i, cus[i].arrive_time);
        printf("L1 %d wait time: %d\n", i, cus[i].wait_time);
        printf("L1 %d index: %d\n", i, cus[i].index);
    }
    */

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_L, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerL2(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_L = 'L';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 4;
        cus[i].wait_time = cus[i].wait_time + 4;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 201;
    }

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_L, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerL3(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_L = 'L';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 4;
        cus[i].wait_time = cus[i].wait_time + 4;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 301;
    }

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_L, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerL4(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_L = 'L';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 4;
        cus[i].wait_time = cus[i].wait_time + 4;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 401;
    }

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_L, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerL5(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_L = 'L';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 4;
        cus[i].wait_time = cus[i].wait_time + 4;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 501;
    }

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_L, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}

void * sellerL6(int *n)
{
    //create queue
    struct customer cus[*n];
    char type_L = 'L';

    //give values to customers queue
    int i;
    for(i = 0; i < *n; i++)
    {
        cus[i].arrive_time = rand() % 60;
        cus[i].wait_time = rand() % 4;
        cus[i].wait_time = cus[i].wait_time + 4;
    }

    //sorting customers by arrive time
    int k;
    struct customer swap;
    for(i = 0; i < *n-1; i++)
    {
        for(k = 0; k < *n - 1 - i; k++)
        {
            if (cus[k].arrive_time > cus[k+1].arrive_time)
            {
                swap = cus[k];
                cus[k] = cus[k+1];
                cus[k+1] = swap;
            }
        }
    }

    //setting customer index
    for(i = 0; i < *n; i++)
    {
        cus[i].index = i + 601;
    }

    //pass each customer to sell() function for processing ordering ticket
    int t = 0;
    for (i = 0; i < *n && t < 60 && run; i++)
    {
        if (cus[i].arrive_time > t)
        {
            t = cus[i].arrive_time;
        }

        int result = sell(t, type_L, cus[i].index, false);

        if (result == -1)
            run = false;    //if theater is full, no more running

        t += cus[i].wait_time;
    }

    return NULL; // thread exits
}


