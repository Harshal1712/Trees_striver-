#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    bool lthread;
    bool rthread;

public:
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
        lthread=rthread=true;
    }
};
Node *insert(Node *root,int key){
    Node *ptr=root;
    Node *par=NULL;

    while(ptr!=NULL){
        if(key==ptr->data){
            cout<<"Duplicate Data "<<endl;
            return root;
        }
        par=ptr;
        if(key < ptr->data){
            if(ptr->lthread==false){
                ptr=ptr->left;
            }
            else break;
        }
        else {
            if(ptr->rthread==false) ptr=ptr->right;
            else break;
        }
    }
    Node *temp=new Node(key) ;
    temp->data=key;
    temp->lthread=true;
    temp->rthread=true;

    if(par==NULL){
        root=temp;
        temp->right=NULL;
        temp->left=NULL;
    }
    else if (key<par->data){
           temp->left=par->left;
            temp->right=par;
            par->lthread=false;
            par->left=temp;
        }
        else {
             temp->left=par;
            temp->right=par->right;
            par->rthread=false;
            par->right=temp;
        }

    return root;
}
Node *inordersuccessor(Node *ptr){
    if(ptr->rthread){
        return ptr->right;
}
ptr=ptr->right;
while(ptr->lthread==false){
    ptr=ptr->left;

}
return ptr;

}
void inordertrav(Node *root) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    // Find leftmost node
    Node *ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = inordersuccessor(ptr);
    }
}
int main(){
      Node *root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);

    cout << "Inorder traversal of threaded binary tree: ";
    inordertrav(root);

}
