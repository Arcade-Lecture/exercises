#include <lineitem_tbl.h>
#include <stdlib.h>

/* fill with random data */

void fill_table(nsm_lineitem_table_t *nsm_table) {
    for (unsigned i = 0; i < NUM_TUPLES; i++) {
        nsm_table->tuples[i].orderkey = random() % UINT32_MAX;
        nsm_table->tuples[i].partkey = random() % UINT32_MAX;
        nsm_table->tuples[i].suppkey   = random() % UINT32_MAX;
        nsm_table->tuples[i].linenumber = random() % INT32_MAX;
        nsm_table->tuples[i].quantity = random() % 1000;
        nsm_table->tuples[i].extendedprice = random() % 10000;
        nsm_table->tuples[i].discount = random() % 50 / 100.0f;
        nsm_table->tuples[i].tax = nsm_table->tuples[i].extendedprice * 0.17f;
        nsm_table->tuples[i].returnflag = 'a' + (random() % 26);
        nsm_table->tuples[i].linestatus = 'a' + (random() % 26);
        nsm_table->tuples[i].shipdate = random() % UINT64_MAX;
        nsm_table->tuples[i].commitdate = random() % UINT64_MAX;
        nsm_table->tuples[i].receipetdate = random() % UINT64_MAX;

        for (int j = 0; j < 25; j++) {
            nsm_table->tuples[i].shipinstr[j] = 'a' + (random() % 26);
        }

        for (int j = 0; j < 10; j++) {
            nsm_table->tuples[i].shipmode[j] = 'a' + (random() % 26);
        }

        for (int j = 0; j < 44; j++) {
            nsm_table->tuples[i].comment[j] = 'a' + (random() % 26);
        }
    }
}

float get_size_mib()
{
    size_t size_tuple = (sizeof(int32_t) * 4) + (sizeof(float) * 4);
    size_tuple += (sizeof(char) * 2);
    size_tuple += (sizeof(uint64_t) * 3);
    size_tuple += sizeof(char) * (25 + 10 + 44);

    return ( (size_tuple * NUM_TUPLES)  /(1024 * 1.0));
}