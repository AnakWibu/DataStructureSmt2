#include <iostream>
#include <stdlib.h>

using namespace std;
  
struct Node{  
    int value;  
    Node *next;  
}*head,*tail;  

Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = newNode;
    return newNode;
}
void push(int value) {  
    Node *temp = createNode(value);
    if(!head){  
        head = tail = temp;  
        temp->next = head;  
    } else {  
        tail->next = temp;
        tail = temp;  
        tail->next = head;  
    }     
}  

void sortAscending() {  
    Node *curr = head, *index = NULL;  
    int temp;  
    if(!head) {  
        cout << "Node Kosong" << endl;  
    } else {  
        do{  
            index = curr->next;  
            while(index != head) {  
                if(curr->value > index->value) {  
                    temp =curr->value;  
                    curr->value= index->value;  
                    index->value = temp;  
                }  
                index= index->next;  
            }  
            curr =curr->next;  
        }while(curr->next != head);   
    }  
}  

void sortDescending() {  
    Node *curr = head, *index = NULL;  
    int temp;  
    if(!head) {  
        cout << "Node Kosong" << endl;  
    } else {  
        do{  
            index = curr->next;  
            while(index != head) {  
                if(curr->value < index->value) {  
                    temp =curr->value;  
                    curr->value= index->value;  
                    index->value = temp;  
                }  
                index= index->next;  
            }  
            curr =curr->next;  
        }while(curr->next != head);   
    }  
}  

void printLinked() {  
    Node *curr = head;  
    if(!head){  
        cout << "Node Kosong...." << endl;
    }  
    else{  
        do{  
            if(curr->next == head) {
                cout << curr->value;
            } else {
                cout << curr->value << " -> ";
            }
            curr = curr->next;  
         }while(curr != head);  
        cout << endl;
    }  
}  

void printTotal() {  
    Node *curr = head; 
    int total = 0, n = 0; 
    if(!head){  
        cout << "Node Kosong...." << endl;
    }  
    else{  
        do{  
            total = curr->value;
            n++;
            curr = curr->next;  
         }while(curr != head);  
        cout << "Jumlah nilai seluruhnya : " << total << endl;
        cout << "Nilai rata rata nilainya : " << (float)total/n << endl;
    }  
}  
      
int main()  
{  
   int n;
   cout << "enter the no of nodes" << endl; cin >> n;
   int value;
   while(n--) {
       cout << "enter value of node" << endl;
       cin >> value;
       push(value);
   }
   cout << "sorted circularly singly link list" << endl;
   sortAscending();
   printLinked();   
   getchar();
   printTotal();
   getchar();
   cout << "Urutkan nilai descending : ";
   sortDescending();
   printLinked();
   getchar();
   cout << "Urutkan nilai ascending : ";
   sortAscending();
   printLinked();
   getchar(); 
     
   return 0;  
}  