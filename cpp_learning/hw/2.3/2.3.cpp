#include <iostream>
#include <vector>
#include "BSTree.h"
using namespace std;

int main() {
    TreeNode* T = new TreeNode(1);
    TreeNode b;
    int a[10] = { 6,18,3,7,17,20,2,4,13,9 };
    int c;
    for (int i = 0; i < 10; i++)
    {
        TreeNode* z = new TreeNode(a[i]);
        b.tree_insert(T, z);
    }

    cout << "inorder    ";
    b.inorder(T);
    cout << endl;
    cout << "preorder   ";
    b.preorder(T);
    cout << endl;
    cout << "postorder  ";
    b.postorder(T);
    cout << endl;

    cout << "input a integer:";
    cin >> c;
    TreeNode* z = new TreeNode(c);
    b.tree_insert(T, z);
    cout << "inorder    ";
    b.inorder(T);
    cout << endl;
}