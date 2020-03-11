#include "doublelinkedlist.h"

bool isEmpty(list L) {
    return first(L)==NULL && last(L)==NULL;

}

void createList(list &L) {
    first(L)=NULL;
    last(L)=NULL;
}

void createNewElmt(infotype X,address &P){
    P=new elmtList;
    info(P)=X;
    next(P)=NULL;
    prev(P)=NULL;
}


void insertFirst (list &L, address P){
    if (isEmpty(L)) {
        first(L)=P;
        last(L)=P;
    } else {
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertAfter (list &L, address &prec,address &P){
    if (next(prec)==NULL) {
        insertLast(L,P);
    } else {
        next(P)=next(prec);
        prev(next(prec))=P;
        next(prec)=P;
        prev(P)=prec;
    }
}

void insertLast (list &L, address &P){
    if (isEmpty(L)) {
        insertFirst(L,P);
    } else {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }

}

void deleteFirst (list &L, address &P){
    if (next(first(L))==NULL) {
        first(L)=NULL;
        last(L)=NULL;
    } else {
        P=first(L);
        first(L)=next(P);
        prev(first(L))=NULL;
        next(P)=NULL;
    }
}

void deleteAfter (list &L, address prec, address &P){
    if (next(next(prec))==NULL) {
        deleteLast(L,P);
    } else {
        if (prev(prec)==NULL) {
            deleteFirst(L,P);
        } else {
            prev(next(prec))=prev(prec);
            next(prev(prec))=next(prec);
            next(prec)=NULL;
            prev(prec)=NULL;
        }
    }
}

void deleteLast (list &L, address &P){
    last(L)=prev(last(L));
    prev(next(last(L)))=NULL;
    next(last(L))=NULL;
}

void concat (list L1,list L2, list &L3){
    next(last(L1))=first(L2);
    prev(first(L2))=last(L1);
    last(L1)=NULL;
    first(L2)=NULL;
    first(L3)=first(L1);
    last(L3)=last(L2);
    first(L1)=NULL;
    last(L2)=NULL;
}

void showList(list L){
    address Q=first(L);
    if (next(first(L))==NULL) {
        cout<<info(Q)<<" ";
    } else {
        while (Q!=NULL) {
        cout<<info(Q)<<" ";
        Q=next(Q);
        }
    }
}

address searching(list L,infotype X) {
    address Q=first(L);
    while (info(Q)!=X && Q!=NULL) {
        Q=next(Q);
    }
    return Q;

}

float median(list L){
    int total = 0;
    address P = first(L);
    while (P != NULL) {
        total = total + 1;
        P = next(P);
    }
    P = first(L);
    int i = 1;
    float x;
    if (total%2 == 0){
        while (i <= total/2){
            i = i + 1;
            P = next(P);
        }
        x = float(info(P) + info(prev(P)))/2.0f;
        return x;
    } else {
        while (i <= total/2){
            i = i + 1;
            P = next(P);
        }
        return float(info(P))*1.0f;
    }

}
