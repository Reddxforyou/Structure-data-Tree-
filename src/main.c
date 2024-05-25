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
    
    // memberikan suatu node anak
    point_birth_available(Root(test), "Anak2", 10, 'L');
    point_birth_available(Root(test), "Anak15", 5, 'P');
    point_birth_available(Root(test), "Anak1", 5, 'P');
    point_birth_available(Root(test)->node_fs, "Anak25", 3, 'L');
    point_birth_available(Root(test)->node_fs, "Anak22", 3, 'L');
    point_birth_available(Root(test)->node_fs->node_nb, "Anak3", 3, 'L');
    point_birth_available(Root(test)->node_fs->node_nb->node_fs, "Anak4", 3, 'L');
    point_birth_available(Root(test)->node_fs->node_nb->node_fs->node_fs, "Anak5", 3, 'L');

    // print tree secara preorder
    printf("\n");
    trav_pre_order(Root(test));

    //mencari anak5
    printf("\n");
    search(Root(test), "ANAK5");

    //ubah status hidup menjadi false
    point_kill(Root(test)->node_fs->node_nb->node_fs); //anak3
    point_kill(Root(test)->node_fs->node_nb->node_fs->node_fs);//anak 4
    
    //melihat siapa penerus selanjutnya
    printf("\n");
    successorPrediction(Root(test), "ANAK5");
    
    //menghapus anak 1 dan keturunannya
    printf("\n");
    deleteNodewithDescendants(Root(test), "ANAK2");
    printf("\n");
    // deAlokasi(Root(test));
    printTree(Root(test), 0);

    // printtraversal
    printf("preorder");
    trav_pre_order(Root(test));
    return 0;
}
