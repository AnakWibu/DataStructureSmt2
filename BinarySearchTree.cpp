#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
  int value;
  Node *left, *right;
};

Node *createNode(int value) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *insertNode(Node *root, int value) {
  if(!root) { 
    return createNode(value);
  } else if(value < root->value) {
    root->left = insertNode(root->left, value);
  } else if(value > root->value) { 
    root->right = insertNode(root->right, value);
  }

  return root;
}

Node *inOrderSucessor(Node *root) { 
  Node *curr = root->right; 
  while(curr && curr->left) { 
    curr = curr->left; 
  }
  return curr;
}

Node *deleteNode(Node *root, int value) {
  if(!root) { 
    return root;
  } else if(value < root->value) { 
    root->left = deleteNode(root->left, value);
  } else if(value > root->value) { 
    root->right = deleteNode(root->right, value);
  } else {
    if(!root->left || !root->right) { 
      Node *newRoot = root->left ? root->left : root->right;
      root->left = root->right = NULL;
      free(root); 
      root = NULL;
      return newRoot;
    }
    Node *newRoot = inOrderSucessor(root);
    root->value = newRoot->value; 
    root->right = deleteNode(root->right, newRoot->value); 
  }
  return root;
}

bool searchNode(Node *root, int key) {
  if(root) {
    if(root->value == key) {
      return true;
    } else if(key < root->value) {
      return searchNode(root->left, key); 
    } else if(key > root->value) {
      return searchNode(root->right, key);
    }
  }

  return false;
}

void preOrder(Node *root) {
  if(root) {
    cout << root->value << " -> ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(Node *root) {
  if(root) {
    inOrder(root->left);
    cout << root->value << " -> ";
    inOrder(root->right);
  }
}

void postOrder(Node *root) {
  if(root) {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " -> ";
  }
}

void menu(Node *baseRoot) {
    cout << "==============================================================\n"
            "                   Tugas Binary Search Tree\n"
            "==============================================================" << endl;
    cout << "Inorder BST :" << endl;
    if(!baseRoot) {
      cout << "Data saat ini masih kosong" << endl;
    } else {
      inOrder(baseRoot);
      cout << "NULL";
      puts("");
    }
    cout << "Menu\n"
            "1. Input Data\n"
            "2. Hapus Data\n"
            "3. Pre Order\n"
            "4. Post Order\n"
            "5. Exit\n" 
            ">> ";
}

int main() {
  Node *baseRoot = NULL;
  int option, value;
  do {
    system("cls");
    menu(baseRoot);
    cin >> option;
    switch(option) {
        case 1:
          cout << "Masukan data yang akan di-input\n"
                  ">> ";
          cin >> value;
          baseRoot = insertNode(baseRoot, value);
          cout << "Data telah berhasil diinput......\n";
          system("pause");
          break;
        case 2:
          cout << "Masukan data yang akan dihapus\n"
                  ">> ";
          cin >> value;
          baseRoot = deleteNode(baseRoot, value);
          cout << "Data telah berhasil dihapus.......\n";
          system("pause");
          break;
        case 3: 
          cout << "Pre Order : ";
          preOrder(baseRoot);
          cout << "NULL";
          puts("");
          system("pause");
          break;
        case 4:
          cout << "Post Order : ";
          postOrder(baseRoot);
          cout << "NULL";
          puts("");
          system("pause");
          break;
        case 5:
          exit(0);
          break;
    }
  } while(option >=1 && option <= 4);
  return 0;
}
