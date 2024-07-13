#include <iostream>

using namespace std;

class Node {
 public:
  int key;
  Node* left;
  Node* right;

  Node(int key) {
    this->key = key;
    this->left = NULL;
    this->right = NULL;
  }
};

class BST {
 private:
  Node* root;

  void insertNode(Node*& node, int key) {
    if (node == NULL) {
      node = new Node(key);
      return;
    }

    if (key < node->key) {
      insertNode(node->left, key);
    } else if (key > node->key) {
      insertNode(node->right, key);
    }
  }

  Node* searchNode(Node* node, int key) {
    if (node == NULL) return NULL;
    if (node->key == key) return node;
    return key < node->key ? searchNode(node->left, key)
                           : searchNode(node->right, key);
  }

  Node* findMin(Node* node) {
    while (node->left != NULL) {
      node = node->left;
    }

    return node;
  }

  Node* deleteNode(Node*& node, int key) {
    if (node == NULL) {
      return node;
    }

    if (key < node->key) {
      node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
      node->right = deleteNode(node->right, key);
    } else {
      if (node->left == NULL) {
        Node* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == NULL) {
        Node* temp = node->left;
        delete node;
        return temp;
      }

      Node* temp = findMin(node->right);
      node->key = temp->key;
      node->right = deleteNode(node->right, temp->key);
    }

    return node;
  }

  void inorderTraversal(Node* node) {
    if (node == NULL) return;
    inorderTraversal(node->left);
    cout << node->key << " ";
    inorderTraversal(node->right);
  }

  void preorderTraversal(Node* node) {
    if (node == NULL) return;
    cout << node->key << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
  }

  void postorderTraversal(Node* node) {
    if (node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->key << " ";
  }

  void displayBST(Node* node, int space) {
    if (node == NULL) {
      return;
    }

    space += 5;
    displayBST(node->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) {
      cout << " ";
    }
    cout << node->key << "\n";

    displayBST(node->left, space);
  }

 public:
  BST() { this->root = NULL; }

  void insert(int key) { insertNode(this->root, key); }

  Node* search(int key) { return searchNode(this->root, key); }

  void remove(int key) { deleteNode(this->root, key); }

  void inorder() {
    inorderTraversal(this->root);
    cout << endl;
  }

  void preorder() {
    preorderTraversal(this->root);
    cout << endl;
  }

  void postorder() {
    postorderTraversal(this->root);
    cout << endl;
  }

  void display() { displayBST(this->root, 0); }
};

int main() {
  BST bst;
  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);

  cout << "Inorder traversal: ";
  bst.inorder();

  cout << "Preorder traversal: ";
  bst.preorder();

  cout << "Postorder traversal: ";
  bst.postorder();

  cout << "Displaying BST:\n";
  bst.display();

  Node* searchedNode = bst.search(60);
  if (searchedNode == NULL) {
    cout << "Node not found in the BST\n";
  } else {
    cout << "Node found in the BST: " << searchedNode->key << endl;
  }

  bst.remove(30);

  cout << "Inorder traversal after deleting a node: ";
  bst.inorder();

  return 0;
}
