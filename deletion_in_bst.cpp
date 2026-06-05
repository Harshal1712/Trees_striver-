#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

public:
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* helper(Node* root);
Node* findlastright(Node* root);

Node* deletion(Node* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return helper(root);

    Node* dummy = root;
    while (root != NULL) {
        if (root->data > key) {
            if (root->left != NULL && root->left->data == key) {
                root->left = helper(root->left);
                break;
            } else root = root->left;
        } else {
            if (root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            } else root = root->right;
        }
    }
    return dummy;
}

Node* findlastright(Node* root) {
    if (root->right == NULL) return root;
    return findlastright(root->right);
}

Node* helper(Node* root) {
    if (root->left == NULL) return root->right;
    else if (root->right == NULL) return root->left;

    Node* rightchild = root->right;
    Node* lastright = findlastright(root->left);
    lastright->right = rightchild;  
    return root->left;
}

Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 7);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    int key = 3;
    root = deletion(root, key);

    cout << "Inorder after deletion of " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
