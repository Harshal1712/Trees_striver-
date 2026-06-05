#include <bits/stdc++.h>
using namespace std ;

struct Node{
    int data;
    Node *left;
    Node *right ;
    
    Node(int value){
        data=value;
        left=right=NULL;
    }
};
vector<int>inorder(Node *root){
    vector<int>ans;
    stack<Node *>st;
    Node *temp=root;
    
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        else {
            if(st.empty()) break;
            temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            temp=temp->right;
        }
        
    }
    return ans ;
}

int main (){
    Node *root=new Node (10);
    root->left=new Node (11);
    root->right=new Node(19);
    
    root->left->left=new Node(8);
    vector<int>result=inorder(root);
    cout<<"inorder Traversal:"<<endl;
    for (auto x:result){
        cout<<x<<" ";
    }
    cout<<endl;
}