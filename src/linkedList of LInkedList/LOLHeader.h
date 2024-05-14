#define LOLHEADER_H

#include <stdio.h>
#include <stdlib.h>

// Define infotype as int for demonstration
typedef char* infotype;

// Define a structure for a node in the inner linked list
typedef struct InnerNode {
    infotype info;
    struct InnerNode *next;
} InnerNode;

// Define a structure for the inner linked list
typedef struct InnerList {
    InnerNode *Front;
} InnerList;

// Define a structure for a node in the outer linked list
typedef struct OuterNode {
    infotype info;
    InnerList point;
    struct OuterNode *next;
} OuterNode;

// Define a structure for the outer linked list
typedef struct OuterList {
    OuterNode *head;
    OuterNode *tail;
} OuterList;


void initInnerList(InnerList *L);

void addInnerNode(OuterList *city_list, infotype _city, infotype data);

void initOuterList(OuterList *L);

void addOuterNode(OuterList *L, infotype _info);

void showInnerList(InnerList L);

void showOuterList(OuterList L);

void changeCity(OuterList L, infotype _info, infotype change);

OuterNode* searchOuter(OuterList L, infotype _info);

InnerNode* searchInner(InnerList List, InnerNode** prev, infotype _info);

void del_inner_name(OuterList *L, infotype _city, infotype _name);

void del_inner_rear(OuterList *L, infotype _city);

void del_inner_front(OuterList *L, infotype _city);

void changePerson(OuterList *L, infotype _info, infotype _nameinfo, infotype name);
