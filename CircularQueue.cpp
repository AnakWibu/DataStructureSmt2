#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

struct Node {
    string nim;
    string name;
    int nilaiTugas;
    int nilaiQuiz;
    int nilaiUTS;
    int nilaiUAS;
    float nilaiAkhir;
    char nilaiHuruf;
    Node *next, *prev;
}*first,*last;

int queue = 0;

Node *createNode(string nim,string name,int nilaiTugas, int nilaiQuiz, int nilaiUTS, int nilaiUAS) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->nim = nim;
    newNode->name = name;
    newNode->nilaiTugas = nilaiTugas;
    newNode->nilaiQuiz = nilaiQuiz;
    newNode->nilaiUTS = nilaiUTS;
    newNode->nilaiUAS = nilaiUAS;
    float total = ((((float)nilaiTugas*10)/100) +
              (((float)nilaiQuiz*20)/100) +
              (((float)nilaiUTS*30)/100) +
              (((float)nilaiUAS*40)/100));
    newNode->nilaiAkhir = total;
    if(total > 85) {
        newNode->nilaiHuruf = 'A';
    } else if(total <= 85 && total > 70) {
        newNode->nilaiHuruf = 'B';
    } else if(total <= 75 && total > 50) {
        newNode->nilaiHuruf = 'C';
    } else if(total <= 50 && total > 40) {
        newNode->nilaiHuruf = 'D';
    } else {
        newNode->nilaiHuruf = 'E';
    }
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void pushQueue(string nim,string name,int nilaiTugas, int nilaiQuiz, int nilaiUTS, int nilaiUAS);
void removeQueue();
void updateNode(int search);
void printQueue();
void sortAscending();
void sortDescending();
void mainMenu();

int main() {
    int option;
    string nim;
    string name;
    int nilaiTugas;
    int nilaiQuiz;
    int nilaiUTS;
    int nilaiUAS;
    int search;
    do {
        system("cls");
        mainMenu();
        cin >> option;
        switch(option) {
            case 1:
                cout << "Masukan NIM Mahasiswa : ";
                cin >> nim;
                cout << "Masukan Nama Mahasiswa : ";
                cin >> name;
                cout << "Masukan Nilai Tugas Mahasiswa: ";
                cin >> nilaiTugas;
                cout << "Masukan Nilai Quiz : ";
                cin >> nilaiQuiz;
                cout << "Masukan Nilai UTS : ";
                cin >> nilaiUTS;
                cout << "Masukan Nilai UAS : ";
                cin >> nilaiUAS;
                pushQueue(nim,name,nilaiTugas,nilaiQuiz,nilaiUTS,nilaiUAS);
                cout << "Data Berhasil Ditambahkan......" << endl;
                system("pause");
                break;
            case 2:
                removeQueue();
                cout << "Data Pertama Berhasil Dihapus....." << endl;
                system("pause");
                break;
            case 3:
                cout << "Masukan Node Data yang akan di Update/Edit : "; 
                cin >> search;
                if(search < 0 || search > queue) {
                    cout << "Node Tidak Ada.....";
                } else {
                    updateNode(search);
                } 
                system("pause");
                break;
            case 4:
                printQueue();
                system("pause");
                break;
            case 5:
                sortAscending();
                cout << "Sorting Nilai Secara Ascending Berhasil....";
                system("pause");
                break;
            case 6:
                sortDescending();
                cout << "Sorting Nilai Secara Descending Berhasil.....";
                system("pause");
                break;
            case 7:
                exit(0);
                break;
        }
    }while(option >= 1 || option <= 7);
    return 0;
}

void mainMenu() {
    cout << "=============================== QUEUEU ==================================\n";
    cout << "menu" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Ubah Data" << endl;
    cout << "4. Laporan Data Mahasiswa" << endl;
    cout << "5. Sorting Nilai Ascending" << endl;
    cout << "6. sorting Nilai Descending" << endl;
    cout << "7. Exit" << endl;
    cout<<"Enter your choice : ";
}

