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
dataInfo ket_available(infotype nama, int age, char gender)
{
    dataInfo person;
    gender = toupper(gender);
    if (gender != 'L' && gender != 'P')
    {
        gender = Unknown_gender;
        printf("your gender is not available\n");
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
address alok_available_pers(infotype name, int age, char gender)
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
    infotype status;
    printf("Nama : %s\n", X.nama);
    printf("Age : %d\n", X.age);
    printf("Gender : %c\n", X.gender);
    if (X.alive)
    {
        status = "Hidup";
    }
    else
    {
        status = "Meninggal";
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
    

}

// Prosedur memberikan suatu node, anak dengan (dataInfo) dari paramerter
// author : Ais Laksana
// I.S : (X->node_fs) atau (X->node_fs->node_nb) pada suatu node masih NULL
// F.S : (X->node_fs) atau (X->node_fs->node_nb) menunjuk pada node dengan (dataInfo) sesuai dengan parameter
void point_birth_available(telm_familly *X, infotype nama, int age, char gender)
{
    address node = alok_available_pers(nama, age, gender);
    if (X->node_fs == NULL)
    {
        X->node_fs = node;
        if(X->node_mate != NULL){
            X->node_mate->node_fs = node;
        }
        X->node_fs->node_parrent = X;
    }
    else
    {
        address temp = X->node_fs;
        while (temp->node_nb != NULL)
        {
            temp = temp->node_nb;
        }
        temp->node_nb = node;
         temp->node_parrent = X->node_parrent;
    }
   
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
address search(address node, infotype name) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(node->info.nama, name) == 0) {
        printf("Found");
        return node;
    }
    if (node->node_mate != NULL) {
        if (strcmp(node->node_mate->info.nama, name) == 0) {
            printf("Found");
            return node->node_mate;
        }
    }
    
    address result = search(node->node_fs, name);
    if (result != NULL) {
        return result;
    }
    return search(node->node_nb, name);
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
    for (i = 0; i < level; i++)
    {

        printf("	|");
    }
    printf("- %s\n", root->info.nama);
    if (root->node_mate != NULL)
    {
        for (i = 0; i < level; i++)
        {

            printf("	|");
        }
        printf("- %s\n", root->node_mate->info.nama);
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

// Function untuk menghitung nilai maksimum kedalaman dari tree
// author: Alya Naila Putri Ashadilla
// I.S. : Maksimum kedalaman dari tree belum diketahui 
// F.S. : Maksimum kedalaman dari tree sudah diketahui
int depth(address root) {
	int fs,nb;

	if(root==NULL){
        return -1;
    }
		
    fs=depth(root->node_fs);
	nb=depth(root->node_nb);
	if (fs > nb){
        return (fs+1);
    } else{
        return (nb+1);
    }
}



// Function untuk menghitung generasi dari anggota keluarga
// author: Alya Naila Putri Ashadilla
// I.S. : generasi dari anggota keluarga belum diketahui 
// F.S. : generasi dari anggota keluarga diketahui
int countGenerations(address root, infotype name) {
    // Jika root kosong, maka generasi tidak terdefinisi
    if (root == NULL) {
        printf("Tree is empty.\n");
        return 0;
    } else {
        address node = search(root, name);
        if (node == NULL) {
            printf("Person with name '%s' not found.\n", name);
            return 0;
        }  else {
            // Hitung kedalaman dari akar pohon
            int treeDepth = depth(root);

            // Hitung kedalaman dari node yang dicari
            int nodeDepth = depth(node);

            // Generasi adalah selisih antara kedalaman akar pohon dan kedalaman node
            return treeDepth - nodeDepth;
        }
    }
}

// Function untuk menghitung anggota keluarga yang masih hidup
// author: Alya Naila Putri Ashadilla
// I.S. : anggota keluarga yang masih hidup belum diketahui 
// F.S. : anggota keluarga yang masih hidup sudah diketahui
int countLivingFamilyMembers(address node) {
    int count = 0;
    if (node == NULL){ // Jika node kosong, maka akan mengembalikan nilai 0
        return 0;
    } else if(node->info.alive == true){ //jika status hidup node bersifat true maka nilai count akan bertambah
        count++;
    }

    //Menghitung jumlah anggota keluarga hidup pada node pasangan, anak, dan saudara
    count +=countLivingFamilyMembers(node->node_mate);
    count +=countLivingFamilyMembers(node->node_fs);
    count +=countLivingFamilyMembers(node->node_nb);

    return count;
}

// Fungsi untuk memprediksi pewaris takhta selanjutnya dari suatu node
// author: Alya
// I.S : nama pewaris takhta belum diketahui
// F.S : nama pewaris takhta telah diketahui
address successorPrediction(address root, infotype name) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return root;
    }

    // Cari node dengan nama yang sesuai
    address current = search(root, name);;

    if (current == NULL) {
        printf("Person with name '%s' not found.\n", name); 
    }else {
        // Lakukan prediksi berdasarkan aturan penurunan tahta
        // Jika memiliki anak dan masih hidup, pewaris tahta adalah anak pertama yang masih hidup
        if ((current->node_fs != NULL) && (current->node_fs->info.alive == true)) {
            return current->node_fs;
        }

        // Jika tidak memiliki anak tapi memiliki saudara, pewaris tahta adalah saudara pertama yang masih hidup
        if (current->node_nb != NULL) {
            address temp = current->node_nb;
            while (temp != NULL && temp->info.alive != true) {
                temp = temp->node_nb;
            }
            if (temp != NULL) {
                return temp;
            }
        }

        // Cari pewaris tahta di antara saudara-saudara orang tua
        if (current->node_parrent != NULL && current->node_parrent->node_nb != NULL) {
            address temp = current->node_parrent->node_nb;
            while (temp != NULL && temp->info.alive != true) {
                temp = temp->node_nb;
            }
            if (temp != NULL) {
                    return temp;
            }

        }

        //Jika tidak ada saudara dari orang tua, cari pewaris tahta dari anak saudara orang tua
       if (current->node_parrent != NULL && current->node_parrent->node_nb != NULL) { 
            if(current->node_parrent->node_nb != current && current->node_parrent->node_nb->node_fs != NULL){
                address temp = current->node_parrent->node_nb;
                successorPrediction(temp, temp->info.nama);
            }
        }

        // Jika tidak ada sepupu, perlu untuk memeriksa di atas
        if (current->node_parrent != NULL && current->node_parrent->node_parrent != NULL && current->node_parrent->node_parrent->node_nb != NULL) {
            successorPrediction(current->node_parrent->node_parrent->node_nb, current->node_parrent->node_parrent->node_nb->info.nama);
        }
        
        // Jika tidak ada pewaris tahta yang sesuai, maka tidak ada prediksi yang bisa dibuat.
        printf("No predicted heir found for %s.\n", name);
        return NULL;
    }
}

// Fungsi untuk membuat seseorang menjadi raja
// author: Alya
// I.S : nama raja/ratu belum diketahui
// F.S : nama raja/ratu telah diketahui
address nextKing(address root, infotype name){
    if (root == NULL) {
        printf("Tree is empty.\n");
        return NULL;
    }

    // Cari node dengan nama yang sesuai
    address current = search(root, name);
    
    if(current->info.alive == true){
        return current;
    } else {
        successorPrediction(root, name);
    }
}

// Fungsi untuk elakukan dealokasi / pengembalian address P ke system
// author: Alya Naila Putri Ashadilla
// referensi: modul pa Ade 
// IS : P terdefinisi 
// FS : P dikembalikan ke sistem 
void deAlokasi (address P){
	 if (P != NULL){
        P=NULL;
	    free (P);
     }    
}

// Fungsi untuk menghapus salah satu anggota keluarga kerajaan berserta keturunannya
// author: Alya Naila Putri Ashadilla
// I.S : anggota keluarga beserta keturunannya masih ada dalam silsilah kerajaan inggris
// F.S : salah satu anggota keluarga beserta keturunannya sudah terhapus dari silsilah kerajaan inggris
void deleteNodeWithDescendants(telm_familly **root, char *name) {
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

    
