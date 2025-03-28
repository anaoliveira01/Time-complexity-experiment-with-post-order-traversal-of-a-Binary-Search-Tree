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
Node* createNode(int key);
void populateTree(Node** root, vector<int>& dataVector, int mode);

Node* createNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    int initialSize;
    int mode;
    cout << "What is the size of the BST?\n";
    cin >> initialSize;
  
    cout << "Choose mode: 1 - Random (Average Case Traversal), 2 - Left-Skewed (Worst Case Traversal), 3 - Balanced (Best Case Traversal): ";
    cin >> mode;
    
    if (mode < 1 || mode > 3) {
        cout << "Invalid mode selected. Defaulting to Random (Average Case Traversal).\n";
        mode = 1;
    }
    
    vector<int> sizes;
    vector<double> times;
        
    cout << "\nBST Size | Time Taken (microseconds)";
    cout << "\n------------------------------------";
    
    for (int i = 1; i <= 10; ++i) {
        int newSize = initialSize * i;
        sizes.push_back(newSize);
        
        Node* root = NULL;
        vector<int> dataVector(newSize);
        populateTree(&root, dataVector, mode);
        
        clock_t start = clock();
        deleteTree(root);
        clock_t stop = clock();
        double duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000;
        
        cout << "\n" << newSize << "\t | " << duration;
        times.push_back(duration);
    }
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

void populateTree(Node** root, vector<int>& dataVector, int mode){
    if (mode == 1){
        srand(static_cast<unsigned>(time(nullptr)));
        for (int &element : dataVector) {
            element = rand() % dataVector.size();
            insert(root, element);
        }
    } else if (mode == 2){
        for (int i=0; i<dataVector.size(); ++i){
            insert(root, i);
        }
    } else if (mode == 3){
        insertBalanced(root, 0, dataVector.size() - 1);
    }
        
}
