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

bool solve(Node * p,Node * q){
    if(p==NULL && q==NULL) return true ;
   if(p==NULL || q==NULL) return false;

   if(p->data !=q->data) return false;

   return solve(p->left,q->left) && solve(p->right,q->right); 
}
int main (){
      Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (solve(root1, root2))
        cout << "Trees are Identical" << endl;
    else
        cout << "Trees are Not Identical" << endl;

    return 0;
}