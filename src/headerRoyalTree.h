#ifndef HEADER_ROYAL_TREE_H
#define HEADER_ROYAL_TREE_H
/***************************/
/*  	  Type data        */
/***************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include "BOOLEAN.H"

#define Unknown_name "SESEORANG"
#define Unknown_gender ' '
#define MAX_NAME_LENGTH 100
#define MAX_LINE_LENGTH 256
#define Root(P) P.root
typedef struct telm_familly *address;
typedef char infotype;

// data dari informasi person
typedef struct dataInfo
{
    char nama[MAX_NAME_LENGTH];
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
    address node_parrent;
} telm_familly;

// pointer of root
typedef struct telm_root
{
    address root;
} telm_root;


// Procedure and function prototypes

// Prosedur initiasi root
// author : Ais Laksana
// I.S : root belum diinisialisasi
// F.S : root sudah diinisialisasi
void init_Root(telm_root *L);

// Prosedur untuk membuat semua char pada array of Char menjadi Uppercase
// ref : https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case, GPT 
// author : Ais Laksana
// I.S : parameter array of char belum diubah
// F.S : parameter array of char sudah diubah menjadi uppercase
void string_to_uppercase(char *str);

// Fungsi meng input data info unknown
// author : Ais Laksana
dataInfo ket_unknown();

// Fungsi meng input data info berdasar parameter
// author : Ais Laksana
// I.S : (dataInfo) belum ada
// F.S : fungsi mereturn (dataInfo) berdasar parameter
dataInfo ket_available(infotype nama[MAX_NAME_LENGTH], int age, char gender);

// Fungsi meng input data info yang diinput user
// author : Ais Laksana
// I.S : (dataInfo) belum ada
// F.S : fungsi mereturn (dataInfo) yang sudah diinput user
dataInfo ket_input();

// Fungsi alokasi node module
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node yang sudah di alokasi dengan datainfo sesuai dengan parameter
address alok_pointer(dataInfo _info);

// Fungsi alokasi node dengan datainfo unknown
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node sudah di alokasi dengan (datainfo) unknown
address alok_unknown_pers();

// Fungsi alokasi node dengan input parameter
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node sudah di alokasi berdasar input parameter
address alok_available_pers(infotype name[MAX_NAME_LENGTH], int age, char gender);

// Fungsi alokasi node dengan input user
// author : Ais Laksana
// I.S : node belum di alokasi
// F.S : fungsi mereturn node sudah di alokasi berdasar input user
address alok_input_pers();

// Prosedur print (dataInfo) module
// author : Ais Laksana
// I.S : dataInfo belum di print
// F.S : dataInfo sudah di print
void print_datainfo(dataInfo X);

// pointer allocation module

// birth module
// Prosedur memberikan suatu node dengan anak yang tidak diketahui
// author : Ais Laksana
// I.S : (X->node_fs) atau (X->node_fs->node_nb) pada suatu node masih NULL
// F.S : (X->node_fs) atau (X->node_fs->node_nb) menunjuk pada node dengan (ket_unknown()) pada (dataInfo)
void point_birth_unknown(telm_familly *X);

// Prosedur memberikan suatu node, anak dengan (dataInfo) dari paramerter
// author : Ais Laksana
// I.S : (X->node_fs) atau (X->node_fs->node_nb) pada suatu node masih NULL
// F.S : (X->node_fs) atau (X->node_fs->node_nb) menunjuk pada node dengan (dataInfo) sesuai dengan parameter
void point_birth_available(telm_familly *X, infotype nama[MAX_NAME_LENGTH], int age, char gender);

// Prosedur memberikan suatu node dengan anak yang diinput user
// author : Ais Laksana
// I.S : (X->node_fs) atau (X->node_fs->node_nb) pada suatu node masih NUL
// F.S : (X->node_fs) atau (X->node_fs->node_nb) menunjuk pada node yang diinput user
void point_birth_input(telm_familly *X);

// marriage module
// menikahkan node dengan node yang tidak diketahui
// author : Ais Laksana
// I.S : (X->node_mate) pada suatu node masih NULL
// F.S : (X->node_mate) menunjuk pada node dengan (ket_unknown()) pada (dataInfo) dan sebaliknya
void point_marriage_unknown(telm_familly *X);

// Prosedur menikahkan node dengan node yang pada parameter
// author : Ais Laksana
// I.S : (X->node_mate) pada suatu node masih NULL
// F.S : (X->node_mate) menunjuk pada node (telm_familly Y) dan sebaliknya
void point_marriage_available(telm_familly *X, infotype nama[MAX_NAME_LENGTH], int age, char gender);

// Prosedur untuk menikahkan node dengan node yang diinput user
// author : Ais Laksana
// I.S : (X->node_mate) pada suatu node masih NULL
// F.S : (X->node_mate) menunjuk pada node yang diinput user dan sebaliknya
void point_marriage_input(telm_familly *X);

// Prosedur untuk mengubah status hidup node
// author : Ais Laksana
// I.S : status hidup pada (dataInfo) node belum diubah
// F.S : status hidup pada (dataInfo) node belum diubah
void point_kill(telm_familly *X);

// Fungsi yang mereturn nama yang di cari
// author : Daffa Muzhafar & Ais Laksan
// I.S : node belum di cari
// F.S : node yang dicari ditemukan dan di return fungsi
address search(address node, infotype name[MAX_NAME_LENGTH]);

// Prosedur untuk mencetak pohon secara rekursif dengan pre order
// author : Daffa Muzhafar & Ais Laksana
// I.S : Tree belum tercetak
// F.S : Tree tercetak dengan garis silsilah tiap generasi
void printTree(address root, int level);

// Prosedur untuk melakukan traversal secara pre-order
// author: Daffa Muzhafar & Ais Laksana
// I.S. : Tree belum dicetak secara pre-order
// F.S. : Tree dicetak secara pre-order
void trav_pre_order(address root);

// prosedur untuk menulis ulang data pada format string dalam file
// author : Ais Laksana
// I.S : file belum di tulis
// F.S : file sudah di tulis
void serialize_Node(FILE *file, address node, boolean isRoot);

// Prosedur untuk menghandle serialize node
// author : Ais Laksana
// I.S : file belum disimpan
// F.S : file sudah disimpan
void save_Tree_To_File(const char *filename, telm_root *familyTree);

void tambah_anggota(address root);

// Procedure to perform marriage
void nikahkan(address root);

// Procedure to display information about a person
void tampilkan_informasi(address root);

// Procedure to perform killing
void membunuh(address root);

address insert_king(telm_root *L);

void make_tree(telm_root *familyTree);



// Function untuk menghitung anggota keluarga yang masih hidup
// author: Alya Naila Putri Ashadilla
// I.S. : anggota keluarga yang masih hidup belum diketahui 
// F.S. : anggota keluarga yang masih hidup sudah diketahui
int countLivingFamilyMembers(address node);

// Fungsi untuk memprediksi pewaris takhta selanjutnya dari suatu node
// author: Alya
// I.S : nama pewaris takhta belum diketahui
// F.S : nama pewaris takhta telah diketahui
void successorPrediction(address root, infotype name[MAX_NAME_LENGTH]);

// Function untuk menghitung generasi dari anggota keluarga
// author: Alya Naila Putri Ashadilla
// I.S. : generasi dari anggota keluarga belum diketahui 
// F.S. : generasi dari anggota keluarga diketahui
int depth(address node);

// Function untuk menghitung generasi dari anggota keluarga
// author: Alya Naila Putri Ashadilla
// I.S. : generasi dari anggota keluarga belum diketahui 
// F.S. : generasi dari anggota keluarga diketahui
int countGenerations(address root, infotype name[MAX_NAME_LENGTH]);

// Fungsi untuk menghapus salah satu anggota keluarga kerajaan berserta keturunannya
// author: Alya Naila Putri Ashadilla
// I.S : anggota keluarga beserta keturunannya masih ada dalam silsilah kerajaan inggris
// F.S : salah satu anggota keluarga beserta keturunannya sudah terhapus dari silsilah kerajaan inggris
void deleteNodeWithDescendants(telm_familly **root, infotype name[MAX_NAME_LENGTH]);

void cek_king(address *current);


address createNode(dataInfo info);

void addMember(telm_root *tree, dataInfo info, char* parentName, char* mateName, char* firstSonName, char* nextSiblingName);

void loadDataFromFile(const char* filename, telm_root *tree);

void printFromFile(const char* location);

void timeskip(address root, int year);

void timeskip_input(address root);





#endif