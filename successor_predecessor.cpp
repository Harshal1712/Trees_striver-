
#include <iostream>
using namespace std ;
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
Node *successor(Node *root,int key){
    Node *succ=NULL;
    while(root!=NULL){
        if(key>=root->data){
            root=root->right;
        }
        else {
            succ=root;
            root=root->left;
        }
    }
    return succ;
}
Node *predecessor(Node *root,int key){
    Node *pred=NULL;
    while(root!=NULL){
        if(key<=root->data){
            root=root->left;
        }
        else {
            pred=root;
            root=root->right;
        }
    }
    return pred;
}
int main() {
   
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    int key = 15;
    Node *succ = successor(root, key);
    Node *pred = predecessor(root, key);
    
    
     if (succ)
        cout << "Successor of " << key << " is " << succ->data << endl;
        
    if (pred)
        cout << "Predecessor of " << key << " is " << pred->data << endl;
}
