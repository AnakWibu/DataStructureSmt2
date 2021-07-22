#include <iostream>
#define MAXSIZE 100

using namespace std;

int maxHeap[MAXSIZE];
int size = 0;

int parent(int pos) {
    if(pos == 0) {
        return 0;
    } else if(pos % 2 == 1) {
        return pos / 2;
    } else {
        return (pos / 2) - 1;
    }
}

void swap(int pos1 , int pos2) {
    int temp = maxHeap[pos1];
    maxHeap[pos1] = maxHeap[pos2];
    maxHeap[pos2] = temp;
}

void insertNode(int value) {
    maxHeap[size] = value;

    int pos = size;
    while(maxHeap[pos] > maxHeap[parent(pos)]) {
        swap(pos , parent(pos));
        pos = parent(pos);
    }
    size ++;
}

int leftChild(int pos) {
    return (pos * 2) + 1;
}

int rightChild(int pos) {
    return (pos * 2) + 2;
}

int deleteNode() {
    int maxValue = maxHeap[0];
    maxHeap[0] = maxHeap[size];
    size--;

    int pos = 0;
    while((maxHeap[pos] < maxHeap[leftChild(pos)] || maxHeap[pos] < maxHeap[rightChild(pos)]) && size > 1) {
        if(maxHeap[leftChild(pos)] > maxHeap[rightChild(pos)]) {
            swap(leftChild(pos) , pos);
            pos = leftChild(pos);
        } else {
            swap(rightChild(pos), pos);
            pos = rightChild(pos);
        }
    }
    return maxValue;
}

void printHeap() {
    for(int i = 0; i < size; i++) {
    cout << "maxHeap[" << i << "]: " << maxHeap[i] << endl;
    }
}

int getMax() {
    return maxHeap[0];
}

int main() {
    int arr[] = {35 ,31 ,22 ,10 ,44 ,19 ,27 ,40 ,26 ,33 ,8 ,42 ,15 ,49 ,36 ,53 ,47 ,51 };
    for(int i= 0; i<18; i++) {
        insertNode(arr[i]);
        printHeap();
        getchar();
    }
    for(int i = 0; i<3; i ++) {
        deleteNode();
        printHeap();
        getchar();
    }
    return 0;
}