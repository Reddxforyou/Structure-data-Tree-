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

    Root(test) = alok_available_pers("Root", 50, 'L');
    point_marriage_unknown(Root(test));
    point_birth_available(Root(test), "Anak1", 10, 'L');
    point_birth_available(Root(test), "Anak2", 5, 'P');
    point_birth_available(Root(test)->node_fs, "Anak1fs", 3, 'L');
    point_birth_available(Root(test)->node_fs, "Anak1.2", 2, 'L');
    point_birth_available(Root(test)->node_fs->node_fs, "Anak1.2.1", 10, 'L');
    point_birth_available(Root(test)->node_fs->node_fs, "Anak1.2.2", 9, 'L');
    printTree(Root(test), 0);
    save_Tree_To_File("familyTree.txt", &test);
    // readFamilyData("familyTree.txt", &test);
    // loadFamilyTreeFromFile("familyTree.txt", &test);
    // char temp_name[MAX_NAME_LENGTH] = "anak1.2.2";
    // address temp = search_handler(Root(test), temp_name);

    return 0;
}
