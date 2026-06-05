#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> postorder(Node* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        ans.push_back(node->data); 

        if (node->left) st.push(node->left);    
        if (node->right) st.push(node->right);  
    }

    reverse(ans.begin(), ans.end()); 
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> result = postorder(root);

    cout << "Postorder Traversal: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
