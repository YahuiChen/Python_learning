#include <iostream> 
#include <vector>
#include "bsttree.h"
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
void TreeNode::inorder_tree_walk(TreeNode* x)
{
    if (x != NULL)
    {
        inorder_tree_walk(x->left);
        cout << x->key << " ";
        inorder_tree_walk(x->right);
    }
    else
        return;
}
void TreeNode::preorder_tree_walk(TreeNode*x)
{
    if (x)
    {
        cout << x->key << " ";
        preorder_tree_walk(x->left);
        preorder_tree_walk(x->right);
    }
}
//TreeNode TreeNode:: tree_search(TreeNode* x, int k)
//{
//    if (x == NULL || k == x->key)
//        return x;
//    if (k < x->key)
//        return tree_search(x->left, k);
//    else return tree_search(x->right, k);
//}

void TreeNode::tree_insert(TreeNode* T, TreeNode* z) //T是现在的BST的树根
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
        T = z;//T是颗空树
    else if (z->key < y->key)
        y->left = z;
    else y->right = z;
    //	 return T; 
}