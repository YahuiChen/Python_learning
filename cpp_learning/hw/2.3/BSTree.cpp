#include <iostream>
#include <vector>
#include "BSTree.h"
using namespace std;

TreeNode::TreeNode()
{
    key = 0;
    left = right = p = NULL;
}
TreeNode::TreeNode(int val)
{
    key = val;
    left = right = p = NULL;
}
void TreeNode::inorder(TreeNode* x)
{
    if (x != NULL)
    {
        inorder(x->left);
        cout << x->key << " ";
        inorder(x->right);
    }
    else
        return;
}
void TreeNode::preorder(TreeNode*x)
{
    if (x)
    {
        cout << x->key << " ";
        preorder(x->left);
        preorder(x->right);
    }
}

void TreeNode::postorder(TreeNode*x)
{
    if (x)
    {
        postorder(x->left);
        postorder(x->right);
        cout << x->key << " ";
    }
}

void TreeNode::tree_insert(TreeNode* T, TreeNode* z) //TÊÇ¸ù
{
    TreeNode * y, *x = T;
    while (x)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else x = x->right;
    }
    z->p = y;
    if (!y)
        T = z;
    else if (z->key < y->key)
        y->left = z;
    else y->right = z;
}