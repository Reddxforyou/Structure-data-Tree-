#include "headerRoyalTree.h"



// Prosedur initiasi root
// author : Ais Laksana
// I.S : root belum diinisialisasi
// F.S : root sudah diinisialisasi
void init_Root(telm_root *L)
{
    L->root = NULL;
}


// Prosedur untuk membuat semua char pada array of Char menjadi Uppercase
// ref : https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case, GPT 
// author : Ais Laksana
// I.S : parameter array of char belum diubah
// F.S : parameter array of char sudah diubah menjadi uppercase
void string_to_uppercase(char *str) 
{
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}


// keterangan data module

// data info module
// Fungsi meng input data info unknown
// author : Ais Laksana
// 
dataInfo ket_unknown()
{
    dataInfo ket;
    strcpy(ket.nama, Unknown_name);
    ket.age = 0;
    ket.gender = Unknown_gender;
    ket.alive = true;
    return ket;
}

// Fungsi meng input data info berdasar parameter
// author : Ais Laksana
// I.S : (dataInfo) belum ada
// F.S : fungsi mereturn (dataInfo) berdasar parameter
dataInfo ket_available(infotype nama[MAX_NAME_LENGTH], int age, char gender)
{
    dataInfo person;
    gender = toupper(gender);
    if (gender != 'L' && gender != 'P')
    {
        gender = Unknown_gender;
    }

    strcpy(person.nama, nama);
    string_to_uppercase(person.nama);
    person.age = age;
    person.gender = gender;
    person.alive = true;
    return person;
}

// Fungsi meng input data info yang diinput user
// author : Ais Laksana
// I.S : (dataInfo) belum ada
// F.S : fungsi mereturn (dataInfo) yang sudah diinput user
dataInfo ket_input()
{
    dataInfo person;
    char gender;
    printf("Masukkan nama : ");
    scanf(" %[^\n]", person.nama);
    string_to_uppercase(person.nama);
    printf("Masukkan umur : ");
    scanf("%d", &person.age);	
    do
    {

        int choice;
        printf("Gender : \n1. Laki-laki\n2. Perempuan\n");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            gender = 'L';
        }else if (choice == 2)
        {
            gender = 'P';
        }
        gender = toupper(gender);
        if(gender != 'L' && gender != 'P'){
            printf("di dunia ini gender hanya ada 2\n");
        }
    } while (gender != 'L' && gender != 'P');

    person.gender = gender;
    person = ket_available(person.nama, person.age, person.gender);
    return person;
}

// Fungsi alokasi node module
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node yang sudah di alokasi dengan datainfo sesuai dengan parameter
address alok_pointer(dataInfo _info)
{
    address P;
    P = (address)malloc(sizeof(telm_familly));
    if (P != NULL)
    {
        P->info = _info;
    }
    P->node_fs = NULL;
    P->node_mate = NULL;
    P->node_nb = NULL;
    P->node_parrent = NULL;
    return P;
}

// Fungsi alokasi node dengan datainfo unknown
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node sudah di alokasi dengan (datainfo) unknown
address alok_unknown_pers()
{
    dataInfo person = ket_unknown();
    return alok_pointer(person);
}

// Fungsi alokasi node dengan input parameter
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node sudah di alokasi berdasar input parameter
address alok_available_pers(infotype name[MAX_NAME_LENGTH], int age, char gender)
{
    dataInfo person = ket_available(name, age, gender);
    return alok_pointer(person);
}

// Fungsi alokasi node dengan input user
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node sudah di alokasi berdasar input user
address alok_input_pers()
{
    dataInfo person = ket_input();
    return alok_pointer(person);
}

