#include <iostream>

using namespace std;

int Parent(int index) {
    return (index - 1) / 2;
}

int Level(int index) {
    int count = 1;
    while (index > 0) {
        index = Parent(index);
        count++;
    }
    return count;
}

void minHeap(int arr[], int n, int index) {
    if (index == 0) {
        return;
    }

    int parent = Parent(index);
    if (arr[index] < arr[parent]) {
        swap(arr[index], arr[parent]);
        minHeap(arr, n, parent);
    }
}

void maxHeap(int arr[], int n, int index) {
    if (index == 0) {
        return;
    }

    int parent = Parent(index);
    if (arr[index] > arr[parent]) {
        swap(arr[index], arr[parent]);
        maxHeap(arr, n, parent);
    }
}

void minMaxHeap(int arr[], int n, int index) {
    if (index == 0) {
        return;
    }

    int parent = Parent(index);
    int grandParent = Parent(parent);
    int level = Level(parent);

    if (level % 2 != 0) {
        // ganjil
        if (arr[index] < arr[parent]) {
            swap(arr[index], arr[parent]);
            minMaxHeap(arr, n, parent);
        } else if (grandParent != 0 && arr[index] > arr[grandParent]) {
            swap(arr[index], arr[grandParent]);
            minMaxHeap(arr, n, grandParent);
        }
    } else {
        // genap
        if (arr[index] > arr[parent]) {
            swap(arr[index], arr[parent]);
            minMaxHeap(arr, n, parent);
        } else if (arr[index] < arr[grandParent]) {
            swap(arr[index], arr[grandParent]);
            minMaxHeap(arr, n, grandParent);
        }
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int search(int arr[], int n, int del){
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == del)
            return i;
    return - 1;
}

int deleteHeap(int arr[], int n, int del){
    int position = search(arr, n, del); 
    if (position == - 1){
        return n;
    }
 
    int i;
    for (i = position; i < n - 1; i++)
        arr[i] = arr[i + 1];
 
    return n - 1;
}

void mainMenu(int arr[], int n) {
    cout << "==============================================\n"
            "                    HEAP\n"
            "==============================================\n";
    for (int i = 0; i < n; i++) {
     	minMaxHeap(arr, n, i);
    }
    cout << "Min Max Heap : ";
    if(n == 0) {
        cout << "Data saat ini masih kosong..." << endl;
        puts("");
    } else {
        printHeap(arr, n);
        puts("\n");
    }
    cout << "Menu : \n"
            "1. Insert Data\n"
            "2. Delete Data\n"
            "3. Min Heap\n"
            "4. Max Heap\n"
            "5. Exit\n"
            ">> ";
}

int main() {
    int option, del;
    int arr[100];
    int n = 0, i = 0;
    do {
        system("cls");
        mainMenu(arr, n);
        cin >> option;
        switch(option) {
            case 1: {
                cout << "Masukan Data yang akan diinput : ";
                cin >> arr[i];
                i++;
                n++;
                cout << "Data berhasil diinput" << endl;
                system("pause");
                break;
            }
            case 2: {
                cout << "Masukan Data yang akan dihapus : ";
                cin >> del;
                int temp = deleteHeap(arr, n, del);
                if(temp == n) {
                    cout << "Data tidak ditemukan...." << endl;
                    system("pause");
                } else {
                    n = temp;
                     cout << "Data berhasil dihapus";
                }
                break;
            }
            case 3: {
                for (int i = 0; i < n; i++) {
     	            minHeap(arr, n, i);
                }
                cout << "Min Heap : ";
                printHeap(arr, n);
                puts("");
                system("pause");
                break;
            }
            case 4: {
                for (int i = 0; i < n; i++) {
     	            maxHeap(arr, n, i);
                }
                cout << "Max Heap : ";
                printHeap(arr, n);
                puts("");
                system("pause");
                break;
            }
            case 5: {
                exit(0);
                break;
            }
        }
    } while(option >=1 && option <=5);
}
