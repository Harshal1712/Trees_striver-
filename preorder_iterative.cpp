
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

vector<int>preorder(Node *root){
    vector<int>ans;
    if(root==NULL) return ans ;
    
    stack<Node *>st;
    st.push(root);
   
    while(!st.empty()){
        
        Node *temp=st.top();
        st.pop();
         ans.push_back(temp->data);
        if(temp->right!=NULL){
        st.push(temp->right);
    }
    if(temp->left!=NULL){
        st.push(temp->left);
    }
    
    }
    return  ans ;
}
int main (){
    Node *root=new Node (10);
    root->left=new Node (11);
    root->right=new Node(19);
    
    root->left->left=new Node(8);
    vector<int>result=preorder(root);
    cout<<"Preorder Traversal:"<<endl;
    for (auto x:result){
        cout<<x<<" ";
    }
    cout<<endl;
}