#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
  int key;
  Node *left, *right;
};

void insert(Node** root, int key);
void deleteTree(Node* root);
void insertBalanced(Node** root, int start, int end);

Node* createNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node* root = NULL;
    int newSize = 50000;
    //cout << "What is the size of the BST?\n";
    //cin >> newSize;
    vector<int> dataVector(newSize);
  
    //Filling data vector with random numbers

    //Uncomment this for average time complexity (random vector values):
    /*
    srand(static_cast<unsigned>(time(nullptr)));
    for (int &element : dataVector) {
      element = rand() % newSize;
      insert(&root, element);
    }*/

    //Uncomment this for worst case time complexity (increasing vector values and left-skewed binary tree):
    for (int i = 0; i < newSize; ++i) {
        insert(&root, i);
    }
  
      //Uncomment this for best case time complexity (balanced tree):
    //insertBalanced(&root, 0, newSize - 1);

  
    clock_t start = clock();
    deleteTree(root);
    clock_t stop = clock();
    double duration = (double)(stop - start)/CLOCKS_PER_SEC * 1000000;

    cout << "\nTime taken to iterate through a " << newSize << "-node BST: " << duration << " microseconds\n";

    return 0;
}

void insert(Node** root, int key) {
  if (*root == NULL)
    *root = createNode(key);
  else if (key < (*root)->key)
    insert(&((*root)->left), key);
  else
    insert(&((*root)->right), key);
}

void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void insertBalanced(Node** root, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        insert(root, mid);
        insertBalanced(root, start, mid - 1);
        insertBalanced(root, mid + 1, end);
    }
}