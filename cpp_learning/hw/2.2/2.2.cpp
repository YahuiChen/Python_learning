/*
*ʵ�������Ͷ�ջ����ִ�����в�����
*��ջ����ջ��
*�ж�ջΪ�գ�
*��ӡջ��Ԫ��
*/

#include <iostream> //��������һ��#
using namespace std;
class zhan //�����һ����ĸӦ����Сд
{
private:
#define MAX 20 //�ú������������
    int zhanshuzu[MAX];
    int top;
public:
    zhan() { top = -1; }; //top��ʼ�����������
    void push(int n);
    int pop();
    bool isEmpty();
    bool isFull();
    void dump();
};
void zhan::push(int n) //����Ӧ��д����������
{
    if (isFull())cout << "ջ��"; // ����Ӧ�ü�����
    else {
        ++top;
        zhanshuzu[top] = n;
    }
}
int zhan::pop() //���ﷵ������Ӧ�÷��ھ���
{
    int t = 0; //��������һ������ֵ
    if (isEmpty())cout << "ջ��";// ����Ӧ�ü�����
    else {
        t = zhanshuzu[top]; //��ȡ��ջ��
        zhanshuzu[top] = 0; //ջ���ÿ�
        top--; //ָ������
    }
    return t; //����ջ��
}
bool zhan::isEmpty() //�ж��Ƿ�Ϊ�� //���ﷵ������Ӧ�÷��ھ���
{
    if (top <= -1)return 1;
    else return 0;
}
bool zhan::isFull() //�ж��Ƿ��� //���ﷵ������Ӧ�÷��ھ���
{
    if (top == (MAX - 1))return 1; //��������һ���ֺ�
    else return 0;
}
void zhan::dump() //���ﷵ������Ӧ�÷��ھ���
{
    int i;
    for (i = top; i == 0; i--)
    {
        cout << "��" << i << "��=" << zhanshuzu[i]; // ����ֱ��д��Ա���ɣ���Ҫ����
    }
}
void main()
{
}