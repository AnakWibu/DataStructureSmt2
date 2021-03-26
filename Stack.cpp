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

int main() {
    // pushStack("Chaaerul");
    // pushStack("Hamdan");
    // pushStack("Lawak");
    // pushStack("Lo");
    // pushStack("Badut");
    // printStack();
    // getchar();
    // removeStack();
    // printStack();
    // getchar();
    // editStack("Lo");
    // printStack();
    // getchar();
    // sortAscending();
    // printStack();
    // getchar();
    // sortDescending();
    // printStack();
    // getchar();
    // cout << stack << endl;
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
    cout << "Apakah Anda akan menghapus Data Bernama " << top->name << " ?" << endl;
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
        curr = curr->next;
        if(strcmp(curr->name,name)==0) {
            flag = 1;
            break;
        }
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
    Node *curr = top;
    puts("Stack: ");
    while(curr) {
        cout << curr->name << endl;
        curr = curr->next;
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
}