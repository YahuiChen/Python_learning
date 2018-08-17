#include<iostream>
#include<algorithm>
using namespace std;

typedef struct BinaryTreeNode {
    int value;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
}BTNode;

int max_height = -1;

void addBTNode(BTNode *&myBT, int val);//添加节点
void createBT(BTNode *&BT, int arr[], int n);//创建二叉排序树,通过*&来改变指针的值

void midorder_showBT(BTNode *myBT);//中序遍历打印，如果是二叉排序树，打印结果与单调递增数组一样

int b[100];
int idx = 0;
void is_BST(BTNode *myBT);//判断是否是二叉排序树

int main() {
    BTNode *myBT = nullptr;

    int arr[10] = { 314,426,12,78,143,8,21,14,9,314 };
    createBT(myBT, arr, 10);

    midorder_showBT(myBT);
    cout << endl;

    is_BST(myBT);
    bool isBT = true;
    if (idx == 1 || idx == 0)
        cout << "是BST" << endl;
    else {
        for (int i = 0; i < idx - 1; i++) {
            if (b[i] >= b[i + 1]) {
                isBT = false;
                break;
            }
        }
        if (isBT)
            cout << "是BST" << endl;
        else
            cout << "不是BST" << endl;
    }

    return 0;
}

void is_BST(BTNode *myBT) {
    if (myBT == nullptr)
        return;
    is_BST(myBT->m_pLeft);
    b[idx++] = myBT->value;
    is_BST(myBT->m_pRight);
}

void createBT(BTNode *&BT, int arr[], int n) {
    BT = nullptr;
    for (int i = 0; i < n; i++)
        addBTNode(BT, arr[i]);
}

void addBTNode(BTNode *&myBT, int val) {
    if (myBT == nullptr) {
        myBT = new BinaryTreeNode();
        myBT->value = val;
        myBT->m_pLeft = nullptr;
        myBT->m_pRight = nullptr;
        return;
    }

    if (val == myBT->value) {
        return;
    }
    else if (val < myBT->value) {
        addBTNode(myBT->m_pLeft, val);
    }
    else {
        addBTNode(myBT->m_pRight, val);
    }
}

void midorder_showBT(BTNode *myBT) {//中序遍历打印 {
    if (myBT == nullptr)
        return;

    midorder_showBT(myBT->m_pLeft);
    cout << myBT->value << " ";
    midorder_showBT(myBT->m_pRight);
}