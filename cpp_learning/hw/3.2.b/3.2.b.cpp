#include<iostream>
using namespace std;

class Node {
public:
    int data;       //数据域
    Node *prev = NULL;
    Node *next = NULL;     //指向下一个节点的指针
};

void output(Node *temp)
{
    Node *ptemp = temp;
    while (ptemp != NULL) {
        cout << ptemp->data << " ";
        ptemp = ptemp->next;
    }
    cout << endl;
}

void swapnode(Node *p)
{
    Node *p1, *p2;
    p1 = p->prev;
    p2 = p->next;
    p->next = p2->next;
    p1->next = p2;
    p2->next = p;
    p->next->prev = p;
    p->prev = p2;
    p2->prev = p1;
}

void main()
{
    Node *head = new Node;
    head->data = 0;
    int i = 0;
    Node *pnew, *ptemp;
    ptemp = head;
    for (i = 1; i <= 9; i++)
    {
        pnew = new Node;
        pnew->data = i;
        pnew->next = NULL;
        pnew->prev = ptemp;
        ptemp->next = pnew;
        ptemp = pnew;
    }

    ptemp = head;
    output(ptemp);

    ptemp = head->next;
    swapnode(ptemp);

    ptemp = head;
    output(ptemp);
    return;
}