// Prosedur print (dataInfo) module
// author : Ais Laksana
// I.S : dataInfo belum di print
// F.S : dataInfo sudah di print
void print_datainfo(dataInfo X)
{
    infotype status[MAX_NAME_LENGTH];
    printf("Nama : %s\n", X.nama);
    printf("Age : %d\n", X.age);
    printf("Gender : %c\n", X.gender);
    if (X.alive)
    {
        strcpy(status, "Hidup");
        
    }
    else
    {
        strcpy(status, "Mati");
    }
    printf("Status hidup : %s\n", status);
}

// pointer allocation module

// birth module
// Prosedur memberikan suatu node dengan anak yang tidak diketahui
// author : Ais Laksana
// I.S : (X->node_fs) atau (X->node_fs->node_nb) pada suatu node masih NULL
// F.S : (X->node_fs) atau (X->node_fs->node_nb) menunjuk pada node dengan (ket_unknown()) pada (dataInfo)
void point_birth_unknown(telm_familly *X)
{
    address node = alok_unknown_pers();
    if (X->node_fs == NULL)
    {
        X->node_fs = node;
        if(X->node_mate != NULL){
            X->node_mate->node_fs = node;
        }
    }else{
        address temp = X->node_fs;
        while (temp->node_nb != NULL)
        {
            temp = temp->node_nb;
        }
        temp->node_nb = node;
    }
    node->node_parrent = X;

}

// Prosedur memberikan suatu node, anak dengan (dataInfo) dari paramerter
// author : Ais Laksana
// I.S : (X->node_fs) atau (X->node_fs->node_nb) pada suatu node masih NULL
// F.S : (X->node_fs) atau (X->node_fs->node_nb) menunjuk pada node dengan (dataInfo) sesuai dengan parameter
void point_birth_available(telm_familly *X, infotype nama[MAX_NAME_LENGTH], int age, char gender)
{
    address node = alok_available_pers(nama, age, gender);
    if (X->node_fs == NULL)
    {
        X->node_fs = node;
        if(X->node_mate != NULL){
            X->node_mate->node_fs = node;
        }
    }
    else
    {
        address temp = X->node_fs;
        while (temp->node_nb != NULL)
        {
            temp = temp->node_nb;
        }
        temp->node_nb = node;
    }
    node->node_parrent = X;
}

// Prosedur memberikan suatu node dengan anak yang diinput user
// author : Ais Laksana
// I.S : (X->node_fs) atau (X->node_fs->node_nb) pada suatu node masih NUL
// F.S : (X->node_fs) atau (X->node_fs->node_nb) menunjuk pada node yang diinput user
void point_birth_input(telm_familly *X)
{
    address node;
    do
    {
        if (X->node_fs != NULL)
        {
            address current = X->node_fs;
            
            int curr_age = current->info.age;
            while (current->node_nb != NULL && curr_age == 0)
            {
                if (curr_age > current->node_nb->info.age || curr_age == 0)
                {
                    curr_age = current->node_nb->info.age;
                }
                current = current->node_nb;
            }
            node = alok_input_pers();
            if (X->node_fs != NULL && node->info.age > curr_age && curr_age != 0)
            {
                system("cls");
                printf("current age inside restriction %d\n", curr_age);
                printf("Cannot add a brother older than the youngest brother/sister.\n");
                printf("current youngest brother/sister age : %d\n", curr_age);
                node = NULL;
            }
        }else if (X->node_fs == NULL)
        {
            node = alok_input_pers();
        }
    } while (node == NULL);

    if (X->node_fs == NULL)
    {
        X->node_fs = node;
        if(X->node_mate != NULL){
            X->node_mate->node_fs = node;
        }
    }
    else
    {
        address temp = X->node_fs;
        while (temp->node_nb != NULL)
        {
            temp = temp->node_nb;
        }
        temp->node_nb = node;
    }
    node->node_parrent = X;
}

