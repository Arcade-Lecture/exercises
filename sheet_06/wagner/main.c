#define NUM_TUPLES 10000

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>  


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

    printf("Database Size in MiB: %f\n", sizeof(nsm_table) / 1024.0f / 1024.0f);
    printf("Program will terminate, if you input :exit.\n");

    printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE '%%x%%' LIMIT n;\n");


    char inputChars[20];
    char inputNumbers[20];

    // fgets read the entire stdin INCLUDING the new line. Tricky.
    char exitCode[20] = ":exit";

    while(strcmp(inputChars, exitCode) != 0) {

    	printf("Input Needle x: \n");
    	fgets(inputChars, sizeof(inputChars), stdin);
    	// Removing new line.
    	strcpy(inputChars,strtok(inputChars, "\n"));


    	printf("Input Limit n (Unlimited: -1): \n");
    	fgets(inputNumbers, sizeof(inputNumbers), stdin);
    	// Removing new line.
    	strcpy(inputNumbers,strtok(inputNumbers, "\n"));

    	int n = atoi(inputNumbers);
    	int foundResults = 0;

		printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE '%s' LIMIT %i;\n", inputChars, n);

    	struct timeval timeval;
		long start, end;
		gettimeofday(&timeval, NULL);
		start = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

    	for(int i = 0; (n < 0 || foundResults < n) && i < NUM_TUPLES; i++) {
    		struct nsm_lineitem_tuple_t currentTuple = nsm_table.tuples[i];

    		printf("%s\n", currentTuple.comment);

    		if(strstr(currentTuple.comment, inputChars) != NULL) {
    			// Match

    			printf("orderKey: %i, partKey: %i, suppKey: %i, comment: %s\n",currentTuple.orderkey, currentTuple.partkey, currentTuple.suppkey, currentTuple.comment);
    			foundResults++;
    		}

    	}

    	gettimeofday(&timeval, NULL);
		end = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

    	printf("%i Records in total. Needed %li ms.\n", foundResults, end - start );

    }


    return 0;
}