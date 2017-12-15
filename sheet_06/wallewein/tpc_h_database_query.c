#define NUM_TUPLES 10000
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "sys/time.h"
#include "stdlib.h"

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

// To shorten main function, exclude the query execution
void executeQuery(struct nsm_lineitem_table_t * nsm_table, const char* searchKey, int searchLimit);

int main(void)
{
    struct nsm_lineitem_table_t nsm_table;
    /* fill with random data */
    for (unsigned i = 0; i < NUM_TUPLES; i++) {
    	nsm_table.tuples[i].orderkey = random() % UINT32_MAX;
    	nsm_table.tuples[i].partkey = random() % UINT32_MAX;
    	nsm_table.tuples[i].suppkey = random() % UINT32_MAX;
    	nsm_table.tuples[i].linenumber = random() % UINT32_MAX;
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
    		nsm_table.tuples[i].comment[j]
    		= 'a' + (random() % 26);
    	}
    }

    /* TODO: add code here */
    /* Example output
    Type ':exit' to exit.
    Database size: 6.866455 MiB
    SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %x% LIMIT n. Enter x$ hugo
    Enter n (-1 for no limit)$ 2
    2008078427d, 183650190d, 1353939664d, glnvhzfylutbhugoszuhrqzkrakdqpcxdqskrzketdhd 1169030037d, 1333710445d, 250609978d, jviyhugodxdvywwuhfvsgvwnygaavbjgxtfennutnzon
    3 records in total, 18 ms
    */

    // To compare with user input
    const char* exitKey = ":exit";

    size_t maxCharInput = 100;
    size_t currentInputLength;
    char* userInput;

    char searchKey[105];
    int searchLimit;

    // First output out of the loop
    double databaseSize = (double)sizeof(nsm_table) / 1024 / 1024; // display in MiB
    printf("%s", "Type ':exit' to exit.\n");
    printf("Database size: %f MiB\n", databaseSize);
    printf("%s", "SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %x% LIMIT n.\n");
    
    while(5)
    {
        // 5.a Ask for x
        printf("%s", "Enter x$ \n");

        // Read user input and check exit
        getline(&userInput, &currentInputLength, stdin);
        if(!strncmp(exitKey, userInput, strlen(exitKey)))
            return 0;
        
        // Copy to searchKey for later use, make sure to remove \n
        userInput[strcspn(userInput, "\n")] = '\0';
        strlcpy(searchKey, userInput, maxCharInput);

        // 5.b Ask for n, make sure to have correct input
        do
        {
            printf("%s", "Enter n (-1 for no limit)$ \n");
            
            // Read user input and check exit
            getline(&userInput, &currentInputLength, stdin);
            if(!strncmp(exitKey, userInput, strlen(exitKey)))
                return 0;
            
        }
        while(sscanf(userInput, "%d", &searchLimit) == 0);

        // Execute Query
        executeQuery(&nsm_table, searchKey, searchLimit);
    }
    
    return 0;
 }
 
 /*
 5 c. Your program answers the query with given x and n, and prints the result to standard output. 
 (Formatted string output is further explained in Appendix 3)
 5.d. After the result is printed, your program prints the number m of all tuples that are contained 
 in the result set (since n might be less than m), and outputs the query response time in ms. 
 One way to measure time distances in C is given in Appendix 2.
 */
 void executeQuery(struct nsm_lineitem_table_t * nsm_table, const char* searchKey, int searchLimit)
 {
    //size_t searchKeySize = sizeof(*searchKey);
    const char* resultOutputFormatString = "%d, %d, %d, %s\n";
    int resultCount = 0;

    // Measure time in the method to exclude stack operations for the method.
    struct timeval timeval; long start, end;
    gettimeofday(&timeval, NULL);
    start = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

    int i;
    for(i = 0; i < sizeof(nsm_table->tuples) / sizeof(struct nsm_lineitem_tuple_t); ++i)
    {
        // Search string in tuple
        if(strstr(nsm_table->tuples[i].comment, searchKey) != NULL)
        {
            if(searchLimit < 0 || resultCount < searchLimit)
            {
                printf(resultOutputFormatString, 
                    nsm_table->tuples[i].orderkey, 
                    nsm_table->tuples[i].partkey, 
                    nsm_table->tuples[i].suppkey, 
                    nsm_table->tuples[i].comment);
            }
            ++resultCount;
        }
    }

    gettimeofday(&timeval, NULL);
    end = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

    printf("%d records in total, %lu ms\n", resultCount, end - start);
 }
