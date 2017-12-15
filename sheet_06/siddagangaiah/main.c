#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>

#define NUM_TUPLES 10000
#define EXIT_STR ":exit"

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

long get_current_time(void) {
    struct timeval timeval;
    gettimeofday(&timeval, NULL);
    return (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;
}

int main(void)
{
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

    while (1){

        char search_string[44];

        printf("Type ':exit' to exit.\n");

        float size_in_MBs = (sizeof(struct nsm_lineitem_table_t) * (CHAR_BIT / 8.0)) /1024.0 / 1024.0;
        printf("Database size: %f MiB\n", size_in_MBs);

        printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %%x%% LIMIT n.\n");

        printf("Enter x$ ");
        scanf("%s",search_string);
        if(strcmp(EXIT_STR, search_string) == 0){
            exit(0);
        }

        int count = 0;
        int req_num_of_res = -1;

        printf("Enter n (-1 for no limit)$ ");
        scanf("%d", &req_num_of_res);

        long start = get_current_time();

        for (int i = 0; i < NUM_TUPLES; ++i) {

            if(strstr(nsm_table.tuples[i].comment, search_string) != NULL){

                count++;

                if(req_num_of_res < 0 || count <= req_num_of_res)

                    printf("%d, %d, %d, %s\n",
                           nsm_table.tuples[i].orderkey,
                           nsm_table.tuples[i].partkey,
                           nsm_table.tuples[i].suppkey,
                           nsm_table.tuples[i].comment);
            }
        }

        long end = get_current_time();
        printf("%d records in total, %lu ms\n\n", count, end - start);
    }
}
