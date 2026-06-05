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

void traversals( Node * root){
     vector<int>preorder;
    vector<int>inorder;
    vector<int>postorder;
    
    stack<pair<Node * ,int>>st;
    st.push({root,1});
    while(!st.empty()){
        pair<Node * ,int>p=st.top();
        st.pop();
        if(p.second==1){
            preorder.push_back(p.first->data);
            p.second++;
            st.push(p);
            if(p.first->left!=NULL){
                st.push({p.first->left,1});
            }
        }
        if(p.second==2){
            inorder.push_back(p.first->data);
            p.second++;
            st.push(p);
            if(p.first->right!=NULL){
                st.push({p.first->right,1});
            }
        }
        else {
            postorder.push_back(p.first->data);
        }
    }
    cout << "Preorder : ";
    for(auto x : preorder)
        cout << x << " ";

    cout << endl;

    cout << "Inorder : ";
    for(auto x : inorder)
        cout << x << " ";

    cout << endl;

    cout << "Postorder : ";
    for(auto x : postorder)
        cout << x << " ";

    cout << endl;

} 

int main (){
     Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(19);
    root->left->left = new Node(8);

    traversals(root);
}