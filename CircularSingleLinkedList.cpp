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

void sortedPush(int value) {
    Node *temp = createNode(value);
    Node *curr = head;
    if (!head) {
        head = tail = temp;
    } else if (curr->value >= temp->value) {
        while(curr->next != head) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
        head = temp;
    } else {
        while (curr->next!= head && curr->next->value < temp->value) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
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
            total += curr->value;
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
       sortedPush(value);
   }
   cout << "sorted circularly singly link list" << endl;
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
