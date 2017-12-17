#include <stdio.h>
#include <lineitem_tbl.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>


int main() {
    nsm_lineitem_table_t table;
    fill_table(&table);

    do {
        printf("Type \':exit\' to exit.\n");
        printf("Database size: %f MiB\n",get_size_mib());
        printf("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %%x%% LIMIT n.\n");
        char x[44];
        printf ("Enter x:$ ");
        scanf ("%s",x);
        if (! strcmp(x,":exit"))
            break;
        int n;
        printf ("\nEnter n:$ ");
        scanf("%d",&n);
        int num_iterations = NUM_TUPLES;
        unsigned i = 0;
        if (n == -1) {

        }else if (n < 0){
                i = (n * -1) - 1;
        } else{
            num_iterations = n;
        }
        int found_records = 0;

        struct timeval timeval; long start, end;
        gettimeofday(&timeval, NULL);
        start = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;

        for (; i < num_iterations; i++) {
                if (strstr(table.tuples[i].comment, x)) {
                    ++found_records;
                    printf("%ud %ud %ud %s\n",table.tuples[i].orderkey, table.tuples[i].partkey, table.tuples[i].suppkey, table.tuples[i].comment);
                }
        }
        gettimeofday(&timeval, NULL);
        end = (long)timeval.tv_sec * 1000 + (long)timeval.tv_usec / 1000;
        printf("%d records in total, %ld ms\n",found_records, end-start);
    } while(true);

    return 0;
}


