#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bodyRoyalTree.c"
#include <ctype.h>
#include "BOOLEAN.H"




// // Fungsi untuk membaca isi file
// void readFile(Node* root) {
//     char filename[100];
//     printf("Masukkan nama file: ");
//     fgets(filename, sizeof(filename), stdin);
//     // Menghapus newline character yang tersisa
//     filename[strcspn(filename, "\n")] = 0;

//     // Debug: Print nama file yang dimasukkan
//     printf("Membuka file: %s\n", filename);

//     FILE* file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Tidak bisa membuka file %s\n", filename);
//         return;
//     }

//     char line[256];
//     while (fgets(line, sizeof(line), file)) {
//         // Menghapus newline character yang tersisa
//         line[strcspn(line, "\n")] = 0;

//         // Debug: Print setiap baris yang dibaca
//         printf("Membaca baris: %s\n", line);

//         // Cek apakah ini teks biasa atau sandi Morse
//         if (strchr(line, '.') != NULL || strchr(line, '-') != NULL) {
//             // Ini adalah sandi Morse
//             printf("Teks asli dari sandi Morse: ");
//             morseTextToChar(root, line);
//         } else {
//             // Ini adalah teks biasa
//             printf("Sandi Morse dari teks: ");
//             textToMorse(root, line);
//         }
//         printf("\n");
//     }

//     fclose(file);

//     printf("Tekan enter untuk kembali ke menu utama...");
//     getchar(); // Menunggu sampai pengguna menekan tombol enter
// }


// address findNodeByName(address root, const char *name) {
//     if (root == NULL) {
//         return NULL;
//     }
//     if (strcmp(root->info.nama, name) == 0) {
//         return root;
//     }
//     address foundNode = findNodeByName(root->node_mate, name);
//     if (foundNode) {
//         return foundNode;
//     }
//     foundNode = findNodeByName(root->node_fs, name);
//     if (foundNode) {
//         return foundNode;
//     }
//     return findNodeByName(root->node_nb, name);
// }

// address deserializeNode(FILE *file, telm_root *familyTree, char *line) {
//     address newNode = NULL;
//     char name[MAX_NAME_LENGTH], mate[MAX_NAME_LENGTH], first_sibling[MAX_NAME_LENGTH], next_sibling[MAX_NAME_LENGTH], parent[MAX_NAME_LENGTH];
//     int age;
//     char gender;
//     char alive[MAX_LINE_LENGTH];

//     while (fgets(line, MAX_LINE_LENGTH, file)) {
//         if (strcmp(line, "# Root\n") == 0 || strcmp(line, "# Person\n") == 0) {
//             if (newNode != NULL) {
//                 if (familyTree->root == NULL) {
//                     familyTree->root = newNode;
//                 }
//                 break;
//             }
//             newNode = (address)malloc(sizeof(telm_familly));
//             newNode->node_mate = NULL;
//             newNode->node_fs = NULL;
//             newNode->node_nb = NULL;
//             newNode->node_parrent = NULL;
//         } else if (sscanf(line, "name: %s", name) == 1) {
//             strcpy(newNode->info.nama, name);
//         } else if (sscanf(line, "age: %d", &age) == 1) {
//             newNode->info.age = age;
//         } else if (sscanf(line, "gender: %c", &gender) == 1) {
//             newNode->info.gender = gender;
//         } else if (sscanf(line, "alive: %s", alive) == 1) {
//             newNode->info.alive = (strcmp(alive, "true") == 0);
//         } else if (sscanf(line, "mate: %s", mate) == 1) {
//             if (strcmp(mate, "null") != 0) {
//                 address mateNode = findNodeByName(familyTree->root, mate);
//                 if (mateNode == NULL) {
//                     mateNode = alok_available_pers(mate, 0, ' ');
//                 }
//                 newNode->node_mate = mateNode;
//             }
//         } else if (sscanf(line, "first_son: %s", first_sibling) == 1) {
//             if (strcmp(first_sibling, "null") != 0) {
//                 address firstSibling = findNodeByName(familyTree->root, first_sibling);
//                 if (firstSibling == NULL) {
//                     firstSibling = alok_available_pers(first_sibling, 0, ' ');
//                 }
//                 newNode->node_fs = firstSibling;
//             }
//         } else if (sscanf(line, "next_sibling: %s", next_sibling) == 1) {
//             if (strcmp(next_sibling, "null") != 0) {
//                 address nextSibling = findNodeByName(familyTree->root, next_sibling);
//                 if (nextSibling == NULL) {
//                     nextSibling = alok_available_pers(next_sibling, 0, ' ');
//                 }
//                 newNode->node_nb = nextSibling;
//             }
//         } else if (sscanf(line, "parent: %s", parent) == 1) {
//             if (strcmp(parent, "null") != 0) {
//                 address parentNode = findNodeByName(familyTree->root, parent);
//                 if (parentNode == NULL) {
//                     parentNode = alok_available_pers(parent, 0, ' ');
//                 }
//                 newNode->node_parrent = parentNode;
//             }
//         } else if (strcmp(line, "\n") == 0) {
//             break;
//         }
//     }

//     return newNode;
// }

// telm_root* loadFamilyTreeFromFile(const char *filepath) {
//     FILE *file = fopen(filepath, "r");
//     if (file == NULL) {
//         perror("Unable to open file for reading");
//         return NULL;
//     }

//     telm_root *familyTree = (telm_root*)malloc(sizeof(telm_root));
//     familyTree->root = NULL;

//     char line[MAX_LINE_LENGTH];
//     while (fgets(line, MAX_LINE_LENGTH, file)) {
//         address node = deserializeNode(file, familyTree, line);
//         if (node && familyTree->root == NULL) {
//             familyTree->root = node;
//         }
//     }

//     fclose(file);
//     return familyTree;
// }




int main()
{
    system("Color 0B");
    
    // masih testing module
    telm_root test;
    make_tree(&test);
    // init_Root(&test);
    // // telm_root *loadedFamilyTree
    // // init_Root(loadedFamilyTree);
    // init_Root(&test);
    // Root(test) = alok_available_pers("Root", 50, 'L');
    // point_marriage_unknown(Root(test));
    // point_birth_available(Root(test), "Anak1", 10, 'L');
    // point_birth_available(Root(test), "Anak2", 5, 'P');
    // point_birth_available(Root(test)->node_fs, "Anak1.1", 30, 'L');
    // point_birth_available(Root(test)->node_fs, "Anak1.2", 20, 'L');
    // point_birth_available(Root(test)->node_fs->node_fs, "Anak1.1.1", 10, 'L');
    // point_birth_available(Root(test)->node_fs->node_fs, "Anak1.1.2", 9, 'L');
    // save_Tree_To_File("familyTree.txt", &test);
    int i;
    i = countLivingFamilyMembers(Root(test));
    printTree(Root(test), 0);
    printf("\nJumlah anggota keluarga yang masih hidup: %d\n", i);
    
    
    // telm_root *loadedFamilyTree = loadFamilyTreeFromFile("data/family_tree.txt");   
    // printTree(loadedFamilyTree, 0);
    // readFamilyData("familyTree.txt", &test);
    // char temp_name[MAX_NAME_LENGTH] = "anak1.2.2";
    // address temp = search_handler(Root(test), temp_name);

    return 0;
}
