#include<iostream>
using namespace std;

class Node {
public:
    int data;       //������
    Node *next = NULL;     //ָ����һ���ڵ��ָ��
};

void output(Node *temp)
{
    //Node *temp;
    if (temp == NULL) {
        return;       //����Ϊ������,���κ�����Ԫ�ؿ����
    }
    Node *current_node = temp;     //��ͷ��㿪ʼ����
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
        Node *node = new Node;      //��new�������ÿһ���ڵ㿪�ٿռ�
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