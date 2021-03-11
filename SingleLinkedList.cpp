#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
}*head,*tail;

Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int value) {
    Node *temp = createNode(value);
    if(!head) {
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void pushTail(int value) {
    Node *temp = createNode(value);
    if(!head) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void pushMidAfter(int value, int search) {
    Node *temp = createNode(value);
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

void pushMidBefore(int value, int search) {
    Node *temp = createNode(value);
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
        cout << curr->value << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

void printTotalLinked() {
    Node *curr = head;
    int total= 0,n = 0;
    while(curr) {
        total += curr->value;
        n++;
        curr = curr->next;
    }
    cout << "Totalnya adalah : " << total << endl;
    cout << "Rata-ratanya adalah : " << (float)total/n << endl;
}

/*int main() {
    int arr[] = {12,13,16,17,21,22,25,28,31,10,41};
    for(int i=0;i<11;i++) {
        pushTail(arr[i]);
    }
    cout << "======== A ========" << endl;
    printLinkedList();
    getchar();
    //sisipkan 6,8 didepan
    int value;
    pushHead(6);
    pushHead(8);
    cout << "======== B ========" << endl;
    printLinkedList();
    getchar();
    cout << "======== C ========" << endl;
    pushMidAfter(18,17);
    pushMidBefore(19,21);
    printLinkedList();
    getchar();
    cout << "======== D ========" << endl;
    pushTail(44);
    printLinkedList();
    printTotalLinked();
    getchar();
    cout << "======== E ========" << endl;
    popHead();
    popHead();
    printLinkedList();
    getchar();
    cout << "======== F ========" << endl;
    popMid(25);
    popMid(28);
    printLinkedList();
    getchar();
    cout << "======== G ========" << endl;
    popTail();
    popTail();
    printLinkedList();
    getchar();
    return 0;
}*/

void mainMenu() {
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu :\n"
            "1. Input data\n"
            "2. Hapus data\n"
            "3. Cetak Data\n"
            "4. Exit" << endl;
    cout << "Masukan pilihan Anda : ";
}

void inputData();
void hapusData();

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
            cout << "Data yang ada dalam linked list adalah" << endl;
            printLinkedList();
            system("pause");
            main();
            break;
        case 4:
            exit(0);
            break;
    }
    return 0;
}

void inputData() {
    ulangi:
    system("cls");
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu :" << endl;
    cout << "1. Sisip Depan\n"
            "2. Sisip Tengah Setelah Angka Tertentu\n"
            "3. Sisip Tengah Sebelum Angka Tertentu\n"
            "4. Sisip Belakang" << endl;
    int option,value,search;
    cout << "Masukan Pilihan Anda : "; 
    cin >> option;
    switch(option) {
        case 1:
            cout << "Masukan Data : "; cin >> value;
            pushHead(value);
            break;
        case 2:
            cout << "Masukan Data : "; cin >> value;
            cout << "Letakan data setelah angka : "; cin >> search;
            pushMidAfter(value,search);
            break;
        case 3:
            cout << "Masukan Data : "; cin >> value;
            cout << "Letakan data sebelum angka : "; cin >> search;
            pushMidBefore(value,search);
            break;
        case 4:
            cout << "Masukan Data : "; cin >> value;
            pushTail(value);
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
    cout << "Menu :" << endl;
    cout << "1. Hapus Depan\n"
            "2. Hapus Tengah\n"
            "3. Hapus Belakang" << endl;
    cout << "Masukan Pilihan Anda : "; 
    int option, search;
    cin >> option;
    switch(option) {
        case 1:
            popHead();
            break;
        case 2:
            cout << "Masukan Data yang ingin dihapus : "; 
            cin >> search;
            popMid(search);
            break;
        case 3:
            popTail();
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