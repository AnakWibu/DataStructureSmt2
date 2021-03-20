#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    char data;
    Node *next;
    Node *prev;
}*head,*tail;

Node *createNode(char data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void pushHead(char data);
void pushTail(char data);
void pushAtPosition(char data, int search);
void popAtPosition(int search);
void updateNode(int search);
void searchNode(char data);
void printLinked();
void reverseLinked();

void menu() {
    cout<<"1.Insert at Beginning"<<endl; 
    cout<<"2.Insert at End"<<endl;
    cout<<"3.Insert at Position"<<endl;
    cout<<"4.Delete at Position"<<endl;
    cout<<"5.Update Node"<<endl;
    cout<<"6.Search Element"<<endl;
    cout<<"7.Display List"<<endl;
    cout<<"8.Reverse List"<<endl;
    cout<<"9.Exit"<<endl;
    cout<<"Enter your choice : ";
}

int main() {
    system("cls");
    int option;
    char data;
    int search;
    menu();
    cin >> option;
    switch(option) {
        case 1:
            cout << "Masukan Data yang Akan di push : "; cin >> data;
            pushHead(data);
            break;
        case 2:
            cout << "Masukan Data yang Akan di push : "; cin >> data;
            pushTail(data);
            break;
        case 3:
            cout << "Masukan Data yang Akan di Push : "; cin >> data;
            cout << "Masukan Posisi yang Akan diisi oleh Data : "; cin >> search;
            pushAtPosition(data,search);
            break;
        case 4:
            cout << "Masukan Posisi Data yang akan dihapus : "; cin >> search;
            popAtPosition(search);
            break;
        case 5:
            cout << "Masukan Posisi Data yang akan di Update : "; cin >> search;
            updateNode(search);
            break;
        case 6:
            cout << "Masukan Data yang ingin Anda cari : "; cin >> data;
            searchNode(data);
            break;
        case 7:
            cout << "Data yang tersedia dalam Node" << endl;
            printLinked();
            break;
        case 8:
            reverseLinked();
            break;
        default:
            exit(0);
    }
}

void pushHead(char data) {
    Node *temp = createNode(data);
    if(!head) {
        head = tail =  temp;
        head->next = tail->next = NULL;
        head->prev = tail->prev = NULL;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = tail;
        tail->next = head;
    }
    cout << "Data Tersisipkan" << endl;
    system("pause");
    main();
}

void pushTail(char data) {
    Node *temp = createNode(data);
    if(!head) {
        head = tail =temp;
        head->next = tail->next = NULL;
        head->prev = tail->prev = NULL;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        head->prev = tail;
        tail->next = head;
    }
    cout << "Data Tersisipkan" << endl;
    system("pause");
    main();
}

void pushAtPosition(char data, int search) {
    Node *temp = createNode(data);
    if(!head){
        if(search == 1) {
            head = tail = temp;
            head->next = tail->next = NULL;
            head->prev = tail->prev = NULL;
        }  else {
            cout << "List Kosong........" << endl;
            return;
        }
    } else {
        Node *curr = head;
        Node *ptr;
        int position = 1;
        while(position != search) {
            position ++;
            ptr = curr;
            curr = curr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
        temp->next = curr;
        curr->prev = temp;
    }
    cout << "Data Tersisipkan" << endl;
    system("pause");
    main();
}

void popHead() {
    Node *curr = head;
    tail->next = curr->next;
    curr->next->prev = tail;
    head = curr->next;
}

void popAtPosition(int search) {
    if(!head) {
        cout << "List Kosong........" << endl;
        return;
    } 
    if(search == 1) {
        popHead();
    } else {
        Node *curr = head;
        Node *temp = curr;
        int position = 1;
        while(position != search) {
            temp = curr;
            curr = curr->next;
            position++;
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        if(curr == tail) {
            tail = curr->prev;
        }
        free(curr);
    }
    cout << "Data Telah Dihapus....." << endl;
    system("pause");
    main();
}

void updateNode(int search) {
    if(!head) {
        cout << "Node Kosong, Tidak Ada Yang Bisa Diupdate..." << endl;
        return;
    }
    char update;
    cout << "Masukan Data yang Baru : ";
    cin >> update;
    Node *curr = head;
    if(search == 1) {
        curr->data = update;
    } else {
        int position = 1;
        while(position !=search) {
            position++;
            curr = curr->next;
        }
        curr->data = update;
    }
    cout << "Data Telah Diupdate....." << endl;
    system("pause");
    main();
}

void searchNode(char data) {
    if(!head) {
        cout << "Node Kosong, Tidak Ada Yang Bisa Ditemukan..." << endl;
        return;
    }
    Node *curr = head;
    int position = 1,flag = 0;
    while(curr->data != data) {
        curr = curr->next;
        position++;
    }
    cout << "Data : " << curr->data << " Ditemukan pada Node ke-" << position;
    cout << endl;
    system("pause");
    main();
}

void printLinked() {
    Node *curr = head;
    do {
        cout << curr->data << " <--> ";
        curr = curr->next;
    } while(curr->next != head);
    cout << curr->data << endl;
    system("pause");
    main();
}

void reverseLinked() {
    if(!head) {
        cout << "Node Kosong......" << endl;
        return;
    }
    Node *temp = head;
    Node *curr = temp->next;
    temp->next = NULL;
    temp->prev = curr;
    while(curr != head ) {
        curr->prev = curr->next;
        curr->next = temp;
        temp = curr;
        curr = curr->prev;
    }
    tail = head;
    head = temp;
    tail->next = head;
    head->prev = tail;
    cout << "Data Berhasil di Reverse...." << endl;
    system("pause");
    main();
}