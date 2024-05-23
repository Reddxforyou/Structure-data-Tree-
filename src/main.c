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
    point_birth_available(Root(test)->node_fs, "    |Anak22", 3, 'L');
    point_birth_available(Root(test)->node_fs->node_nb, "   |Anak3", 3, 'L');
    point_birth_available(Root(test)->node_fs->node_nb->node_fs, "      |Anak4", 3, 'L');
    point_birth_available(Root(test)->node_fs->node_nb->node_fs->node_fs, "        |Anak5", 3, 'L');
    point_kill(Root(test)->node_fs);
    print_datainfo(Root(test)->node_fs->info);
    trav_pre_order(Root(test));
    int Depth = depth(Root(test)->node_fs);
    printf("Kedalaman tree adalah: %d\n", Depth);
    int live = countLivingFamilyMembers(Root(test)->node_fs);
    printf("hidup: %d\n", live);
    infotype nodeName = "ANAK1";
    int generations = countGenerations(Root(test), nodeName);
    printf("Generations: %d\n", generations);
    printf(search(Root(test), nodeName));
    return 0;
}
