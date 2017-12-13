#define NUM_TUPLES 10000
#define __STDC_LIMIT_MACROS
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "sys/time.h"

//0391 2439944

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

	char* disrupt = ":exit";

	while(1){
	
	//Starting foo
	printf("You can terminate the program by entering :exit\n");
	printf("Size of table in MiB: %g \n", (double)sizeof(nsm_table) /1024.0 /1024.0);
	printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %%x%% LIMIT n.\n");

	//input foo
	printf("Enter x:");
	char line[64];
	scanf("%63[^\n]", line);
	//Exit foo
	if(strstr(disrupt,line))
		break;
	stdin = freopen(NULL,"r",stdin);
	printf("Enter n:");
	char line2[16];
	scanf("%63[^\n]", line2);
	if(strstr(disrupt,line2))
		break;
	int n = atoi(line2);
	if(n > 0){ }
	else{
		n = -1;
	}
	stdin = freopen(NULL,"r",stdin);

	int counter = 0;
	int pos = 0;

	//Time foo 
	struct timeval timeval;
	long start, end;
	gettimeofday(&timeval, NULL);
	start = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

	while(1){
		if(strstr(nsm_table.tuples[pos].comment,line)){
			printf("%i %i %i %s \n",nsm_table.tuples[pos].orderkey, nsm_table.tuples[pos].partkey, nsm_table.tuples[pos].suppkey, nsm_table.tuples[pos].comment);
			++counter;
		}
		++pos;
		if(counter == n || pos == NUM_TUPLES){
			break;
		}
	}

	gettimeofday(&timeval, NULL);
end = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

	printf("%i records in total, %d ms\n", counter, end-start);
	printf("############################################\n");
	}
/* TODO: add code here */
return 0;
}