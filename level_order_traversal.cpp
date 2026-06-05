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
vector<vector<int>>levelorder(Node *root){
    vector<vector<int>>ans ;
    if(root==NULL) return ans;
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for (int i=0;i<size;i++){
            Node *temp=q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);

        }
        ans.push_back(level);
    }
    return ans ;
}
int main (){
 Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

     vector<vector<int>> result = levelorder(root);
    cout << "Level Order Traversal:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Level " << i + 1 << ": ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
