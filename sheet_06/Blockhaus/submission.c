#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>

#define NUM_TUPLES 10000

struct nsm_lineitem_tuple_t {
    uint32_t orderkey;
    uint32_t partkey;
    uint32_t suppkey;
    int32_t linenumber;
    float quantity;
    float extendedprice;
    float discount;
    float tax;
    char returnflag;
    char linestatus;
    uint64_t shipdate;
    uint64_t commitdate;
    uint64_t receipetdate;
    char shipinstr[25];
    char shipmode[10];
    char comment[44];
};

struct nsm_lineitem_table_t {
    struct nsm_lineitem_tuple_t tuples[NUM_TUPLES];
};

void fill_table(struct nsm_lineitem_table_t *nsm_table) {

    for (unsigned i = 0; i < NUM_TUPLES; i++) {
        nsm_table->tuples[i].orderkey
            = random() % UINT32_MAX;
        nsm_table->tuples[i].partkey
            = random() % UINT32_MAX;
        nsm_table->tuples[i].suppkey
            = random() % UINT32_MAX;
        nsm_table->tuples[i].linenumber
            = random() % INT32_MAX;
        nsm_table->tuples[i].quantity
            = random() % 1000;
        nsm_table->tuples[i].extendedprice = random() % 10000;
        nsm_table->tuples[i].discount
            = random() % 50 / 100.0f;
        nsm_table->tuples[i].tax
            = nsm_table->tuples[i].extendedprice * 0.17f;
        nsm_table->tuples[i].returnflag
            = 'a' + (random() % 26);
        nsm_table->tuples[i].linestatus
            = 'a' + (random() % 26);
        nsm_table->tuples[i].shipdate
            = random() % UINT64_MAX;
        nsm_table->tuples[i].commitdate
            = random() % UINT64_MAX;
        nsm_table->tuples[i].receipetdate = random() % UINT64_MAX;
        for (int j = 0; j < 25; j++) {
            nsm_table->tuples[i].shipinstr[j] = 'a' + (random() % 26);
        }
        for (int j = 0; j < 10; j++) {
            nsm_table->tuples[i].shipmode[j] = 'a' + (random() % 26);
        }
        for (int j = 0; j < 44; j++) {
            nsm_table->tuples[i].comment[j]
                = 'a' + (random() % 26);
        }
    }
}

long query(struct nsm_lineitem_table_t *table, char *search, long limit)
{
    long i = 0, j = 0;

    if (limit == -1)
        limit = LONG_MAX;

    while (i < limit && j < NUM_TUPLES)
    {
        if(strstr(table->tuples[i].comment,search) != NULL)
        {
            printf("%" PRIu32", %" PRIu32", %" PRIu32 ", %s\n", table->tuples[i].orderkey,table->tuples[i].partkey,table->tuples[i].suppkey,table->tuples[i].comment);
            ++i;
        }
        ++j;
    }

    return i;
}
int main(void)
{
    struct nsm_lineitem_table_t nsm_table;
    char *input = NULL, *x = NULL;
    size_t input_size = 0;
    struct timeval timeval;
    long start, end, n, records;

    /* fill with random data */
    fill_table(&nsm_table);

    //print out hello and infos
    printf("Type \":exit\" to exit the program.\n");
    printf("Size of table LINEITEM: %f MiB\n",sizeof(struct nsm_lineitem_table_t) / (double) 0x100000);

    //mainloop
    for (;;)
    {
        printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %%x%% LIMIT n.\n");
        printf("Enter value for x: ");
        input_size = getline(&input,&input_size,stdin);

        if (strstr(input,":exit") != NULL)
            break;
        if (strlen(input) == 0 || input[0] == '\n')
            continue;

        //somehow dirty because of possibly alot allocs and memory movement
        if (input[strlen(input)-1] == '\n')
        {
            x = realloc(x, strlen(input));
            strncpy(x,input,strlen(input)-1);
        }
        else
        {
            x = realloc(x, strlen(input)+1);
            strcpy(x,input);
        }


        printf("Enter n (-1 for no limit): ");
        input_size = getline(&input,&input_size,stdin);

        if (strstr(input,":exit") != NULL)
            break;
        if (strlen(input) == 0 || input[0] == '\n')
            continue;

        //todo: error handling
        n = strtol(input,NULL,10);

        gettimeofday(&timeval, NULL);
        start = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

        records = query(&nsm_table,x,n);

        gettimeofday(&timeval, NULL);
        end = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;
        printf("%ld records in %ld ms\n",records,end - start);

    }
    //cleanup
    free(input);
    free(x);

    return EXIT_SUCCESS;
}