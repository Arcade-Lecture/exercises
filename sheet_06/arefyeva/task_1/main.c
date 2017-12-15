#define NUM_TUPLES 1000

#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h> 

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

int main(void)
{
	struct nsm_lineitem_table_t nsm_table;
	/* fill with random data */
	for (unsigned i = 0; i < NUM_TUPLES; i++) {
		nsm_table.tuples[i].orderkey = rand() % UINT32_MAX;
		nsm_table.tuples[i].partkey = rand() % UINT32_MAX;
		nsm_table.tuples[i].suppkey = rand() % UINT32_MAX;
		nsm_table.tuples[i].linenumber = rand() % INT32_MAX;
		nsm_table.tuples[i].quantity = rand() % 1000;
		nsm_table.tuples[i].extendedprice = rand() % 10000;
		nsm_table.tuples[i].discount = rand() % 50 / 100.0f;
		nsm_table.tuples[i].tax = nsm_table.tuples[i].extendedprice * 0.17f;
		nsm_table.tuples[i].returnflag = 'a' + (rand() % 26);
		nsm_table.tuples[i].linestatus = 'a' + (rand() % 26);
		nsm_table.tuples[i].shipdate = rand() % UINT64_MAX;
		nsm_table.tuples[i].commitdate = rand() % UINT64_MAX;
		nsm_table.tuples[i].receipetdate = rand() % UINT64_MAX;
		for (int j = 0; j < 25; j++) {
			nsm_table.tuples[i].shipinstr[j] = 'a' + (rand() % 26);
		}
		for (int j = 0; j < 10; j++) {
			nsm_table.tuples[i].shipmode[j] = 'a' + (rand() % 26);
		}
		for (int j = 0; j < 44; j++) {
			nsm_table.tuples[i].comment[j] = 'a' + (rand() % 26);
		}
	}
	/* TODO: add code here */

	printf("Type \":exit\" to exit.\n");

	float table_size = sizeof(nsm_table) / 1024;
	table_size /= 1024;

	printf("Database size: %f MiB\n", table_size);

	printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %%x%% LIMIT n.\n");

	while (1) {
		char input[50];
		printf("Enter x: ");
		scanf_s("%s", input, 50);
		if (strcmp(input, ":exit") == 0) break;
		//int x = atoi(input);
		//sscanf(input, "%d", &x);
		char x[50];
		memcpy(x, input, 50);
		printf("Enter n (-1 for no limit): ");
		scanf_s("%s", input, 50);
		if (strcmp(input, ":exit") == 0) break;
		int n = atoi(input);
		struct timeb start, end;
		int diff;
		int j = 0;
		int total = 0;
		ftime(&start);
		for (unsigned i = 0; i < NUM_TUPLES; i++) {
			if (strstr(nsm_table.tuples[i].comment, x) != NULL) {
				total++;
				if ((n < 0) || (j < n)) {
					j++;
					printf("%d, %d, %d, %s\n", nsm_table.tuples[i].orderkey, nsm_table.tuples[i].partkey, nsm_table.tuples[i].suppkey, nsm_table.tuples[i].comment);
				}
			}
		}
		ftime(&end);
		diff = (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
		printf("%d records in total, %d ms\n", total, diff);
	}

	printf("Terminating the program");
	//int a;
	//scanf_s("%d", &a);

	return 0;
}