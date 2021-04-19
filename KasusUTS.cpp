#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

using namespace std;

int linkedList = 0;

struct Node {
    char name[255];
    Node *next,*prev;
}*head,*tail;

Node *createNode(const char name[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void pusHead(const char name[]);
void pushTail(const char name[]);
void pushMid(const char name[], int search);
void push();
void popNode();
void printLinked();
void editNode();
void sortAscending();
void sortDescending();
void mainMenu();

int main() {
    int option;
    do {
        system("cls");
        mainMenu();
        cin >> option;
        switch(option) {
            case 1:
                push();
                break;
            case 2:
                popNode();
                break;
            case 3:
                editNode();
                break;
            case 4:
                sortAscending();
                break;
            case 5:
                sortDescending();
                break;
            case 0:
                cout << "Terimakasih sudah menggunakan aplikasi ini...." << endl;
                system("pause");
                exit(0);
                break;
            default:
                cout << "Menu tidak ada dipilihan silahkan ulangi";
        }
    } while(option != 0);
    return 0;
}

void mainMenu() {
    cout << "==============================================="<< endl;
    cout << "                   KASUS UTS" << endl;
    cout << "===============================================" << endl;
    cout << endl;
    cout << "Data yang ada dalam Linked List : " << endl;
    if(linkedList == 0 && !head) {
        cout << "Data saat ini masih kosong\n" << endl;
    } else {
        printLinked();
        cout << endl;
    }
    cout << "------------------------" << endl;
    cout << "|Menu :                |" << endl;
    cout << "|1. Insert Node        |\n"
            "|2. Delete Node        |\n"
            "|3. Edit Node          |\n"
            "|4. Sorting Ascending  |\n"
            "|5. Sorting Descending |\n"
            "|0. Exit               |\n";
    cout << "------------------------" << endl;
    cout << "Masukan pilihan anda" << endl;
    cout << ">> ";
}

void pushHead(const char name[]) {
    Node *temp = createNode(name);
    if(!head) {
        head = tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    linkedList++;
    cout << "Data berhasil dimasukan pada node awal....." << endl;
    system("pause");
}

void pushTail(const char name[]) {
    Node *temp = createNode(name);
    if(!head) {
        head = tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    linkedList++;
    cout << "Data berhasil dimasukan node akhir....." << endl;
    system("pause");
}

void pushMid(const char name[], int search) {
    Node *temp = createNode(name);
    if(!head) {
        head = tail = temp;
    } else {
        Node *curr = head;
        int position = 1;
        while(position != search) {
            curr = curr->next;
            position++;
        }
        curr->prev->next = temp;
        temp->prev = curr->prev;
        temp->next = curr;
        curr->prev = temp;
    }
    linkedList++;
    cout << "Data berhasil diinsertkan pada node ke-" << search << "....." << endl;
    system("pause");
}

void push() {
    int option,search;
    char name[255];
    cout << "-----------------\n"
            "|1. Insert Head |\n"
            "|2. Insert Tail |\n"
            "|3. Insert Mid  |\n"
            "-----------------" << endl;
    cout << ">> ";
    cin >> option;
    cout << "Masukan Data ke-" << linkedList+1 << endl;
    cout << ">> ";
    cin >> name;
    switch(option) {
        case 1:
            pushHead(name);
            break;
        case 2:
            pushTail(name);
            break;
        case 3:
            cout << "Data akan diinsertkan pada node ke :" << endl;
            cout << ">> ";
            cin >> search;
            if(search < 0 || search > linkedList + 1) {
                cout << "Node tidak tersedia..." << endl;
                break;
            }
            pushMid(name, search);
            break;
    }
}

void popHead() {
    if(!head) {
        return;
    } else if(head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        Node *newHead = head->next;
        head->next = newHead->prev = NULL;
        free(head);
        head = newHead;
    }
    linkedList--;
}

void popTail() {
    if(!head) {
        return;
    } else if(head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        Node *newTail = tail->prev;
        tail->prev = newTail->next = NULL;
        free(tail);
        tail = newTail;
    }
    linkedList--;
}

void popNode() {
    char del[255];
    cout << "Masukan data yang ingin dihapus" << endl;
    cout << ">> ";
    cin >> del;
    if(!head) {
        return;
    } else if(strcmp(head->name,del) == 0) {
        popHead();
        cout << "Data bernama " << del << " berhasil dihapus pada node pertama..." << endl;
    } else if(strcmp(tail->name,del) == 0) {
        popTail();
        cout << "Data bernama " << del << " berhasil dihapus pada node terakhir..." << endl;
    } else {
        Node *curr = head;
        bool valid = false;
        int position = 1;
        while(curr) {
            if(strcmp(curr->name,del) == 0) {
                valid = true;
                break;
            }
            curr = curr->next;
            position++;
        } 
        if(valid) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->prev = curr->next = NULL;
            free(curr);
            curr = NULL;
            linkedList--;
            cout << "Data bernama " << del << " berhasil dihapus pada node ke-" << position << endl;
        } else {
            cout << "Data tidak ditemukan....." << endl;
        }
    }
    system("pause");
}

void printLinked() {
    Node *curr = head;
    while(curr) {
        cout << curr->name << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void editNode() {
    char edit[255];
    char search[255];
    cout << "Masukan data yang akan di edit" << endl;
    cout << ">> ";
    cin >> search;
    if(!head) {
        return;
    } else if(strcmp(head->name,search) == 0) {
        cout << "Masukan data yang baru" << endl;
        cout << ">> ";
        cin >> edit;
        strcpy(head->name,edit); 
        cout << "Data " << search << " Berhasil diganti dengan data " << edit << " pada node pertama..." << endl;
    } else if(strcmp(tail->name,search) == 0) {
        cout << "Masukan data yang baru" << endl;
        cout << ">> ";
        cin >> edit;
        strcpy(tail->name,edit);
        cout << "Data " << search << " Berhasil diganti dengan data " << edit << " pada node terakhir..." << endl;
    } else {
        Node *curr = head;
        bool valid = false;
        int position = 1;
        while(curr) {
            if(strcmp(curr->name,search) == 0) {
                valid = true;
                break;
            }
            position++;
            curr = curr->next;
        }
        if(valid) {
            cout << "Masukan Data yang baru" << endl;
            cout << ">> ";
            cin >> edit;
            strcpy(curr->name,edit);
            cout << "Data " << search << "Berhasil diganti dengan data " << edit << "pada node ke-" << position << endl;
        } else {
            cout << "Data tidak ditemukan........" << endl;
        }
    }
    system("pause");
}

void sortAscending() {
    if(!head) {
        return;
    }
    Node *curr = head, *index = NULL;
    char temp[255];
    do {
        index = curr->next;
        while(index != NULL) {
            if(strcmp(curr->name,index->name) > 0) {
                strcpy(temp,curr->name);
                strcpy(curr->name,index->name);
                strcpy(index->name,temp);
            }
            index = index->next;
        }
        curr = curr->next;
    } while(curr->next != NULL);
    cout << "Data berhasil disorting secara ascending...." << endl;
    system("pause");
}

void sortDescending() {
    if(!head) {
        return;
    }
    Node *curr = head, *index = NULL;
    char temp[255];
    do {
        index = curr->next;
        while(index != NULL) {
            if(strcmp(curr->name,index->name) < 0) {
                strcpy(temp,curr->name);
                strcpy(curr->name,index->name);
                strcpy(index->name,temp);
            }
            index = index->next;
        }
        curr = curr->next;
    } while(curr->next != NULL);
    cout << "Data berhasil disorting secara descemdimg...." << endl;
    system("pause");
}