// marriage module
// menikahkan node dengan node yang tidak diketahui
// author : Ais Laksana
// I.S : (X->node_mate) pada suatu node masih NULL
// F.S : (X->node_mate) menunjuk pada node dengan (ket_unknown()) pada (dataInfo) dan sebaliknya
void point_marriage_unknown(telm_familly *X)
{
    address node = alok_unknown_pers();
    if (X->node_mate == NULL)
    {
        X->node_mate = node;
        X->node_mate->node_mate = X;
    }
}

// Prosedur menikahkan node dengan node yang pada parameter
// author : Ais Laksana
// I.S : (X->node_mate) pada suatu node masih NULL
// F.S : (X->node_mate) menunjuk pada node (telm_familly Y) dan sebaliknya
void point_marriage_available(telm_familly *X, telm_familly *Y)
{
    if (X->node_mate == NULL)
    {
        X->node_mate = Y;
    }
    else
    {
        printf("%s already married\n", X->info.nama);
    }
    if (Y->node_mate == NULL)
    {
        Y->node_mate = X;
    }
    else
    {
        printf("%s already married\n", Y->info.nama);
    }
}

// Prosedur untuk menikahkan node dengan node yang diinput user
// author : Ais Laksana
// I.S : (X->node_mate) pada suatu node masih NULL
// F.S : (X->node_mate) menunjuk pada node yang diinput user dan sebaliknya
void point_marriage_input(telm_familly *X)
{
    address node = alok_input_pers();
    if (X->node_mate == NULL)
    {
        X->node_mate = node;
    }
    else if (node->node_mate == NULL)
    {
        node->node_mate = X;
    }
    else
    {
        printf("both already married\n");
    }
}

// Prosedur untuk mengubah status hidup node
// author : Ais Laksana
// I.S : status hidup pada (dataInfo) node belum diubah
// F.S : status hidup pada (dataInfo) node belum diubah
void point_kill(telm_familly *X)
{
    X->info.alive = false;
}

// Fungsi yang mereturn nama yang di cari
// author : Daffa Muzhafar & Ais Laksan
// I.S : node belum di cari
// F.S : node yang dicari ditemukan dan di return fungsi
address search(address node, infotype name[MAX_NAME_LENGTH]) {
    if (node == NULL) {
        return NULL;
    }
    
    if (strcmp(node->info.nama, name) == 0) {
        return node;
    }
    if (node->node_mate != NULL) {
        if (strcmp(node->node_mate->info.nama, name) == 0) {
            return node->node_mate;
        }
    }
    
    address result = search(node->node_fs, name);
    if (result != NULL) {
        return result;
    }
    return search(node->node_nb, name);
}

address search_handler(address node, infotype name[MAX_NAME_LENGTH]) {
    char temp_name[MAX_NAME_LENGTH];
    strcpy(temp_name, name);
    string_to_uppercase(temp_name);
    address result = search(node, temp_name);
    if (result == NULL) {
        printf("Not found\n");
    }else{
        printf("Found\n");
    }
    return result;
}


// Prosedur untuk mencetak pohon secara rekursif dengan pre order
// author : Daffa Muzhafar
// I.S : Tree belum tercetak
// F.S : Tree tercetak dengan garis silsilah tiap generasi
void printTree(address root, int level) {
    if (root == NULL) return;
    int i;
    for (i = 0; i < level; i++) {

        printf("	|");
    }
    printf("- %s\n", root->info.nama);
    if (root->node_mate != NULL)
    {
        printf("- %s\n", root->node_mate->info.nama);
    }
    
    printTree(root->node_fs, level + 1);
    printTree(root->node_nb, level);
}

// Prosedur untuk melakukan traversal secara pre-order
// author: Daffa Muzhafar & Ais Laksana
// I.S. : Tree belum 
// F.S. : Tree dicetak secara pre-order
void trav_pre_order(address root){
    if (root == NULL) return;
    printf(" %s", root->info.nama);
    if (root->node_mate != NULL)
    {
        printf(" pasangan dengan %s", root->node_mate->info.nama);
    }
    printf("\n");
    trav_pre_order(root->node_fs);
    trav_pre_order(root->node_nb);
}




