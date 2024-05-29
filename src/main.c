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


// address findNodeByName(address root, char* name) {
//     if (root == NULL) return NULL;
//     if (strcmp(root->info.nama, name) == 0) return root;
//     address found = findNodeByName(root->node_fs, name);
//     if (found) return found;
//     return findNodeByName(root->node_nb, name);
// }



int main()
{
    system("Color 0B");
    
    // masih testing module
    telm_root test;
    // make_tree(&test);
    init_Root(&test);
    // // telm_root *loadedFamilyTree
    // // init_Root(loadedFamilyTree);
    // point_birth_available(Root(test), "Anak2", 5, 'P');
    // point_birth_available(Root(test)->node_fs, "Anak1.1", 30, 'L');
    // point_birth_available(Root(test)->node_fs, "Anak1.2", 20, 'L');
    // point_birth_available(Root(test)->node_fs->node_fs, "Anak1.1.1", 10, 'L');
    // point_birth_available(Root(test)->node_fs->node_fs, "Anak1.1.2", 9, 'L');
    // save_Tree_To_File("familyTree.txt", &test);
    loadDataFromFile("familyTree.txt", &test);
    printTree(Root(test), 0);
    // telm_root *loadedFamilyTree = loadFamilyTreeFromFile("data/family_tree.txt");   
    // printTree(loadedFamilyTree, 0);
    // readFamilyData("familyTree.txt", &test);
    // char temp_name[MAX_NAME_LENGTH] = "anak1.2.2";
    // address temp = search_handler(Root(test), temp_name);

    return 0;
}
