//
// Created by Mahmoud Mohsen on 16.12.17.
//
#include <inttypes.h>
#include <stdlib.h>

#pragma once

#define NUM_TUPLES 10000

typedef struct nsm_lineitem_tuple_t { uint32_t orderkey; uint32_t partkey; uint32_t suppkey;
    int32_t linenumber; float quantity; float extendedprice; float discount; float tax;
    char returnflag;
    char linestatus; uint64_t shipdate; uint64_t commitdate; uint64_t receipetdate; char shipinstr[25]; char shipmode[10]; char comment[44];
}nsm_lineitem_tuple_t;

typedef struct nsm_lineitem_table_t {
    struct nsm_lineitem_tuple_t tuples[NUM_TUPLES];
}nsm_lineitem_table_t;

void fill_table(nsm_lineitem_table_t *nsm_table);
float get_size_mib();