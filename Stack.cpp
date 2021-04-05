#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Node {
    char name[255];
    Node *next,*prev;
}*top;

int stack = 0;

Node *createNode(const char name[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void pushStack(const char name[]);
void removeStack();
void editStack(const char name[]);
void printStack();
void sortAscending();
void sortDescending();
void menu();

int main() {
    system("cls");
    int option;
    menu();
    cin >> option;
    char name[255];
    switch(option) {
        case 1:
            if(stack == 15) {
                cout << "Stack Penuh Tidak bisa menginput Data Lagi...." << endl;
                system("pause");
                main();
            }
            cout << "Masukan Data ke-" << stack+1 << " : "; cin >> name;
            pushStack(name);
            break;
        case 2:
            removeStack();
            break;
        case 3:
            cout << "Masukan Nama yang akan di Edit : "; cin >> name;
            editStack(name);
            break;
        case 4:
            sortAscending();
            break;
        case 5:
            sortDescending();
            break;
        default:
            exit(0);
            break;
    }
    return 0;
}

void menu() {
    cout << "       Program Stack Linked List       " << endl;
    cout << "=======================================" << endl;
    printStack();
    cout << "Menu." << endl;
    cout << "1. Tambah Data\n"
            "2. Hapus Data\n"
            "3. Edit Data\n"
            "4. Sorting Ascending\n"
            "5. Sorting Descending" << endl;
    cout << ">> ";
}

void pushStack(const char name[]) {
    Node *temp = createNode(name);
    if(!top) { 
        top = temp;
    } else { 
        top->prev = temp;
        temp->next = top;
        top = temp;
    }
    stack++;
    cout << "Data Berhasil Ditambahkan...." << endl;
    system("pause");
    main();
}

void removeStack() {
    char valid; 
    cout << "Apakah Anda akan menghapus Data ke-" << stack+1 <<  " Bernama " << top->name << " ?" << endl;
    cout << "Tekan Y/y untuk menghapus tekan selain itu untuk membatalkan\n" << ">> ";
    cin >> valid;
    if(valid == 'Y' || valid == 'y') {
        system("pause");
        main();
    }
    if(!top) { 
        return;
    } else if(top->next == NULL) { 
        free(top); 
        top = NULL;
    } else { 
        Node *newTop = top->next;
        top->next = newTop->prev = NULL;
        free(top);
        top = newTop;
    } 
    stack--;
    cout << "Data berhasil dihapus Dihapus" << endl;
    system("pause");
    main();
}

void editStack(const char name[]) {
    Node *curr = top;
    int flag = 0;
    while(curr) {
        if(strcmp(curr->name,name)==0) {
            flag = 1;
            break;
        }
        curr = curr->next;
    }
    if(flag) {
        char update[255];
        cout << "Masukan Data yang Baru untuk Mengganti " << curr->name << " : "; cin >> update;
        strcpy(curr->name,update);
        cout << "Data Berhasil Diganti......" << endl;
    } else {
        cout << "Data Tidak Ditemukan....." << endl;
        cout << "Silahkan ulangi." << endl;
    }
    system("pause");
    main();
}

void printStack() {
    if(!top) {
        cout << " Stack Kosong....." << endl;
    } else {
        Node *curr = top;
        puts("\n=================================\n");
        cout << "Maksimal Stack yang bisa ditampung = 15" << endl;
        puts("Stack: ");
        while(curr) {
            cout << curr->name << endl;
            curr = curr->next;
        }
        puts("\n=================================");
    }
}

void sortAscending() {
    Node *curr = top, *index = NULL;  
    char temp[255];  
    if(!top) {  
        cout << "Node Kosong" << endl;  
    } else {  
        do{  
            index = curr->next;  
            while(index != NULL) {  
                if(strcmp(curr->name,index->name) > 0) {  
                    strcpy(temp,curr->name);  
                    strcpy(curr->name,index->name);  
                    strcpy(index->name,temp);  
                }  
                index= index->next; 
            }  
            curr =curr->next;  
        }while(curr->next != NULL);   
    }  
    cout << "Data Berhasil di Sorting secara Ascending....." << endl;
    system("pause");
    main();
}

void sortDescending() {
    Node *curr = top, *index = NULL;  
    char temp[255];  
    if(!top) {  
        cout << "Node Kosong" << endl;  
    } else {  
        do{  
            index = curr->next;  
            while(index != NULL) {  
                if(strcmp(curr->name,index->name) < 0) {  
                    strcpy(temp,curr->name);  
                    strcpy(curr->name,index->name);  
                    strcpy(index->name,temp);  
                }  
                index = index->next; 
            }  
            curr =curr->next;  
        }while(curr->next != NULL);   
    }  
    cout << "Data Berhasil di Sorting secara Descending....." << endl;
    system("pause");
    main();
}