// prosedur untuk menulis ulang data pada format string dalam file
// author : Ais Laksana
// I.S : file belum di tulis
// F.S : file sudah di tulis
void serialize_Node(FILE *file, address node, boolean isRoot)
{
    if (node == NULL)
        return;


    if (isRoot) {
        fprintf(file, "# Root\n");
    } else {
        fprintf(file, "# Person\n");
    }

    fprintf(file, "name: %s\n", node->info.nama);
    fprintf(file, "age: %d\n", node->info.age);
    fprintf(file, "gender: %c\n", node->info.gender);
    fprintf(file, "alive: %s\n", node->info.alive ? "true" : "false");
    fprintf(file, "mate: %s\n", node->node_mate ? node->node_mate->info.nama : "null");
    fprintf(file, "first_son: %s\n", node->node_fs ? node->node_fs->info.nama : "null");
    fprintf(file, "next_sibling: %s\n", node->node_nb ? node->node_nb->info.nama : "null");
    fprintf(file, "parent: %s\n", node->node_parrent ? node->node_parrent->info.nama : "null");
    fprintf(file, "\n");

    
    if (node->node_mate)
    {
        fprintf(file, "# Mate\n");
        fprintf(file, "name: %s\n", node->node_mate->info.nama);
        fprintf(file, "age: %d\n", node->node_mate->info.age);
        fprintf(file, "gender: %c\n", node->node_mate->info.gender);
        fprintf(file, "alive: %s\n", node->node_mate->info.alive ? "true" : "false");
        fprintf(file, "mate: %s\n", node->node_mate->node_mate ? node->node_mate->node_mate->info.nama : "null");
        fprintf(file, "first_son: %s\n", node->node_mate->node_fs ? node->node_mate->node_fs->info.nama : "null");
        fprintf(file, "next_sibling: %s\n", node->node_mate->node_nb ? node->node_mate->node_nb->info.nama : "null");
        fprintf(file, "parent: %s\n", node->node_mate->node_parrent ? node->node_mate->node_parrent->info.nama : "null");
        fprintf(file, "\n");
    }

    serialize_Node(file, node->node_fs, false); 
    serialize_Node(file, node->node_nb, false); 
}

// Prosedur untuk menghandle serialize node
// author : Ais Laksana
// I.S : file belum disimpan
// F.S : file sudah disimpan
void save_Tree_To_File(const char *filename, telm_root *familyTree)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Unable to open file for writing");
        return;
    }

    serialize_Node(file, familyTree->root, true);

    fclose(file);
}


// prosedur fitur untuk menambah anggota kerajaan
// author : Ais Laksana & Daffa Muzhafar
// I.S : node belum di tambah
// F.S : node sudah di tambah
void add_member(address root) {
    char name_parent[MAX_NAME_LENGTH];
    printf("Masukkan nama orang tua: ");
    scanf("%s", name_parent);
    address parent = search_handler(root, name_parent);
    if (parent == NULL) {
        printf("Orang tua tidak ditemukan\n");
        return;
    }
    point_birth_input(parent);
}


// prosedur untuk dummy data
void make_tree(telm_root *familyTree) {
    familyTree->root = alok_available_pers("Root", 50, 'L');
    point_marriage_unknown(familyTree->root);
    point_birth_available(familyTree->root, "Anak1", 10, 'L');
    point_birth_available(familyTree->root, "Anak2", 5, 'P');
    point_birth_available(familyTree->root->node_fs, "Anak1.1", 30, 'L');
    point_birth_available(familyTree->root->node_fs, "Anak1.2", 20, 'L');
    point_birth_available(familyTree->root->node_fs->node_fs, "Anak1.1.1", 10, 'L');
    point_birth_available(familyTree->root->node_fs->node_fs, "Anak1.1.2", 9, 'L');
}