void pushQueue(string nim,string name,int nilaiTugas, int nilaiQuiz, int nilaiUTS, int nilaiUAS) {
    Node *temp = createNode(nim,name,nilaiTugas,nilaiQuiz,nilaiUTS,nilaiUAS);
    if(!first) {
        first = last = temp;
    } else {
        last->next = temp;
        temp->prev = last;
        last = temp;
        last->next = first;
        first->prev = last;
    }
    queue++;
}

void removeQueue() {
    if(!first) {
        return;
    } else if(first == last) { 
        free(first); 
        first = last = NULL; 
    } else { 
        Node *newFirst = first->next;
        first->next = newFirst->prev = NULL;
        free(first);
        first = newFirst;
        first->prev = last;
        last->next = first;
    } 
    queue--;
}

void updateNode(int search) {
    if(!first) {
        cout << "Node Kosong, Tidak Ada Yang Bisa Diupdate..." << endl;
        return;
    }
    int update;
    string nim;
    string name;
    int nilaiTugas;
    int nilaiQuiz;
    int nilaiUTS;
    int nilaiUAS;
    int markNIM = 0;
    int markName = 0;
    int markNilaiTugas = 0;
    int markNilaiQuiz = 0;
    int markNilaiUTS = 0;
    int markNilaiUAS = 0;
    cout << "Apakah NIM Akan di update ?\n Tekan 1 untuk mengganti\n>> ";
    cin >> update;
    if(update == 1) {
        cin >> nim;
        markNIM = 1;
    }
    cout << "Apakah Nama Akan di update ?\n Tekan 1 untuk mengganti\n>> ";
    cin >> update;
    if(update == 1) {
        cin >> name;
        markName = 1;
    }
    cout << "Apakah Nilai Tugas Akan di update ?\n Tekan 1 untuk mengganti\n>> ";
    cin >> update;
    if(update == 1) {
        cin >> nilaiTugas;
        markNilaiTugas = 1;
    }
    cout << "Apakah Nilai Quiz Akan di update ?\n Tekan 1 untuk mengganti\n>> ";
    cin >> update;
    if(update == 1) {
        cin >> nilaiQuiz;
        markNilaiQuiz = 1;
    }
    cout << "Apakah Nilai UTS Akan di update ?\n Tekan 1 untuk mengganti\n>> ";
    cin >> update;
    if(update == 1) {
        cin >> nilaiUTS;
        markNilaiUTS = 1;
    }
    cout << "Apakah Nilai UAS Akan di update ?\n Tekan 1 untuk mengganti\n>> ";
    cin >> update;
    if(update == 1) {
        cin >> nilaiUAS;
        markNilaiUAS = 1;
    }
    Node *curr = first;
    int position = 1;
    while(position !=search) {
        position++;
        curr = curr->next;
    }
    if(markNIM) {
        curr->nim = nim;
    } if(markName) {
        curr->name = name;
    } if(markNilaiTugas) {
        curr->nilaiTugas = nilaiTugas;
    } if(markNilaiQuiz) {
        curr->nilaiQuiz = nilaiQuiz;
    } if(markNilaiUTS) {
        curr->nilaiUTS = nilaiUTS;
    } if(markNilaiUAS) {
        curr->nilaiUAS = nilaiUAS;
    }
    float total = ((((float)nilaiTugas*10)/100) +
              (((float)nilaiQuiz*20)/100) +
              (((float)nilaiUTS*30)/100) +
              (((float)nilaiUAS*40)/100));
    curr->nilaiAkhir = total;
    if(total > 85) {
        curr->nilaiHuruf = 'A';
    } else if(total <= 85 && total > 70) {
        curr->nilaiHuruf = 'B';
    } else if(total <= 75 && total > 50) {
        curr->nilaiHuruf = 'C';
    } else if(total <= 50 && total > 40) {
        curr->nilaiHuruf = 'D';
    } else {
        curr->nilaiHuruf = 'E';
    }
    cout << "Data Telah Diupdate....." << endl;
}

