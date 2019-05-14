
#include "jumphash.h"

/*

int32_t JumpConsistentHash(uint64_t key, int32_t num_buckets) {
    int64_t b = -1, j = 0;
    while (j < num_buckets) {
        b = j;
        key = key * 2862933555777941757ULL + 1;
        j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));
    }
    return b;
}
*/

int jump_hash(uint64_t key, int buckets)
{
    int64_t b = -1;
    int64_t j = 0;

    while (j < ((int64_t) buckets))
    {
        b = j;
        key = key * 2862933555777941757ULL + 1;
        j = (int64_t) (((double) (b + 1)) * (((double)(1LL << 31)) / ((double)((key >> 33)+1))));
    }
    return (int) b;
}

int main(int argc, char *argv[])
{
    int hash = Hash(10863919174838991, 11);
    printf("hash: %d\n", hash);
}
