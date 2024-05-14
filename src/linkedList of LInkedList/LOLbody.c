#include "LOLHeader.h"

// Function to initialize an inner linked list
void initInnerList(InnerList *L) {
    L->Front = NULL;
}

// Function to add a node to the beginning of an inner linked list
void addInnerNode(OuterList *city_list, infotype _city, infotype data) {
    InnerNode *newNode = (InnerNode *)malloc(sizeof(InnerNode));
    newNode->next = NULL;
    newNode->info = data;
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    OuterNode *city = searchOuter(*city_list, _city);

    if (city->point.Front == NULL)
    {
        city->point.Front = newNode;
    }else{
        InnerNode *current = city->point.Front;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the elements of an inner linked list
void showInnerList(InnerList L) {
    InnerNode *current = L.Front;
    while (current != NULL) {
        printf(" -> %s ", current->info);
        current = current->next;
    }
    printf("\n");
}

// Function to initialize an outer linked list
void initOuterList(OuterList *L) {
    L->head = NULL;
    L->tail = NULL;
}

void del_inner_front(OuterList *L, infotype _city){
    OuterNode *current = searchOuter(*L, _city);
    InnerNode *pointer = current->point.Front;
    current->point.Front = current->point.Front->next;
    pointer->next = NULL;
    free(pointer);
}

void del_inner_rear(OuterList *L, infotype _city){
    OuterNode *current = searchOuter(*L, _city);
    
    InnerNode *pointer = current->point.Front;
    InnerNode *prev;
    while (pointer->next != NULL)
    {
        prev = pointer;
        pointer = pointer->next;
    }
    prev->next = NULL;
    free(pointer);
}


void del_inner_name(OuterList *L, infotype _city, infotype _name) {
    OuterNode *current = searchOuter(*L, _city);
    if (current == NULL) {
        printf("The city is not found\n");
        return ;
    }

    InnerNode *prev = NULL;
    InnerNode *pointer = searchInner(current->point, &prev, _name);
    if (pointer == NULL) {
        printf("The person is not found\n");
        return ;
    }

    // Update previous node's next pointer
    if (prev == NULL) {
        // If the node to be deleted is the first node
        current->point.Front = pointer->next;
    } else {
        prev->next = pointer->next;
    }

    // Free memory of the deleted node
    free(pointer);
}


InnerNode* searchInner(InnerList List, InnerNode** prev, infotype _info) {
    InnerNode *current = List.Front;
    while (current != NULL && current->info != _info) {
        *prev = current;
        current = current->next;
    }
    return current;
}



// Function to add a node to the beginning of the outer linked list
void addOuterNode(OuterList *L, infotype _info) {
    OuterNode *newNode = (OuterNode *)malloc(sizeof(OuterNode));
    newNode->info = _info;
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    initInnerList(&newNode->point); // Initialize the inner linked list
    if (L->head == NULL)
    {
        newNode->next = L->head;
        L->head = newNode;
        L->tail = L->head;
    }else{
        while (L->tail->next != NULL)
        {
            L->tail = L->tail->next;
        }
        L->tail->next = newNode;
        L->tail = newNode;
    }
}


// Function to display the elements of the outer linked list
void showOuterList(OuterList L) {
    OuterNode *current = L.head;
    while (current != NULL) {
        printf("%s ",current->info);
        showInnerList(current->point);
        current = current->next;
    }
}

// search outer traversal outer
OuterNode* searchOuter(OuterList List, infotype _info) {
    OuterNode *current = List.head;
    while (current != NULL && current->info != _info) {
        current = current->next;
    }
    return current;
}


