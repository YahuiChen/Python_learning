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
    TreeNode* p;//ָ�򸸽ڵ�
public:
    TreeNode();
    TreeNode(int val);
    void inorder(TreeNode*);
    void preorder(TreeNode*);
    void postorder(TreeNode*);
    void tree_insert(TreeNode*, TreeNode*);
};
#endif