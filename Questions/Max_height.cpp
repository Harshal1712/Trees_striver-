#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};


int maxdepth(Node * root){
    if(root==NULL) return 0;

    int left=maxdepth(root->left);
    int right=maxdepth(root->right);

    return 1+max(left,right);


}
int main (){
  Node *root=new Node (10);
    root->left=new Node (11);
    root->right=new Node(19);
    
    root->left->left=new Node(8);
    
    cout<<"Max depth of the tree is ";
    cout<<maxdepth(root);
}
