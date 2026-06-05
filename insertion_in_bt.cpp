#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int data;
    Node *right;
    Node *left;

    public:
    Node (int value){
        data=value;
        left=right =NULL;
    }
};

Node *insert(Node *root,int key){
    queue<Node*>q;
   
    if(root==NULL){
        return new Node (key);
    }
    q.push(root);
    while(!q.empty()){
        Node *current =q.front();
        q.pop();

        if(current->left==nullptr){
            current->left=new Node (key);
            return root;
        }
        else {
            q.push(current->left);
           
        }
        if(current->right==nullptr){
            current->right=new Node (key);
            return root;
        }
        else{
            q.push(current->right);
           
        }
    }
    return root;
}
void levelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
}
int main (){
     Node* root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(15);

     cout << "Level Order before insertion: ";
    levelOrder(root);

   
    int key = 8;
    root = insert(root, key);

    cout << "\nLevel Order after insertion: ";
    levelOrder(root);

    return 0;
}