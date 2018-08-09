#include <iostream> 
#include <vector>
#include "bsttree.h"
using namespace std;
//class TreeNode {
//public:
//    int key;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode* p;//指向父节点 
//public:
//    TreeNode();
//    TreeNode(int val);
//
//};
//TreeNode::TreeNode()
//{
//    key = 0;
//    left = right = p = NULL;
//}
//TreeNode::TreeNode(int val)
//{
//    key = val;
//    left = right = p = NULL;
//}
//void inorder_tree_walk(TreeNode* x)
//{
//    if (x != NULL)
//    {
//        inorder_tree_walk(x->left);
//        cout << x->key << " ";
//        inorder_tree_walk(x->right);
//    }
//    else
//        return;
//}
//void preorder_tree_walk(TreeNode*x)
//{
//    if (x)
//    {
//        cout << x->key << " ";
//        preorder_tree_walk(x->left);
//        preorder_tree_walk(x->right);
//    }
//}
//TreeNode* tree_search(TreeNode* x, int k)
//{
//    if (x == NULL || k == x->key)
//        return x;
//    if (k < x->key)
//        return tree_search(x->left, k);
//    else return tree_search(x->right, k);
//}
//
////c插入
//void tree_insert(TreeNode* T, TreeNode* z) //T是现在的BST的树根
//{
//    TreeNode * y, *x = T;
//    while (x)
//    {
//        y = x;
//        if (z->key < x->key)
//            x = x->left;
//        else x = x->right;
//    }
//    z->p = y;
//    if (!y)
//        T = z;//T是颗空树
//    else if (z->key < y->key)
//        y->left = z;
//    else y->right = z;
//    //	 return T; 
//}


int main() {
    TreeNode* T = new TreeNode(15);
    //inorder_tree_walk(T);
    int a[10] = { 6,18,3,7,17,20,2,4,13,9 };
    for (int i = 0; i < 10; i++)
    {
        TreeNode* z = new TreeNode(a[i]);
        tree_insert(T, z);
    }
    inorder_tree_walk(T);
    cout << endl;
    preorder_tree_walk(T);
}