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

int main() {
    string nim;
    string name;
    cin >> nim;
    cin >> name;
    pushQueue(nim, name,100,100,100,100);
    printQueue();
    getchar();
}