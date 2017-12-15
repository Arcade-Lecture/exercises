/*
 * ARCADE
 * Sheet_06
 * String Matching in TPC-H LineItem.
 * by Christian Elias
 * */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
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

int main(void) {
    struct nsm_lineitem_table_t nsm_table;
    /* fill with random data */
    for (unsigned i = 0; i < NUM_TUPLES; i++) {
        nsm_table.tuples[i].orderkey = random() % UINT32_MAX;
        nsm_table.tuples[i].partkey = random() % UINT32_MAX;
        nsm_table.tuples[i].suppkey = random() % UINT32_MAX;
        nsm_table.tuples[i].linenumber = random() % INT32_MAX;
        nsm_table.tuples[i].quantity = random() % 1000;
        nsm_table.tuples[i].extendedprice = random() % 10000;
        nsm_table.tuples[i].discount = random() % 50 / 100.0f;
        nsm_table.tuples[i].tax = nsm_table.tuples[i].extendedprice * 0.17f;
        nsm_table.tuples[i].returnflag = 'a' + (random() % 26);
        nsm_table.tuples[i].linestatus = 'a' + (random() % 26);
        nsm_table.tuples[i].shipdate = random() % UINT64_MAX;
        nsm_table.tuples[i].commitdate = random() % UINT64_MAX;
        nsm_table.tuples[i].receipetdate = random() % UINT64_MAX;
        for (int j = 0; j < 25; j++) {
            nsm_table.tuples[i].shipinstr[j] = 'a' + (random() % 26);
        }
        for (int j = 0; j < 10; j++) {
            nsm_table.tuples[i].shipmode[j] = 'a' + (random() % 26);
        }
        for (int j = 0; j < 44; j++) {
            nsm_table.tuples[i].comment[j] = 'a' + (random() % 26);
        }
    }


    char esc[] = ":exit";

    while (1) {
        printf("Type ':exit' to exit.\n");
        printf("Database size:%f Mib.\n", (double) sizeof(nsm_table) / 1024 / 1024);
        printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %%x%% LIMIT n.\n");

        printf("Enter x$ ");
        char x[32];
        scanf("%32[^\n]", x);

        if (strcmp(esc, x) == 0) {
            break;
        } // break the WHILE when :exit is typed
        stdin = freopen(NULL, "r", stdin);

        printf("Enter n (-1 for no limit)$ ");
        char nString[16];
        scanf("%16[^\n]", nString);

        if (strcmp(esc, nString) == 0) {
            break;
        } // break the WHILE when :exit is typed
        stdin = freopen(NULL, "r", stdin);
        int n = atoi(nString);

        n = (n < 0 ? NUM_TUPLES : n); // get all the results when the limit is negative.

        int foundedCounter = 0;

        //for the time measurement
        struct timeval timeval;
        long start, end;
        gettimeofday(&timeval, NULL);
        start = (long) timeval.tv_sec * 1000 + (long) timeval.tv_usec / 1000;

        for (int i = 0; i < NUM_TUPLES; i++) {

            struct nsm_lineitem_tuple_t current = nsm_table.tuples[i]; //to make the code DRY :)

            if (strstr(current.comment, x) != NULL) {
                //output when found
                printf("%i, %i,  %i, %s\n", current.orderkey, current.partkey, current.suppkey, current.comment);
                foundedCounter++;
            }

            if (foundedCounter == n) {
                break;
            } // exit the FOR loop when the limit of results reached
        }

        gettimeofday(&timeval, NULL);
        end = (long) timeval.tv_sec * 1000 + (long) timeval.tv_usec / 1000;

        printf("%i Records in total, %li ms.\n", foundedCounter, end - start);
        printf("---------------------\n\n");
    }
    return 0;
}