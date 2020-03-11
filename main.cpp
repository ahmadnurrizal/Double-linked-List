#include "doublelinkedlist.h"

using namespace std;

int main()
{
    /*  Nama    : Wahid firgiyanto
        NIM     : 1301194287*/

    list L1,L2,L3;
    address Q,P,prec;

    createList(L1);
    createList(L2);
    createList(L3);

    int X;
    int i=1;

    cout<<"List 1 :\n";
    while (i<=3){
        cin>>X;
        createNewElmt(X,P);
        Q = first(L1);
        if (Q == NULL || info(Q) > X){
            insertFirst(L1, P);
        } else {
            while (next(Q) != NULL && info(next(Q)) < X){
                Q = next(Q);
            }
            if (next(Q) == NULL){
                insertLast(L1, P);
            } else {
                insertAfter(L1,Q, P);
            }
        }
        i++;
    }
    cout<<">>> Isi List 1: ";
    showList(L1);
    cout<<endl;

    i=1;
    cout<<"List 2 :\n";
    while (i<=4){
        cin>>X;
        createNewElmt(X,P);
        Q = first(L2);
        if (Q == NULL || info(Q) > X){
            insertFirst(L2, P);
        } else {
            while (next(Q) != NULL && info(next(Q)) < X){
                Q = next(Q);
            }
            if (next(Q) == NULL){
                insertLast(L2, P);
            } else {
                insertAfter(L2,Q, P);
            }
        }
        i++;
    }
    cout<<">>> Isi List 2: ";
    showList(L2);
    cout<<endl;
    cout<<endl;

    concat(L1,L2,L3);
    cout<<">>> Isi List 3: ";
    showList(L3);
    cout<<endl;
    cout<<endl;


    deleteFirst(L3,P);
    cout<<"Isi List 3: ";
    showList(L3);
    cout<<endl;
    cout<<endl;

    deleteLast(L3,P);
    cout<<"Isi List 3: ";
    showList(L3);
    cout<<endl;
    cout<<endl;

    cout<<"Pilih nomor untuk dihapus ? ";
    cin>>X;
    prec=searching(L3,X);
    deleteAfter(L3,prec,P);
    cout<<endl;

    cout<<"Isi List 3: ";
    showList(L3);

    cout<<endl;
    cout<<"Median : "<<median(L3);


    return 0;

}

