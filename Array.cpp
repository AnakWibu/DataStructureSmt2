#include <iostream>

using namespace std;

void pushHead(int arr[],int value) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    n++;
    for(int i=n-1;i>=0;i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = value;
}

void pushTail(int arr[],int value) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    arr[n] = value;
}

void pushMidBefore(int arr[], int value, int search) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    int index;
    for(int i=0;i<n;i++) {
        if(arr[i] == search) {
            index = i;
            break;
        }
    }
    n++;
    for(int i=n-1;i>=index;i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = value;
}

void pushMidAfter(int arr[], int value, int search) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    int index;
    for(int i=0;i<n;i++) {
        if(arr[i] == search) {
            index = i;
            break;
        }
    }
    n++;
    for(int i=n-1;i>=index+1;i--) {
        arr[i+1] = arr[i];
    }
    arr[index+1] = value;
}

void popHead(int arr[]) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    for(int i=0;i<n;i++) {
        arr[i] = arr[i+1];
    }
}

void popMid(int arr[], int search) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    int index;
    for(int i=0;i<n;i++) {
        if(arr[i] == search) {
            index = i;
        }
    }
    for(int i=index;i<n;i++) {
        arr[i] = arr[i+1];
    }
}

void popTail(int arr[]) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    for(int i = n-1; i<=n; i++) {
        arr[i] = arr[i+1];
    }
}

void printArray(int arr[]) {
    int n=0;
    while(arr[n]) {
        cout << arr[n] << " -> ";
        n++;
    }
    cout << "NULL" << endl;
}

void totalArray(int arr[]) {
    int n=0,total = 0;
    while(arr[n]) {
        total += arr[n];
        n++;
    }
    cout << "Totalnya adalah : " << total << endl;
    cout << "Rata-ratanya adalah : " << (float)total/n << endl;
}

void searchArray(int arr[], int search) {
    int n=0;
    while(arr[n]) {
        n++;
    }
    int index;
    for(int i=0;i<n;i++) {
        if(arr[i] == search) {
            index = i;
            break;
        }
    }
    cout << "Array " << arr[index] << " berada pada index " << index + 1 << endl;
} 

int main() {
    int arr[] = {12,13,16,17,21,22,25,28,31,10,41};
    printArray(arr);
    getchar();
    pushHead(arr, 6);
    pushHead(arr,8);
    printArray(arr);
    getchar();
    pushMidAfter(arr, 18, 17);
    pushMidBefore(arr,19,21);
    printArray(arr);
    getchar();
    pushTail(arr,44);
    printArray(arr);
    totalArray(arr);
    searchArray(arr,17);
    searchArray(arr,28);
    searchArray(arr,10);
    getchar();
    popHead(arr);
    popHead(arr);
    printArray(arr);
    getchar();
    popMid(arr,25);
    popMid(arr, 28);
    printArray(arr);
    getchar();
    popTail(arr);
    popTail(arr);
    printArray(arr);
    getchar();
    return 0;
}