void sortAscending() {  
    Node *curr = first, *index = NULL;  
    int temp;  
    string tmp;
    char tp;
    if(!first) {  
        cout << "Node Kosong" << endl;  
    } else {  
        do{  
            index = curr->next;  
            while(index != first) {  
                if(curr->nilaiAkhir > index->nilaiAkhir) {  
                    tmp = curr->nim;
                    curr->nim = index->nim;
                    index->nim = tmp;
                    tmp = curr->name;
                    curr->name = index->name;
                    index->name = tmp;
                    temp = curr->nilaiTugas;  
                    curr->nilaiTugas= index->nilaiTugas;  
                    index->nilaiTugas = temp; 
                    temp = curr->nilaiQuiz;  
                    curr->nilaiQuiz= index->nilaiQuiz;  
                    index->nilaiQuiz = temp; 
                    temp = curr->nilaiUTS;  
                    curr->nilaiUTS= index->nilaiUTS;  
                    index->nilaiUTS = temp; 
                    temp = curr->nilaiUAS;  
                    curr->nilaiUAS= index->nilaiUAS;  
                    index->nilaiUAS = temp; 
                    temp = curr->nilaiAkhir;  
                    curr->nilaiAkhir= index->nilaiAkhir;  
                    index->nilaiAkhir = temp;  
                    tp = curr->nilaiHuruf;
                    curr->nilaiHuruf = index->nilaiHuruf;
                    index->nilaiHuruf = tp;
                }  
                index= index->next;  
            }  
            curr =curr->next;  
        }while(curr->next != first);   
    }  
}  

void sortDescending() {  
    Node *curr = first, *index = NULL;  
    int temp;  \
    string tmp;
    char tp;
    if(!first) {  
        cout << "Node Kosong" << endl;  
    } else {  
        do{  
            index = curr->next;  
            while(index != first) {  
                if(curr->nilaiAkhir < index->nilaiAkhir) {  
                    tmp = curr->nim;
                    curr->nim = index->nim;
                    index->nim = tmp;
                    tmp = curr->name;
                    curr->name = index->name;
                    index->name = tmp;
                    temp = curr->nilaiTugas;  
                    curr->nilaiTugas= index->nilaiTugas;  
                    index->nilaiTugas = temp; 
                    temp = curr->nilaiQuiz;  
                    curr->nilaiQuiz= index->nilaiQuiz;  
                    index->nilaiQuiz = temp; 
                    temp = curr->nilaiUTS;  
                    curr->nilaiUTS= index->nilaiUTS;  
                    index->nilaiUTS = temp; 
                    temp = curr->nilaiUAS;  
                    curr->nilaiUAS= index->nilaiUAS;  
                    index->nilaiUAS = temp; 
                    temp = curr->nilaiAkhir;  
                    curr->nilaiAkhir= index->nilaiAkhir;  
                    index->nilaiAkhir = temp;  
                    tp = curr->nilaiHuruf;
                    curr->nilaiHuruf = index->nilaiHuruf;
                    index->nilaiHuruf = tp; 
                }  
                index= index->next;  
            }  
            curr =curr->next;  
        }while(curr->next != first);   
    }  
}  

void printQueue() {
    Node *curr = first;
    cout<<"======================================================================================\n";
    cout<<"No       NIM              Nama Mahasiswa                         NILAI                \n";
    cout<<"                                            __________________________________________\n"; 
    cout<<"                                            Tugas   Quiz    UTS     UAS   Akhir  Huruf\n";
    cout<<"======================================================================================\n";
    int nomer = 1;
    do {
        cout << nomer << setw(15) << curr->nim << setw(24) << curr->name << setw(9) << curr->nilaiTugas;
        cout << setw(7) << curr->nilaiQuiz << setw(7) << curr->nilaiUTS << setw(7) << curr->nilaiUAS;
        cout << setw(7) << curr->nilaiAkhir << setw(7) << curr->nilaiHuruf << endl;
        nomer++;
        curr = curr->next;
    } while(curr != first);
    cout << "======================================================================================" << endl;
}
