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

// Prosedur untuk mencetak pohon secara rekursif dengan pre order
// author : Daffa Muzhafar & Ais Laksana
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


// Fungsi yang menampilkan tampilan Awal
// author : Daffa Muzhafar 
// I.S : program kosong (Blank)
// F.S : Tampilan awal
void gameStart()
{   
    system("cls");
    printf("\n\n");
	printf("\n\t\t\t\t                                        _____________                          ");
	printf("\n\t\t\t\t                                       |'+.   |   .+'|                         ");
	printf("\n\t\t\t\t                                       |___'+.|.+'___|                         ");
	printf("\n\t\t\t\t                                       |   .+'|'+.   |                         ");
	printf("\n\t\t\t\t                                       |.+'___|___'+.|                         ");
	printf("\n\t\t\t\t                                       |                                       ");
	printf("\n\t\t\t\t                                       |                                       ");
	printf("\n\t\t\t\t                                      / \\                                      ");
	printf("\n\t\t\t\t                                     /   \\                                     ");
	printf("\n\t\t\t\t                                    /     \\                                    ");
	printf("\n\t\t\t\t                                   /       \\                                   ");
	printf("\n\t\t\t\t                                  /         \\                                  ");
	printf("\n\t\t\t\t                              __ /  __   __  \\ __                              "); 
	printf("\n\t\t\t\t                             |  |__|  |_|  |__|  |                             ");
	printf("\n\t\t\t\t                             \\                   /                             ");
	printf("\n\t\t\t\t                          /\\  \\                 /  /\\                          ");
	printf("\n\t\t\t\t                         /  \\  \\_______________/  /  \\                         ");
	printf("\n\t\t\t\t                        /    \\  |   _     _   |  /    \\                        ");
	printf("\n\t\t\t\t                       /      \\ |  |_|   |_|  | /      \\                       ");
	printf("\n\t\t\t\t                      /________\\|_____________|/________\\                      ");
	printf("\n\t\t\t\t                      |         |   _     _   |         |                      ");
	printf("\n\t\t\t\t                      |   __    |  |_|   |_|  |    __   |                      ");
	printf("\n\t\t\t\t                      |  |__|   |_____________|   |__|  |                      ");
	printf("\n\t\t\t\t               _   _  |_        |   _     _   |        _|  _   _               ");
	printf("\n\t\t\t\t              | |_| |_| |_______|  |_|   |_|  |_______| |_| |_| |              ");
	printf("\n\t\t\t\t              |    _    |    __ |  __     __  | __    |    _    |              ");
	printf("\n\t\t\t\t     _   _   _|   |_|   |   |  |__|  |___|  |__|  |   |   |_|   |_   _   _     ");
	printf("\n\t\t\t\t    | |_| |_| |         |   |   __           __   |   |         | |_| |_| |    ");
	printf("\n\t\t\t\t    |         |    _    |   |  |__|         |__|  |   |    _    |         |    ");
	printf("\n\t\t\t\t    |    _    |   |_|   |   |       _______       |   |   |_|   |    _    |    ");
	printf("\n\t\t\t\t    |   |_|   |         |   |      |   |   |      |   |         |   |_|   |    ");
	printf("\n\t\t\t\t    |         |         |   |      |  0|0  |      |   |         |         |    ");
	printf("\n\t\t\t\t____|_________|_________|___|______|___|___|______|___|_________|_________|____");
	printf("\n\t\t   _  _   __   __   _   __    ___   _    _     ___   ____     ___   ____    __   _____   _____   __   __   _");
	printf("\n\t\t  | |/ / |  | |  \\ | | |  \\  |   | | \\  / |   |   | |  __|   |   \\ | __ \\  |  | |_   _| |  _  | |  | |  \\ | |");
	printf("\n\t\t  |   /  |  | |   \\| | | _ \\ | | | |  \\/  |   | | | | |__    | | / | || /  |  |   | |   | |_| | |  | |   \\| |");
	printf("\n\t\t  |   \\  |  | | |\\   | |   / | | | | |\\/| |   | | | |  __|   | | \\ | |\\ \\  |  |   | |   |  _  | |  | | |\\   |");
	printf("\n\t\t  |_|\\_\\ |__| |_| \\__| |__/  |___| |_|  |_|   |___| |_|      |___/ |_| \\_\\ |__|   |_|   |_| |_| |__| |_| \\__|");
    printf("\n\n\t\t\t\t\t\t\t    Press Enter To Continue");
    getchar();     //Menunggu untuk menekan enter
    system("cls"); // Membersihkan layar terminal
    mainMenu();
}

void mainMenu()
{
    do
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\n\t\t\t\t\t\t_________________.===========.___________________");
        printf("\n\t\t\t\t\t\t|                |=MAIN MENU=|                  |");
        printf("\n\t\t\t\t\t\t|                '==========='                  |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                1. Testing                     |");
        printf("\n\t\t\t\t\t\t|                2. Aturan Kerajaan             |");
        printf("\n\t\t\t\t\t\t|                3. Tambah Anggota Kerajaan     |");
        printf("\n\t\t\t\t\t\t|                4. Tambah Pasangan             |");
        printf("\n\t\t\t\t\t\t|                5. Turunkan Raja               |");
        printf("\n\t\t\t\t\t\t|                6. Hapus Anggota Kerajaan      |");
        printf("\n\t\t\t\t\t\t|                7. Tampilkan Informasi Anggota |");
        printf("\n\t\t\t\t\t\t|                8. Tampilkan Penerus Tahta     |");
        printf("\n\t\t\t\t\t\t|                9. Tampilkan Jumlah Anggota    |");
	printf("\n\t\t\t\t\t\t|               10. Tampilkan Anggota Hidup     |");								        
        printf("\n\t\t\t\t\t\t|                0. Keluar                      |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|                                               |");
        printf("\n\t\t\t\t\t\t|_______________________________________________|");
        printf("\n\t\t\t\t\t\t\t\tPilih menu (0/1/2/3): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        	Start();
            break;
        case 2:
        	Aturan();
            break;
        case 3:
        	//Aturan();
            break;
        case 4:
        	//Aturan();
            break;
        case 5:
        	//Aturan();
            break;
        case 6:
        	//Aturan();
            break;
        case 7:
        	//Aturan();
            break;
        case 8:
        	//Aturan();
            break;
        case 9:
        	//Aturan();
            break;
        case 10:
        	//Aturan();
            break;        
        case 0:
            printf("\t\t\t\t\t\tTerima kasih!\n");
            break;
        default:
            printf("\t\t\t\t\tPilihan tidak valid. Silakan pilih lagi.\n");
        }
        printf("\t\t\t\t\t\tTekan Enter untuk melanjutkan :"); // Teks "tekan enter untuk melanjutkan"
        getchar();                                             // Mengambil karakter dari input (enter) untuk melanjutkan
        getchar();                                             // Untuk menunggu sampai pengguna menekan Enter
    } while (choice != 0);
}

void Start()
{
	telm_root test;
    init_Root(&test);
    Root(test) = alok_available_pers("Charles1", 60, 'L');
    point_marriage_input(Root(test));
    point_birth_input(Root(test));
    point_birth_input(Root(test));
    point_birth_input(Root(test));

    // Cetak struktur pohon
    printf("Silsilah Anggota Kerajaan:\n");
    printTree(Root(test), 0);
}

void Aturan(){
}

