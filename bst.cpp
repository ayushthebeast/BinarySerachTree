#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int data) {
        key = data;
        left = right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* search(Node* node, int key) {
        if (node == NULL || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* node, int key) {
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

    void inOrder(Node* node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->key << " ";
            inOrder(node->right);
        }
    }

    void preOrder(Node* node) {
        if (node != NULL) {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << " ";
        }
    }

public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* search(int key) {
        return search(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "InOrder traversal: ";
    bst.inOrder();

    cout << "PreOrder traversal: ";
    bst.preOrder();

    cout << "PostOrder traversal: ";
    bst.postOrder();

    cout << "\nDelete 20\n";
    bst.deleteNode(20);
    cout << "InOrder traversal: ";
    bst.inOrder();

    cout << "\nDelete 30\n";
    bst.deleteNode(30);
    cout << "InOrder traversal: ";
    bst.inOrder();

    cout << "\nDelete 50\n";
    bst.deleteNode(50);
    cout << "InOrder traversal: ";
    bst.inOrder();

    return 0;
}

