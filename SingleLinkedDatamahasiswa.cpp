#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Node {
    int value;
    char name[255];
    int age;
    float height;
    float weight;
    Node *next;
}*head,*tail;

Node *createNode(int value, const char name[], int age, float height, float weight) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    strcpy(newNode->name,name);
    newNode->age = age;
    newNode->height = height;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int value, const char name[], int age, float height, float weight) {
    Node *temp = createNode(value,name,age,height,weight);
    if(!head) {
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void pushTail(int  value, const char name[], int age, float height, float weight) {
    Node *temp = createNode(value,name,age,height,weight);
    if(!head) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void pushMidAfter(int value, const char name[], int age, float height, float weight,int search) {
    Node *temp = createNode(value,name,age,height,weight);
    if(!head) {
        cout << "List Kosong" << endl;
    } else {
        Node *curr = head;
        while(curr->value != search) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void pushMidBefore(int value, const char name[], int age, float height, float weight,int search) {
    Node *temp = createNode(value,name,age,height,weight);
    if(!head) {
        cout << "List Kosong" << endl;
        return;
    } else {
        Node *curr = head;
        while(curr->next->value != search) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void popHead() {
    if(!head) {
        cout << "List Kosong" << endl;
        return;
    } else if(head == tail) { 
        free(head); 
        head = tail = NULL; 
    } else {
        Node *newHead = head->next;
        head->next = NULL;
        free(head);
        head = newHead;
    }
}

void popTail() {
   if(!head) {
        cout << "List Kosong" << endl;
        return;
    } else if(head == tail) { 
        free(head);
        head = tail = NULL; 
    }else {
        Node *curr = head;
        while(curr->next != tail) {
            curr = curr->next;
        }
        curr->next = NULL;
        free(tail);
        tail = curr;

    }
}

void popMid(int search) {
    if(!head) {
        cout << "List Kosong" << endl;
        return;
    } else if(head->value == search) {
        popHead();
    } else if(tail->value == search) {
        popTail();
    } else {
        Node *curr = head;
        while(curr->next->value != search) {
            curr = curr->next;
        }
        Node *erased = curr->next;
        curr->next = curr->next->next;
        erased->next = NULL;
        free(erased);
    }
}

void printLinkedList() {
    Node *curr = head;
    while(curr) {
        cout << curr->value << "/" << curr->name << "/"; 
        cout << curr->age << "/" << curr->height << "/";
        cout << curr->weight << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void mainMenu() {
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu :\n"
            "1. Input data\n"
            "2. Hapus data\n"
            "3. Edit data\n"
            "4. Cari data\n"
            "5. Cetak Data\n"
            "6. Exit" << endl;
    cout << "Masukan pilihan Anda : ";
}

void inputData();
void hapusData();
void editData();
void cariData();

int main() {
    system("cls");
    mainMenu();
    int option;
    cin >> option;
    switch(option) {
        case 1:
            inputData();
            break;
        case 2:
            hapusData();
            break;
        case 3:
            editData();
            break;
        case 4:
            cariData();
            break;
        case 5:
            cout << "Data yang ada dalam linked list adalah" << endl;
            printLinkedList();
            system("pause");
            main();
            break;
        case 6:
            exit(0);
            break;
    }
    return 0;
}

void inputData() {
    ulangi:
    system("cls");
    char name[255];
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu :" << endl;
    cout << "1. Sisip Depan\n"
            "2. Sisip Tengah Setelah Angka Tertentu\n"
            "3. Sisip Tengah Sebelum Angka Tertentu\n"
            "4. Sisip Belakang" << endl;
    int option;
    cout << "Masukan Pilihan Anda : "; 
    cin >> option;
    int value,search,age;
    float height,weight;
    cout << "Masukan NIM : "; cin >> value;
    cout << "Masukan Nama : "; cin >> name;
    cout << "Masukan Umur : "; cin >> age; 
    cout << "Masukan Tinggi : "; cin >> height;
    cout << "Masukan Berat Badan : "; cin>> weight;
    switch(option) {
        case 1:
            pushHead(value,name,age,height,weight);
            break;
        case 2:
            cout << "Letakan data sedudah NIM : "; cin >> search;
            pushMidAfter(value,name,age,height,weight,search);
            break;
        case 3:
            cout << "Letakan data sebelum NIM : "; cin >> search;
            pushMidBefore(value,name,age,height,weight,search);
            break;
        case 4:
            pushTail(value,name,age,height,weight);
            break;
    }
    char valid;
    cout << "Kembali ke menu?(y/n)" << endl;
    getchar();
    cout << ">> "; cin >> valid;
    if(valid =='y' || valid == 'Y') {
        main();
    } else {
        goto ulangi;
    }
}

void hapusData() {
    ulangi:
    system("cls");
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    int search;
    cout << "Masukan NIM yang ingin dihapus : "; cin >> search;
    popMid(search);
    char valid;
    cout << "Kembali ke menu?(y/n)" << endl;
    getchar();
    cout << ">> "; cin >> valid;
    if(valid == 'y' || valid == 'Y') {
        main();
    } else {
        goto ulangi;
    }
}

void editData() {
    ulangi:
    system("cls");
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    int search;
    cout << "Masukan NIM yang ingin diedit : "; cin >> search;
    Node *curr = head;
    while(curr->value != search) {
        curr = curr->next;
    }
    int option;
    cout << "Menu :\n"
            "1. Ganti NIM\n"
            "2. Ganti Nama\n"
            "3. Perbarui Umur\n"
            "4. Perbarui Tinggi dan Berat Badan" << endl;
    cout << "Masukan pilihan : "; cin >> option;
    switch(option) {
        case 1:
            cout << "Masukan NIM yang baru : "; cin >> curr->value;
            break;
        case 2:
            cout << "Masukan Nama yang baru : "; cin >> curr->name;
            break;
        case 3:
            cout << "Masukan Umur sekarang : "; cin >> curr->age;
            break;
        case 4:
            cout << "Masukan Tinggi sekarang :"; cin >> curr->height;
            cout << "Masukan Berat sekarang : "; cin >> curr->weight;
            break;
    }
    char valid;
    cout << "Kembali ke menu?(y/n)" << endl;
    getchar();
    cout << ">> "; cin >> valid;
    if(valid == 'y' || valid == 'Y') {
        main();
    } else {
        goto ulangi;
    }
}

void cariData() {
    ulangi:
    system("cls");
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    int search;
    cout << "Masukan NIM yang ingin dicari : "; cin >> search;
    Node *curr = head;
    while(curr->value != search) {
        curr=curr->next;
    }
    cout << "NIM : " << curr->value << endl;
    cout << "Nama : "  << curr->name << endl;
    cout << "Umur : " << curr->age << " tahun" << endl;
    cout << "Tinggi : " << curr->height << " cm" << endl;
    cout << "Berat : " << curr->weight << " kg" << endl;
    char valid;
    cout << "Kembali ke menu?(y/n)" << endl;
    getchar();
    cout << ">> "; cin >> valid;
    if(valid == 'y' || valid == 'Y') {
        main();
    } else {
        goto ulangi;
    }
}