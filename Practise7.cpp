#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* root, int x) {
        if (!root) 
            return new Node{x, nullptr, nullptr};

        if (x < root->data)
            root->left = insert(root->left, x);
        else if (x > root->data)
            root->right = insert(root->right, x);
        return root;
    }

    Node* findMin(Node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    Node* remove(Node* root, int x) {
        if (!root) 
            return nullptr;
            
        if (x < root->data)
            root->left = remove(root->left, x);
        else if (x > root->data)
            root->right = remove(root->right, x);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        return root;
    }

    void preorder(Node* root) {
        if (root) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    Node* search(Node* root, int x) {
        if (!root || root->data == x) return root;
        if (x < root->data)
            return search(root->left, x);
        return search(root->right, x);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int x) {
        root = insert(root, x);
    }

    void remove(int x) {
        root = remove(root, x);
    }

    Node* search(int x) {
        return search(root, x);
    }

    void display() {
        cout << "Inorder: ";
        inorder(root);
        cout << "\nPreorder: ";
        preorder(root);
        cout << "\nPostorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.display();

    bst.remove(50);
    bst.display();

    Node* found = bst.search(60);
    cout << (found ? "Found\n" : "Not Found\n");

    return 0;
}
