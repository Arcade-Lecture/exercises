#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <math.h>

#define NUM_TUPLES 10000
struct nsm_lineitem_tuple_t
{
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
struct nsm_lineitem_table_t
{
  struct nsm_lineitem_tuple_t tuples[NUM_TUPLES];
};
int
main (void)
{

  struct timeval timeval;
  long start, end;
  float dbSize;
  char pattern[50];
  unsigned int row_count_limit;
  int pattern_matched_count = 0;
  struct nsm_lineitem_table_t nsm_table;
  /* fill with random data */
  for (unsigned i = 0; i < NUM_TUPLES; i++)
    {
      nsm_table.tuples[i].orderkey = random () % UINT32_MAX;
      nsm_table.tuples[i].partkey = random () % UINT32_MAX;
      nsm_table.tuples[i].suppkey = random () % UINT32_MAX;
      nsm_table.tuples[i].linenumber = random () % INT32_MAX;
      nsm_table.tuples[i].quantity = random () % 1000;
      nsm_table.tuples[i].extendedprice = random () % 10000;
      nsm_table.tuples[i].discount = random () % 50 / 100.0f;
      nsm_table.tuples[i].tax = nsm_table.tuples[i].extendedprice * 0.17f;
      nsm_table.tuples[i].returnflag = 'a' + (random () % 26);
      nsm_table.tuples[i].linestatus = 'a' + (random () % 26);
      nsm_table.tuples[i].shipdate = random () % UINT64_MAX;
      nsm_table.tuples[i].commitdate = random () % UINT64_MAX;
      nsm_table.tuples[i].receipetdate = random () % UINT64_MAX;
      for (int j = 0; j < 25; j++)
	{
	  nsm_table.tuples[i].shipinstr[j] = 'a' + (random () % 26);
	}
      for (int j = 0; j < 10; j++)
	{
	  nsm_table.tuples[i].shipmode[j] = 'a' + (random () % 26);
	}
      for (int j = 0; j < 44; j++)
	{
	  nsm_table.tuples[i].comment[j] = 'a' + (random () % 26);
	}
    }
  printf ("Type ':exit' to exit\n");

  dbSize = (((float) sizeof (nsm_table) / 1024) / 1024);

  printf ("Database Size: %f MiB\n", dbSize);

  printf
    ("SELECT orderkey, partkey, suppkey, comment FROM lineitem WHERE comment LIKE %%x\%%  LIMIT n\n");

  while (1)
    {
      pattern_matched_count = 0;
      printf ("Enter x$ ");

      scanf ("%s", pattern);

      if (strcmp (pattern, ":exit") == 0)
	return 0;

      printf ("Enter n (-1 for no limit)$ ");

      scanf ("%d", &row_count_limit);

      gettimeofday (&timeval, NULL);
      start = (long) timeval.tv_sec * 1000 + (long) timeval.tv_usec / 1000;

      /*code for pattern matching */
      for (int i = 0; i < NUM_TUPLES; i++)
	{

	  if (strstr (nsm_table.tuples[i].comment, pattern) != NULL)
	    {
	      ++pattern_matched_count;
	      if (row_count_limit < 0
		  || pattern_matched_count <= row_count_limit)
		{
		  printf ("%d, %d, %d, %s\n", nsm_table.tuples[i].orderkey,
			  nsm_table.tuples[i].partkey,
			  nsm_table.tuples[i].suppkey,
			  nsm_table.tuples[i].comment);
		}
	    }

	}


      gettimeofday (&timeval, NULL);
      end = (long) timeval.tv_sec * 1000 + (long) timeval.tv_usec / 1000;

      printf ("%d records in total, %d ms \n", pattern_matched_count,
	      (end - start));

    }

  return 0;
}
