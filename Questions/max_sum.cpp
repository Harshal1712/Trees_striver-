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
int maxi=INT_MIN;
int solve(Node * root){
    
    if(root==NULL) return 0;
    int left=max(0,solve(root->left));
    int right=max(0,solve(root->right));

    maxi=max(maxi,left+right+root->data);
    return max(left,right)+root->data;
}

int diameter(Node * root){
     solve(root);
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

    cout << "Max sum is : " << ans << endl;

    return 0;
}
