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

vector<int> postorder(Node *root)
{
    vector<int> ans;
    stack<Node*> st;
    Node *curr = root;

    while(curr != NULL || !st.empty())
    {
        if(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;

            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }

    return ans;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(19);

    root->left->left = new Node(8);

    vector<int> result = postorder(root);

    cout << "Postorder Traversal: ";

    for(auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}