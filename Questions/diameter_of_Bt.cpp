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
int maxi=0;
int height(Node * root){
    
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);

    maxi=max(maxi,left+right);
    return max(left,right)+1;
}

int diameter(Node * root){
    return height(root);
    return maxi;
}
int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int ans = diameter(root);

    cout << "Diameter of Tree = " << ans << endl;

    return 0;
}