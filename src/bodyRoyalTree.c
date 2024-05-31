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
    while (*str)
    {
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
        }
        else if (choice == 2)
        {
            gender = 'P';
        }
        gender = toupper(gender);
        if (gender != 'L' && gender != 'P')
        {
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
        if (X->node_mate != NULL)
        {
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
        if (X->node_mate != NULL)
        {
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
    address temp;
    do
    {
        if (X->node_fs != NULL)
        {
            address current = X->node_fs;

            int curr_age = current->info.age;
            while (current->node_nb != NULL || curr_age == 0)
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
            temp = X->node_fs;
            while (temp != NULL)
            {
                if (strcmp(temp->info.nama, node->info.nama) == 0)
                {
                    printf("Name already exist\n");
                    node = NULL;
                    break;
                }
                temp = temp->node_nb;
            }
        }
        else if (X->node_fs == NULL)
        {
            node = alok_input_pers();
        }
    } while (node == NULL);

    if (X->node_fs == NULL)
    {
        X->node_fs = node;
        if (X->node_mate != NULL)
        {
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
void point_marriage_available(telm_familly *X, infotype nama[MAX_NAME_LENGTH], int age, char gender)
{
    address Y = alok_available_pers(nama, age, gender);
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
    address node;
    do
    {
        node = alok_input_pers();
        if (node->info.gender == X->info.gender)
        {
            printf("\npernikahan tidak boleh sejenis");
            printf("\n\tPress any key to continue . . . ");
            getch();
            system("cls");
            free(node);
            node = NULL;
        }
        if (node->info.age < 18)
        {
            printf("Umur minimal 18 tahun\n");
            printf("\n\tPress any key to continue . . . ");
            getch();
            system("cls");
            free(node);
            node = NULL;
        }
        
    } while (node == NULL);
    
    if (X->node_mate == NULL)
    {
        X->node_mate = node;
    }
    if (node->node_mate == NULL)
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
address search(address node, infotype name[MAX_NAME_LENGTH])
{
    if (node == NULL)
    {
        return NULL;
    }

    if (strcmp(node->info.nama, name) == 0)
    {
        return node;
    }
    if (node->node_mate != NULL)
    {
        if (strcmp(node->node_mate->info.nama, name) == 0)
        {
            return node->node_mate;
        }
    }

    address result = search(node->node_fs, name);
    if (result != NULL)
    {
        return result;
    }
    return search(node->node_nb, name);
}

address search_handler(address node, infotype name[MAX_NAME_LENGTH])
{
    char temp_name[MAX_NAME_LENGTH];
    strcpy(temp_name, name);
    string_to_uppercase(temp_name);
    address result = search(node, temp_name);
    if (result == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found\n");
    }
    return result;
}

// Prosedur untuk mencetak pohon secara rekursif dengan pre order
// author : Daffa Muzhafar
// I.S : Tree belum tercetak
// F.S : Tree tercetak dengan garis silsilah tiap generasi
void printTree(address root, int level)
{
    if (root == NULL)
        return;
    int i;
    int j;
    for (i = 0; i < level; i++)
    {  
        printf("                |");
    }
    printf("- %s[ %c ][ %d ]\n", root->info.nama, root->info.gender ,root->info.age);
    if (root->node_mate != NULL)
    {
        for (i = 0; i < level; i++)
        {
            printf("                |");
        }
        printf("- %s[ %c ][ %d ]\n", root->node_mate->info.nama, root->node_mate->info.gender, root->node_mate->info.age);
    }

    printTree(root->node_fs, level + 1);
    printTree(root->node_nb, level);
}

// Prosedur untuk melakukan traversal secara pre-order
// author: Daffa Muzhafar & Ais Laksana
// I.S. : Tree belum
// F.S. : Tree dicetak secara pre-order
void trav_pre_order(address root)
{
    if (root == NULL)
        return;
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

    if (isRoot)
    {
        fprintf(file, "# Root\n");
    }
    else
    {
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


// Function untuk menghitung anggota keluarga yang masih hidup
// author: Alya Naila Putri Ashadilla
// I.S. : anggota keluarga yang masih hidup belum diketahui 
// F.S. : anggota keluarga yang masih hidup sudah diketahui
int countLivingFamilyMembers(address node) {
    int count = 0;
    if (node == NULL){ // Jika node kosong, maka akan mengembalikan nilai 0
        return 0;
    } else if(node->info.alive){ //jika status hidup node bersifat true maka nilai count akan bertambah
        count++;
    }
    if (node->node_mate != NULL && node->node_mate->info.alive == true)
    {
        count++;
    }
    
    
    //Menghitung jumlah anggota keluarga hidup pada node pasangan, anak, dan saudara
    count +=countLivingFamilyMembers(node->node_fs);
    count +=countLivingFamilyMembers(node->node_nb);

    return count;
}

// Fungsi untuk memprediksi pewaris takhta selanjutnya dari suatu node
// author: Alya
// I.S : nama pewaris takhta belum diketahui
// F.S : nama pewaris takhta telah diketahui
void successorPrediction(address root, infotype name[MAX_NAME_LENGTH]) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    // Cari node dengan nama yang sesuai
    address current = search(root, name);;

    if (current == NULL) {
        printf("Person with name '%s' not found.\n", name); 
    }else {
        // Lakukan prediksi berdasarkan aturan penurunan tahta
        // Jika memiliki anak dan masih hidup, pewaris tahta adalah anak pertama yang masih hidup
        if ((current->node_fs != NULL) && (current->node_fs->info.alive == true)) {
            printf("Predicted heir: %s\n", current->node_fs->info.nama);
            return;
        }

        // Jika tidak memiliki anak tapi memiliki saudara, pewaris tahta adalah saudara pertama yang masih hidup
        if (current->node_nb != NULL) {
            address temp = current->node_nb;
            while (temp != NULL && temp->info.alive != true) {
                temp = temp->node_nb;
            }
            if (temp != NULL) {
                printf("Predicted heir: %s\n", temp->info.nama);
                return;
            }
        }

        // Cari pewaris tahta di antara saudara-saudara orang tua
        if (current->node_parrent != NULL && current->node_parrent->node_nb != NULL) {
            address temp = current->node_parrent->node_nb;
            while (temp != NULL && temp->info.alive != true) {
                temp = temp->node_nb;
            }
            if (temp != NULL) {
                    printf("Predicted heir: %s\n", temp->info.nama);
                    return;
            }

        }

        //Jika tidak ada saudara dari orang tua, cari pewaris tahta dari anak saudara orang tua
       if (current->node_parrent != NULL && current->node_parrent->node_nb != NULL) { 
            if(current->node_parrent->node_nb != current && current->node_parrent->node_nb->node_fs != NULL){
                address temp = current->node_parrent->node_nb;
                successorPrediction(temp, temp->info.nama);
                return;
            }
        }

        // Jika tidak ada sepupu, perlu untuk memeriksa di atas
        if (current->node_parrent != NULL && current->node_parrent->node_parrent != NULL && current->node_parrent->node_parrent->node_nb != NULL) {
            successorPrediction(current->node_parrent->node_parrent->node_nb, current->node_parrent->node_parrent->node_nb->info.nama);
            return;
        }
        
        // Jika tidak ada pewaris tahta yang sesuai, maka tidak ada prediksi yang bisa dibuat.
        printf("No predicted heir found for %s.\n", name);
        return;
    }
}

// Function untuk menghitung generasi dari anggota keluarga
// author: Alya Naila Putri Ashadilla
// I.S. : generasi dari anggota keluarga belum diketahui 
// F.S. : generasi dari anggota keluarga diketahui
int depth(address node) {
    if (node == NULL) { //jika node kosong, maka akan mengembalikan nilai 0
        return 0;
    } else { //jika node tidak kosong 
        int maxDepth = 0;

        if (node->node_fs != NULL) {// jika anak dari node tidak kosong
             // Hitung kedalaman dari anak pertama (fs) dari node
            int depth_fs = depth(node->node_fs);
            if (depth_fs > maxDepth) {// Ubah nilai maksimal dari kedalaman dengan kedalaman anak pertama, jika nilainya lebih besar
                maxDepth = depth_fs;
            }
        }
        if (node->node_nb != NULL) { // jika saudara dari node tidak kosong
            int depth_nb = depth(node->node_nb);

            if (depth_nb > maxDepth) {  // Ubah nilai maksimal dari kedalaman dengan kedalaman saudara, jika nilainya lebih besar
                maxDepth = depth_nb;
            }
        }
        return maxDepth + 1;
    }
}

// Function untuk menghitung generasi dari anggota keluarga
// author: Alya Naila Putri Ashadilla
// I.S. : generasi dari anggota keluarga belum diketahui 
// F.S. : generasi dari anggota keluarga diketahui
int countGenerations(address root, infotype name[MAX_NAME_LENGTH]) {
    // Jika root kosong, maka generasi tidak terdefinisi
    if (root == NULL) {
        printf("Tree is empty.\n");
        return 0;
    } else {
        address node = search(root, name);
        if (node == NULL) {
            printf("Person with name '%s' not found.\n", name);
            return 0;
        } else if (node->node_parrent == NULL) { // Jika node adalah akar, maka generasinya adalah 1
            return 1;
        } else {
            // Hitung kedalaman dari akar pohon
            int treeDepth = depth(root);

            // Hitung kedalaman dari node yang dicari
            int nodeDepth = depth(node);

            // Generasi adalah selisih antara kedalaman akar pohon dan kedalaman node
            return treeDepth - nodeDepth + 1;
        }
    }
}

// Fungsi untuk menghapus salah satu anggota keluarga kerajaan berserta keturunannya
// author: Alya Naila Putri Ashadilla
// I.S : anggota keluarga beserta keturunannya masih ada dalam silsilah kerajaan inggris
// F.S : salah satu anggota keluarga beserta keturunannya sudah terhapus dari silsilah kerajaan inggris
void deleteNodeWithDescendants(address *root, infotype name[MAX_NAME_LENGTH]) {
    // Mengecek apakah tree kosong
    if (*root == NULL) {
        return;
    }

    // Mencari node dengan nama yang dicari
    if (strcmp((*root)->info.nama, name) == 0) {
        // Menghapus node
        telm_familly *temp = *root;
        *root = (*root)->node_nb;
        free(temp);
        printf("Node with name %s has been deleted.\n", name);
        return;
    }

    // Menghapus anak dari node secara rekursif
    deleteNodeWithDescendants(&((*root)->node_fs), name);

    // Menghapus node sibling secara rekrusif
    if (*root != NULL) {
        deleteNodeWithDescendants(&((*root)->node_nb), name);
    }
}



int countLastDescendants(address root) {
    if (root == NULL) {
        return 0;
    } else if (root->node_fs == NULL && root->node_nb == NULL) {
        printf("%s\n", root->info.nama);
        return 1;
    } else {
        int count = 0;
        count += countLastDescendants(root->node_fs);
        count += countLastDescendants(root->node_nb);
        return count;
    }
}



void printFromFile(const char* location){
	FILE *read;
	char c;

	read=fopen(location, "rt");
	while((c=fgetc(read))!=EOF){
		printf("%c", c);
	}
    

	fclose(read);
}


address createNode(dataInfo info) {
    address newNode = (address)malloc(sizeof(telm_familly));
    newNode->info = info;
    newNode->node_mate = NULL;
    newNode->node_fs = NULL;
    newNode->node_nb = NULL;
    newNode->node_parrent = NULL;
    return newNode;
}

void addMember(telm_root *tree, dataInfo info, char* parentName, char* mateName, char* firstSonName, char* nextSiblingName) {
    address newNode = createNode(info);
    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        address parent = search(tree->root, parentName);
        address mate = search(tree->root, mateName);
        address firstSon = search(tree->root, firstSonName);
        address nextSibling = search(tree->root, nextSiblingName);

        if (parent) {
            newNode->node_parrent = parent;
            if (parent->node_fs == NULL) {
                parent->node_fs = newNode;
                if (parent->node_mate != NULL)
                {
                    parent->node_mate->node_fs = newNode;
                    /* code */
                }
                
            } else {

                address sibling = parent->node_fs;
                while (sibling->node_nb) {
                    sibling = sibling->node_nb;
                }
                sibling->node_nb = newNode;
            }
        }

        if (mate) {
            newNode->node_mate = mate;
            mate->node_mate = newNode;
            newNode->node_mate->node_fs = newNode->node_fs;
            
        }

        if (firstSon) {
            newNode->node_fs = firstSon;
            if (newNode->node_mate != NULL)
            {
                newNode->node_mate->node_fs = firstSon;
            }
        }

        if (nextSibling) {
            newNode->node_nb = nextSibling;
        }
    }
}

void loadDataFromFile(const char* filename, telm_root *tree) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    dataInfo info;
    char line[MAX_LINE_LENGTH];
    char mateName[MAX_NAME_LENGTH], firstSonName[MAX_NAME_LENGTH], nextSiblingName[MAX_NAME_LENGTH], parentName[MAX_NAME_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "# Person") != NULL || strstr(line, "# Root") != NULL || strstr(line, "# Mate") != NULL) {
            fgets(line, sizeof(line), file); // Read the name line
            sscanf(line, "name: %s", info.nama);
            fgets(line, sizeof(line), file); // Read the age line
            sscanf(line, "age: %d", &info.age);
            fgets(line, sizeof(line), file); // Read the gender line
            sscanf(line, "gender: %c", &info.gender);
            fgets(line, sizeof(line), file); // Read the alive line
            char aliveStr[MAX_NAME_LENGTH];
            sscanf(line, "alive: %s", aliveStr);
            info.alive = (strcmp(aliveStr, "true") == 0);

            fgets(line, sizeof(line), file); // Read the mate line
            sscanf(line, "mate: %s", mateName);
            fgets(line, sizeof(line), file); // Read the first_son line
            sscanf(line, "first_son: %s", firstSonName);
            fgets(line, sizeof(line), file); // Read the next_sibling line
            sscanf(line, "next_sibling: %s", nextSiblingName);
            fgets(line, sizeof(line), file); // Read the parent line
            sscanf(line, "parent: %s", parentName);

            addMember(tree, info, parentName, mateName, firstSonName, nextSiblingName);
        }
    }

    fclose(file);
}

void gotoxy(int X, int y) {
	COORD coord;
	coord.X = X;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loading_screen() {
	int i;
	gotoxy(50, 10); printf("Loading...");
	gotoxy(50, 12);
	for (i = 0; i <= 17; i++) {
		Sleep(90);
		printf("%c", 177);
	}
	printf("\n\n");
	system("pause");
	system("cls");
}



// prosedur fitur untuk menambah anggota kerajaan
// author : Ais Laksana & Daffa Muzhafar
// I.S : node belum di tambah
// F.S : node sudah di tambah
void tambah_anak(address root)
{
    char name_parent[MAX_NAME_LENGTH];
    address parent;
    do
    {
        system("cls");
        printTree(root, 0);
        printf("Masukkan nama orang tua: ");
        scanf(" %[^\n]", name_parent);
        getchar();
        /* code */
        parent = search_handler(root, name_parent);
        if (parent == NULL)
        {
            system("cls");
            printf("[ %s ] Tidak ditemukan dalam pohon keluarga\n", name_parent);
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
        if (parent->info.age < 18)
        {
            printf("Orang tua harus berusia minimal 18 tahun\n");
            printf("\n\tPress any key to continue . . . ");
            getch();
            parent = NULL;
        }
        if (parent->node_mate == NULL)
        {
            printf("Orang tua belum menikah\n");
            printf("\n\tPress any key to continue . . . ");
            getch();
            parent = NULL;
        }
    } while (parent == NULL && strcmp(name_parent, "\n") != 0);

    if (parent == NULL)
    {
        printf("Orang tua tidak ditemukan\n");
        return;
    }
    printf("Data diri calon anak : \n");
    point_birth_input(parent);
    
    
    system("cls");
    printTree(root, 0);
    printf("[ %s ] dikaruniai anak\n", parent->info.nama);
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");
}

// prosedur untuk dummy data
void make_tree(telm_root *familyTree)
{
    familyTree->root = alok_available_pers("Root", 50, 'L');
    point_marriage_unknown(familyTree->root);
    point_birth_available(familyTree->root, "Anak1", 10, 'L');
    point_birth_available(familyTree->root, "Anak2", 5, 'P');
    point_birth_available(familyTree->root->node_fs, "Anak1.1", 30, 'L');
    point_birth_available(familyTree->root->node_fs, "Anak1.2", 20, 'L');
    point_birth_available(familyTree->root->node_fs->node_fs, "Anak1.1.1", 10, 'L');
    point_birth_available(familyTree->root->node_fs->node_fs, "Anak1.1.2", 9, 'L');
}

void nikahkan(address root)
{
    if (root == NULL)
    {
        return;
    }
    address temp = NULL;
    do
    {
        system("cls");
        printTree(root, 0);
        printf("Siapa yang ingin dinikahkan : \n");
        char nama[MAX_NAME_LENGTH];
        scanf(" %[^\n]", nama);
        getchar();
        temp = search_handler(root, nama);
        if (temp->node_mate != NULL)
        {
            system("cls");
            printf("[ %s ] Sudah menikah, jangan ganggu yang sudah menikah~\n", temp->info.nama);
            temp = NULL;
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
        if (temp == NULL)
        {
            system("cls");
            printf("[ %s ] tidak di temukan\n", temp->info.nama);
            temp = NULL;
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
        if (temp->info.age < 18)
        {
            printf("Usia minimal untuk menikah adalah 18 tahun\n");
            printf("\n\tPress any key to continue . . . ");
            getch();
            temp = NULL;
        }
    } while (temp == NULL);
    printf("Data diri calon pasangan :\n");
    point_marriage_input(temp);
    if (temp->node_fs != NULL)
    {
        temp->node_mate->node_fs = temp->node_fs;
    }
    
    system("cls");
    printTree(root, 0);
    printf("[ %s ] menikah dengan [ %s ] \n", temp->info.nama, temp->node_mate->info.nama);
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");
}

void tampilkan_informasi(address root)
{
    if (root == NULL)
    {
        return;
    }
    address temp = NULL;
    do
    {
        system("cls");
        printTree(root, 0);
        printf("Siapa yang ingin dilihat informasinya : \n");
        infotype nama[MAX_NAME_LENGTH];
        scanf(" %[^\n]", nama);
        getchar();
        temp = search_handler(root, nama);
        if (temp == NULL)
        {
            system("cls");
            printf("[ %s ] Tidak ditemukan dalam pohon keluarga\n", nama);
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
    } while (temp == NULL);
    system("cls");
    print_datainfo(temp->info);
    printf("first son = %s\n", temp->node_fs ? temp->node_fs->info.nama : "null");
    printf("next sibling = %s\n", temp->node_nb ? temp->node_nb->info.nama : "null");
    printf("parent = %s dan %s\n", temp->node_parrent ? temp->node_parrent->info.nama : "null", temp->node_parrent ? temp->node_parrent->node_mate->info.nama : "null");
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");
}

void membunuh(address root)
{
    if (root == NULL)
    {
        return;
    }
    address temp = NULL;
    do
    {
        system("cls");
        printTree(root, 0);
        printf("Siapa aggota yang ingin dibunuh : \n");
        infotype nama[MAX_NAME_LENGTH];
        scanf(" %[^\n]", nama);
        getchar();
        temp = search_handler(root, nama);
        if (temp == NULL)
        {
            system("cls");
            printf("[ %s ] Tidak ditemukan dalam pohon keluarga\n", nama);
            printf("\n\tPress any key to continue . . . ");
            getchar();
        }
    } while (temp == NULL);
    system("cls");
    point_kill(temp);
    printf("[ %s ] telah meninggal", temp->info.nama);
    printf("\n\tPress any key to continue . . . ");
    getchar();
    system("cls");
}

void penerus(address root){
    if (root == NULL)
    {
        return;
    }
    address temp = NULL;
    do
    {
        system("cls");
        printTree(root, 0);
        printf("Siapa yang ingin dilihat informasinya : \n");
        infotype nama[MAX_NAME_LENGTH];
        scanf(" %[^\n]", nama);
        getchar();
        temp = search_handler(root, nama);
        if (temp == NULL)
        {
            system("cls");
            printf("[ %s ] Tidak ditemukan dalam pohon keluarga\n", nama);
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
    } while (temp == NULL);
    system("cls");
    successorPrediction(root, temp->info.nama);
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");
}


// modul meng insert raja pertama
address insert_king(telm_root *L){
    infotype nama[MAX_NAME_LENGTH];
    address King = NULL;
    do
    {
        printTree(L->root, 0);
        printf("Masukkan nama raja : ");
        scanf(" %[^\n]", &nama);
        King = search_handler(L->root, nama);
         if (King == NULL)
        {
            system("cls");
            printf("[ %s ] Tidak ditemukan dalam pohon keluarga\n", nama);
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
    } while (King == NULL);
    system("cls");
    printf("[ %s ] telah menjadi Raja/Ratu yang baru", King->info.nama);
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");
    return King;
}

void print_king(address King){
    if (King == NULL)
    {
        printf("Tahta saat ini kosong\n");
    }else{
        printf("Raja/Ratu saat ini : %s\n", King->info.nama);
        printf("Umur : %d\n", King->info.age);
    }
}


void menghitung_generasi(address root){
    infotype nama[MAX_NAME_LENGTH];
    address temp;
    do
    {
        printTree(root, 0);
        printf("Masukkan nama orang yang ingin di cari generasinny : ");
        scanf(" %[^\n]", &nama);
        temp = search_handler(root, nama);
        if (temp == NULL)
        {
            system("cls");
            printf("[ %s ] Tidak ditemukan dalam pohon keluarga\n", nama);
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
    } while (temp == NULL);
    printf("[ %s ] merupakan generasi ke %d", temp->info.nama, countGenerations(root, temp->info.nama));
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");
}

// Menambahkan umur tiap anggota kerajan dengan parameter year
// author : Ais Laksana
// I.S : umur belum bertambah
// F.S : umur bertambah sesuai dengan parameter
void timeskip(address root, int year){
    if (root == NULL)
        return;
    if (root->info.alive == true)
    {
        root->info.age += year;
    }
    
    if (root->node_mate != NULL && root->node_mate->info.alive == true)
    {
        root->node_mate->info.age += year;
    }
    
    timeskip(root->node_fs, year);
    timeskip(root->node_nb, year);
}


void timeskip_input(address root){
    int year;
    printf("Masukkan tahun yang ingin dilewati : ");
    scanf("%d", &year);
    timeskip(root, year);
    printf("Waktu telah dilewati %d tahun\n", year);
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");

}


int count_all_member(address node) {
    int count = 0;
    if (node == NULL){ // Jika node kosong, maka akan mengembalikan nilai 0
        return 0;
    } else{ //jika status hidup node bersifat true maka nilai count akan bertambah
        count++;
    }
    if (node->node_mate != NULL)
    {
        count++;
    }
    
    
    //Menghitung jumlah anggota keluarga hidup pada node pasangan, anak, dan saudara
    count +=count_all_member(node->node_fs);
    count +=count_all_member(node->node_nb);

    return count;
}


void cek_king(address *current)
{
    // Check if the current node has a living child
    if ((*current)->node_fs != NULL && (*current)->node_fs->info.alive)
    {
        *current = (*current)->node_fs;
        printf("%s adalah pewaris tahta\n", (*current)->info.nama);
        return;
    }

    // Check if the current node has a living sibling
    if ((*current)->node_nb != NULL)
    {
        address temp = (*current)->node_nb;
        while (temp != NULL && !temp->info.alive)
        {
            temp = temp->node_nb;
        }
        if (temp != NULL)
        {
            *current = temp;
            printf("%s adalah pewaris tahta\n", (*current)->info.nama);
            return;
        }
    }

    // Check the siblings of the parent for a living heir
    if ((*current)->node_parrent != NULL && (*current)->node_parrent->node_nb != NULL)
    {
        address temp = (*current)->node_parrent->node_nb;
        while (temp != NULL && !temp->info.alive)
        {
            temp = temp->node_nb;
        }
        if (temp != NULL)
        {
            *current = temp;
            printf("%s adalah pewaris tahta\n", (*current)->info.nama);
            return;
        }
    }

    // Check the children of the parent's siblings (cousins) for a living heir
    if ((*current)->node_parrent != NULL && (*current)->node_parrent->node_nb != NULL)
    {
        address temp = (*current)->node_parrent->node_nb;
        while (temp != NULL)
        {
            if (temp->node_fs != NULL)
            {
                address tempChild = temp->node_fs;
                while (tempChild != NULL && !tempChild->info.alive)
                {
                    tempChild = tempChild->node_nb;
                }
                if (tempChild != NULL)
                {
                    *current = tempChild;
                    printf("%s adalah pewaris tahta\n", (*current)->info.nama);
                    return;
                }
            }
            temp = temp->node_nb;
        }
    }

    // Check higher generations if no heir found among current generation and cousins
    if ((*current)->node_parrent != NULL && (*current)->node_parrent->node_parrent != NULL)
    {
        address temp = (*current)->node_parrent->node_parrent->node_nb;
        while (temp != NULL)
        {
            cek_king(&temp);
            if (temp->info.alive)
            {
                *current = temp;
                printf("%s adalah pewaris tahta\n", (*current)->info.nama);
                return;
            }
            temp = temp->node_nb;
        }
    }

    printf("%s telah digantikan\n", (*current)->info.nama);
    printf("\n\tPress any key to continue . . . ");
    getchar();
    system("cls");
}

void delete_input(telm_familly *root){
    infotype nama[MAX_NAME_LENGTH];
    address temp;
    do
    {
        printTree(root->node_fs, 0);
        printf("Masukkan nama orang yang ingin di cari generasinny : ");
        scanf(" %[^\n]", &nama);
        temp = search_handler(root, nama);
        if (temp == NULL)
        {
            system("cls");
            printf("[ %s ] Tidak ditemukan dalam pohon keluarga\n", nama);
            printf("\n\tPress any key to continue . . . ");
            getch();
        }
    } while (temp == NULL);
    deleteNodeWithDescendants(&root, nama);
    printf("%s beserta keturunannya telah dihapus dari sejarah silsilah kerajan\n", temp->info.nama);
    printf("\n\tPress any key to continue . . . ");
    getch();
}

void jumlah_generasi_terakhir(address root){
    printf("Jumlah generasi terakhir : %d\n", countLastDescendants(root));
    printf("\n\tPress any key to continue . . . ");
    getch();
    system("cls");

}


void start(){
    system("cls");
    printFromFile("tampilan/tampilan_awal.txt");
    printf("\n\n\t\t\t\t\t\t\t    Press Enter To Continue");
    getchar();     //Menunggu untuk menekan enter
    system("cls"); // Membersihkan layar terminal // Membersihkan layar terminal
}

void Aturan()
{
    printFromFile("tampilan/aturan.txt");
    printf("\n");
}
