#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left ;
    Node *right ;

    public:
    Node (int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node *insert(Node *root,int key){
    if(root==NULL) return new Node(key);

    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else if(key>root->data){
        root->right=insert(root->right,key);
    }
    return root;
}
void traversal(Node *root){
    if(root==NULL) return ;
    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
}
int main (){
    Node *root=NULL;
    root=insert(root,30);
    insert(root,89);
    insert(root,89);
    insert(root,45);
    insert(root,79);
    insert(root,80);
    insert(root,63);

    traversal(root);
    cout<<endl;
    return 0;
}