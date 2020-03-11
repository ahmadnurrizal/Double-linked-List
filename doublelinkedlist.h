#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info


using namespace std;


typedef int infotype;
typedef struct elmtList *address;
struct elmtList {
    infotype info;
    address next;
    address prev;
};
struct list {
    address first;
    address last;
};

bool isEmpty(list L);

void createList(list &L);

void createNewElmt (infotype X,address &P);

void insertFirst (list &L, address P);

void insertAfter (list &L, address &prec,address &P);

void insertLast (list &L, address &P);

void deleteFirst (list &L, address &P);

void deleteAfter (list &L, address prec, address &P);

void deleteLast (list &L, address &P);

void concat (list L1,list L2, list &L3);

float median (list L);

void showList(list L);
address searching(list L,infotype X);

#endif // DOUBLELINKEDLIST_H_INCLUDED
