#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

struct seat
{
    int row;
    int column;
    bool reserved;  //true if seat is sold
    char type;      //record which type of seller sell it
    int index;      //record the order of the customer in the queue so that we can print e.g. H101
};

//sell function, receive t = customer arrive time, type = seller type, index for the order in the queue
//print is true for printing result only, false then skip printing
int sell(int t, char type, int index, bool print)
{
    int i, j;
    static bool initialized;    // use this to run the if statement below only once
    static int full = false;
    static int count_H = 0;     //reason for using static is to keep values unchanged
    static int count_M = 0;
    static int count_L = 0;

    //create seats
    static struct seat seats[10][10];

    //run only once because the static initialized
    if (!initialized)
    {
        initialized = true;
        for (i = 0; i < 10; i++)
        {
            for(j = 0; j < 10; j++)
            {
                seats[i][j].row = i;
                seats[i][j].column = j;
                seats[i][j].reserved = false;
            }
        }
    }

    //type H execution
    if (type == 'H')
    {
        bool test = true; //use it to test if the searing goes to the end, if find a seat, test = false, searching end
        for(i = 0; i < 10 && test ; i++)
        {
            for(j = 0; j < 10 && test ; j++)
            {
                if (!seats[i][j].reserved)                  //find empty seat
                {
                    test = false;
                    seats[i][j].reserved = true;
                    seats[i][j].type = type;
                    seats[i][j].index = index;
                    count_H++;

                    if(t < 10)
                    {
                        printf("00:0%d  Seller H1 sells seat at row %d column %d\n", t, i, j);
                    }
                    else
                    {
                        printf("00:%d  Seller H1 sells seat at row %d column %d\n", t, i, j);
                    }
                }
            }
        }
        if (test == true)   //test = true when cannot find empty seat
        {
            full = true;
            return -1;
        }
    }

    //type L execution
    if (type == 'L')
    {
        bool test = true;   //use it to test if the searing goes to the end, if find a seat, test = false, searching end
        for(i = 9; i >= 0 && test ; i--)
        {
            for(j = 0; j < 10 && test ; j++)
            {
                if (!seats[i][j].reserved)                  //find empty seat
                {
                    test = false;
                    seats[i][j].reserved = true;
                    seats[i][j].type = type;
                    seats[i][j].index = index;
                    count_L++;

                    if(t < 10)
                    {
                        if (index < 200)
                            printf("00:0%d  Seller L1 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 300)
                            printf("00:0%d  Seller L2 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 400)
                            printf("00:0%d  Seller L3 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 500)
                            printf("00:0%d  Seller L4 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 600)
                            printf("00:0%d  Seller L5 sells seat at row %d column %d\n", t, i, j);
                        else
                            printf("00:0%d  Seller L6 sells seat at row %d column %d\n", t, i, j);
                    }
                    else
                    {
                        if (index < 200)
                            printf("00:%d  Seller L1 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 300)
                            printf("00:%d  Seller L2 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 400)
                            printf("00:%d  Seller L3 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 500)
                            printf("00:%d  Seller L4 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 600)
                            printf("00:%d  Seller L5 sells seat at row %d column %d\n", t, i, j);
                        else
                            printf("00:%d  Seller L6 sells seat at row %d column %d\n", t, i, j);
                    }
                }
            }
        }
        if (test == true)   //test = true when cannot find empty seat
        {
            full = true;
            return -1;
        }
    }

    //type M execution
    if (type == 'M')
    {
        bool test = true;   //use it to test if the searing goes to the end, if find a seat, test = false, searching end
        int ary[10] = {5, 6, 4, 7, 3, 8, 2, 9, 1, 10}; //use to follow the order of row from 5, 6, 4, 7 and so on
        int a;
        for(a = 0; a < 10 && test ; a++)
        {
            i = ary[a] - 1;
            for(j = 0; j < 10 && test ; j++)
            {
                if (!seats[i][j].reserved)                  //find empty seat
                {
                    test = false;
                    seats[i][j].reserved = true;
                    seats[i][j].type = type;
                    seats[i][j].index = index;
                    count_M++;

                    if(t < 10)
                    {
                        if (index < 200)
                            printf("00:0%d  Seller M1 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 300)
                            printf("00:0%d  Seller M2 sells seat at row %d column %d\n", t, i, j);
                        else
                            printf("00:0%d  Seller M3 sells seat at row %d column %d\n", t, i, j);
                    }
                    else
                    {
                        if (index < 200)
                            printf("00:%d  Seller M1 sells seat at row %d column %d\n", t, i, j);
                        else if (index < 300)
                            printf("00:%d  Seller M2 sells seat at row %d column %d\n", t, i, j);
                        else
                            printf("00:%d  Seller M3 sells seat at row %d column %d\n", t, i, j);
                    }
                }
            }
        }
        if (test == true)   //test = true when cannot find empty seat
        {
            full = true;
            return -1;
        }
    }

    //printing the result when calling with parameter print = true
    if (print)
    {
        printf("\n\n");
        for (i = 0; i < 10; i++)
        {
            for(j = 0; j < 10; j++)
            {
                if (seats[i][j].reserved == false)
                    printf("----- ");
                else
                {
                    if (seats[i][j].index < 10)
                        printf(" %c00%d ", seats[i][j].type, seats[i][j].index);
                    else if(seats[i][j].index < 100)
                        printf(" %c0%d ", seats[i][j].type, seats[i][j].index);
                    else
                        printf(" %c%d ", seats[i][j].type, seats[i][j].index);
                }
            }
            printf("\n");
        }

        //take care of 100 customer taking 100 seats,
        //in this case, full still false, check to set it true
        if(!full)
        {
            full = true;
            for(i = 0; i < 10; i++)
            {
                for(j = 0; j < 10; j++)
                {
                    if (!seats[i][j].reserved)
                    {
                        full = false;   //if there is empty seat, full is false
                    }
                }
            }
        }

        if(full)
            printf("\nThe theater is full\n");
        else
            printf("\nThe theater is not full\n");

        printf("number of H customers got seats: %d\n", count_H);
        printf("number of M customers got seats: %d\n", count_M);
        printf("number of L customers got seats: %d\n", count_L);
        int run_away;
        run_away = index*10 - 100;
        if (run_away > 0)
            printf("number of customers were turned away: %d\n", run_away);
        else
            printf("number of customers were turned away: 0\n", run_away);
    }


    return 0;
}
