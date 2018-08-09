#ifndef BSTTREE_H
#define BSTTREE_H

#include <iostream> 
#include <vector>
using namespace std;
class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* p;//指向父节点 
public:
    TreeNode();
    TreeNode(int val);
    void inorder_tree_walk( TreeNode* );
    void preorder_tree_walk(TreeNode* );
        // TreeNode* tree_search(TreeNode* , int );
        void tree_insert(TreeNode*, TreeNode* );
};
#endif