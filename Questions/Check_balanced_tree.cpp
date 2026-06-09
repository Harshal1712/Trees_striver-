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

int balance_tree(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Left Height
    int left = balance_tree(root->left);

    if (left == -1)
        return -1;

    // Right Height
    int right = balance_tree(root->right);

    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    return max(left, right) + 1;
}

bool height(Node *root)
{
    return balance_tree(root) != -1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    if (height(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    return 0;
}