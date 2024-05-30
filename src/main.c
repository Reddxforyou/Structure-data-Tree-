
#include "bodyRoyalTree.c"


int main()
{
    system("Color 0B");
    telm_root test;
    init_Root(&test);
    loading_screen();
    start();
    int choice;
    int insert_choice;
    do
    {
        printf("1. New Tree\n2. Load Tree");
        printf("\nPilih : ");
        scanf("%d", &insert_choice);
        switch (insert_choice)
        {
        case 1:
            printf("1. Input data\n");
            printf("input data Root\n");
            test.root = alok_input_pers();
            break;
        case 2:
            loadDataFromFile("familyTree.txt", &test);
            printf("Data loaded\n");
            break;
        default:
            test.root = NULL;
            break;
        }
    } while (test.root == NULL);
    address King = insert_king(&test);

    do{
        system("cls");
        printFromFile("tampilan/menu.txt");
        printTree(Root(test), 0);
        print_king(King);
        printf("\n\t\t\t\t\t\t\tPilih menu (0/1/2/3): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Aturan();
            break;
        case 2:
            tambah_anak(Root(test));
            break;
        case 3:
            nikahkan(Root(test));
            break;
        case 4:
            //Aturan();
            break;
        case 5:
            membunuh(Root(test));
            break;
        case 6:
            tampilkan_informasi(Root(test));
            break;
        case 7:
            penerus(Root(test));
            break;
        case 8:
            //Aturan();
            break;
        case 9:
            printf("Anggota keluarga kerajaan yang masih hidup berjumlah : %d", countLivingFamilyMembers(Root(test)));
            break;
        case 10:
            menghitung_generasi(Root(test));
            break;
        case 11:
            jumlah_generasi_terakhir(Root(test));
        case 12:
            timeskip_input(Root(test));
        case 0:
            printf("\t\t\t\t\t\tTerima kasih!\n");
            break;
        default:
            printf("\t\t\t\t\tPilihan tidak valid. Silakan pilih lagi.\n");
        }
        printf("\t\t\t\t\t\tTekan Enter untuk melanjutkan :"); // Teks "tekan enter untuk melanjutkan"
        getchar();                                             // Mengambil karakter dari input (enter) untuk melanjutkan
    }while(choice != 0);

    return 0;
}
