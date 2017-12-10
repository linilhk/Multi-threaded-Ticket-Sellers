
#include <stdio.h>
#include <pthread.h>
#include "seller.c"

int main()
{
    int n;
    pthread_t tids[10];

    //ask for size of customer
    printf("Enter a number of customer: ");
    scanf("%d", &n);

    //create 10 threads
    pthread_create(&tids[0], NULL, sellerH1, &n);
    pthread_create(&tids[1], NULL, sellerM1, &n);
    pthread_create(&tids[2], NULL, sellerM2, &n);
    pthread_create(&tids[3], NULL, sellerM3, &n);
    pthread_create(&tids[4], NULL, sellerL1, &n);
    pthread_create(&tids[5], NULL, sellerL2, &n);
    pthread_create(&tids[6], NULL, sellerL3, &n);
    pthread_create(&tids[7], NULL, sellerL4, &n);
    pthread_create(&tids[8], NULL, sellerL5, &n);
    pthread_create(&tids[9], NULL, sellerL6, &n);

    //wait for all threads to finish
    int i;
    for (i = 0; i < 10 ; i++)
        pthread_join(tids[i], NULL);

    //print result
    int result;
    result = sell(60, 'E', n, true);




    exit(0);
}
