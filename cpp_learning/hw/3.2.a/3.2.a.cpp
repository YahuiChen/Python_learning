#include<iostream>
using namespace std;

class Node {
public:
    int data;       //数据域
    Node *next = NULL;     //指向下一个节点的指针
};

void output(Node *temp)
{
    //Node *temp;
    if (temp == NULL) {
        return;       //链表为空链表,无任何数据元素可输出
    }
    Node *current_node = temp;     //从头结点开始遍历
    while (current_node != NULL) {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << endl;
}

void swapnode(Node * p0)
{
    Node *p, *p1;
    p = p0->next;
    p1 = p->next; // both p and afterp assumed not NULL
    p->next = p1->next;
    p0->next = p1;
    p1->next = p;
}

void main()
{
    Node *temp, *head = new Node;
    head->data = 0;
    temp = head;
    for (int i = 1; i <= 10; i++) {
        Node *node = new Node;      //用new给链表的每一个节点开辟空间
        temp->next = node;
        node->data = i;
        temp = node;
    }

    temp = head;
    output(temp);

    temp = head;
    swapnode(temp);

    temp = head;
    output(temp);
    return;
}