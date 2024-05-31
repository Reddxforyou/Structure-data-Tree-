
#include "bodyRoyalTree.c"

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
    count +=count_all_member(node->node_mate);
    count +=count_all_member(node->node_fs);
    count +=count_all_member(node->node_nb);

    return count;
}

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

    do
    {
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
            cek_king(&King);
            getchar();
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
            printf("Anggota seluruh keluarga kerajaan adalah berjumlah : %d", count_all_member(Root(test)));
            printf("\n\tPress any key to continue . . . ");
            getch();
            break;
        case 9:
            printf("Anggota keluarga kerajaan yang masih hidup berjumlah : %d", countLivingFamilyMembers(Root(test)));
            printf("\n\tPress any key to continue . . . ");
            getch();
            break;
        case 10:
            menghitung_generasi(Root(test));
            break;
        case 11:
            jumlah_generasi_terakhir(Root(test));
            break;
        case 12:
            timeskip_input(Root(test));
            break;
        case 13:
            delete_input(Root(test));
            break;
        case 14:
            save_Tree_To_File("familyTree.txt", &test);
            break;
        case 0:
            printf("\t\t\t\t\t\tTerima kasih!\n");
            break;
        default:
            printf("\t\t\t\t\tPilihan tidak valid. Silakan pilih lagi.\n");
        }
        if (King == NULL || King->info.alive == false)
        {
            cek_king(&King);
        }
        printf("\t\t\t\t\t\tTekan Enter untuk melanjutkan :"); // Teks "tekan enter untuk melanjutkan"
        getchar();                                             // Mengambil karakter dari input (enter) untuk melanjutkan
    } while (choice != 0);

    return 0;
}
