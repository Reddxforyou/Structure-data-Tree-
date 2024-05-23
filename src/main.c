#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bodyRoyalTree.c"
#include <ctype.h>
#include "BOOLEAN.H"

int main()
{
    // masih testing module
    telm_root test;
    init_Root(&test);
    Root(test) = alok_unknown_pers();
    point_birth_available(Root(test), "Anak2", 10, 'L');
    point_birth_available(Root(test), "Anak1", 5, 'P');
    point_birth_available(Root(test)->node_fs, "Anak22", 3, 'L');
    print_datainfo(Root(test)->node_fs->info);
    return 0;
}
