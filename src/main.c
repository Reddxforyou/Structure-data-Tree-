#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "BOOLEAN.H"
#define Unknown_name "Keluarga kerajaan"
#define Unknown_gender ' '
#define Root(P) P.root
typedef struct telm_familly *address;
typedef char *infotype;

int choice;

// data dari informasi person
typedef struct dataInfo
{
    char nama[100];
    int age;
    char gender;
    boolean alive;
} dataInfo;

// node person dalam silsilah
typedef struct telm_familly
{
    dataInfo info;
    address node_mate;
    address node_fs;
    address node_nb;
    address node_ayah;
    address node_ibu;
} telm_familly;

// pointer of root
typedef struct telm_root
{
    address root;
} telm_root;

// initiasi root
void init_Root(telm_root *L)
{
    L->root = NULL;
}

// keterangan data module
// data info module
// meng input data info unknown
dataInfo ket_unknown()
{
    dataInfo ket;
    strcpy(ket.nama, Unknown_name);
    ket.age = 0;
    ket.gender = Unknown_gender;
    ket.alive = true;
    return ket;
}

// meng input data info yang diketahui programer
dataInfo ket_available(infotype nama, int age, char gender)
{
    dataInfo person;
    gender = toupper(gender);
    if (gender != 'L' && gender != 'P')
    {
        printf("your gender is not available\n");
        return ket_unknown();
    }

    strcpy(person.nama, nama);
    person.age = age;
    person.gender = gender;
    person.alive = true;
    return person;
}

// meng input data info yang diinput user
dataInfo ket_input()
{
    dataInfo person;
    char gender;
    printf("Masukkan nama : ");
    scanf("%s", person.nama);
    printf("Masukkan umur : ");
    scanf("%d", &person.age);	
    do
    {
        printf("Gender : ");
        scanf(" %c", &gender);
        gender = toupper(gender);
    } while (gender != 'L' && gender != 'P');

    person.gender = gender;
    person = ket_available(person.nama, person.age, person.gender);
    return person;
}

// alokasi node module
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
    P->node_ayah = NULL;
    P->node_ibu = NULL;
    return P;
}

// alokasi node dengan datainfo unknown
address alok_unknown_pers()
{
    dataInfo person = ket_unknown();
    return alok_pointer(person);
}

// alokasi node dengan input programer
address alok_available_pers(infotype name, int age, char gender)
{
    dataInfo person = ket_available(name, age, gender);
    return alok_pointer(person);
}

// alokasi node dengan input user
address alok_input_pers()
{
    dataInfo person = ket_input();
    return alok_pointer(person);
}

// print data module
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
// memberikan suatu node dengan anak yang tidak diketahui
void point_birth_unknown(telm_familly *X)
{
    address node = alok_unknown_pers();

    X->node_fs = node;
}

// memberikan suatu node dengan anak yang diketahui programer
void point_birth_available(telm_familly *X, infotype nama, int age, char gender)
{
    address node = alok_available_pers(nama, age, gender);
    if (X->node_fs == NULL)
    {
        X->node_fs = node;
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

// memberikan suatu node dengan anak yang diinput user
void point_birth_input(telm_familly *X)
{
    address node;
    do
    {
        if (X->node_fs != NULL)
        {
            address current = X->node_fs;
            int curr_age = current->info.age;
            while (current->node_nb != NULL)
            {
                if (curr_age > current->node_nb->info.age)
                {
                    curr_age = current->node_nb->info.age;
                }
                current = current->node_nb;
            }
            node = alok_input_pers();
            if (X->node_fs != NULL && node->info.age > curr_age)
            {
                system("cls");
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
    if (X->info.gender == 'L')
    {
        node->node_ayah = X;
        node->node_ibu = X->node_mate;
    }
    else if (X->info.gender == 'P')
    {
        node->node_ayah = X->node_mate;
        node->node_ibu = X;
    }
    else
    {
        node->node_ayah = X->node_mate;
        node->node_ibu = X->node_mate;
    } 
}

// marriage module
// menikahkan node dengan node yang tidak diketahui
void point_marriage_unknown(telm_familly *X)
{
    address node = alok_unknown_pers();
    if (X->node_mate == NULL)
    {
        X->node_mate = node;
    }
}

// menikahkan node dengan node yang diketahui programer
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

// menikahkan node dengan node yang diinput user
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

// mengubah status hidup node
void point_kill(telm_familly *X)
{
    X->info.alive = false;
}

// belum beres module search orang nya
void search(infotype name){
    
}

// Fungsi untuk mencetak pohon secara rekursif
void printTree(address root, int level) {
    if (root == NULL) return;
    int i;
    for (i = 0; i < level; i++) {
        printf("	|");
    }
    printf("%s\n", root->info.nama);
    printTree(root->node_fs, level + 1);
    printTree(root->node_nb, level);
}

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
        printf("\n\t\t\t\t\t\t|                1. Tambahkan Node              |");
        printf("\n\t\t\t\t\t\t|                2. Aturan Kerajaab             |");
        printf("\n\t\t\t\t\t\t|                3.                             |");
        printf("\n\t\t\t\t\t\t|                0. Keluar                      |");
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
            break;
        case 3:
            break;
        case 0:
            printf("\t\t\t\t\t\tTerima kasih telah bermain!\n");
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

int main() {
    system("Color 0B");

    // Panggil fungsi gameStart saat program dimulai
    gameStart();

    return 0;
}
