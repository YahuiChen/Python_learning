#include "vector.h"
#include <iostream>
using namespace std;

int main()
{
    Vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(i);

    for (int i = 0; i < 10; i++)
        cout << v[i] << " ";

    //���ò�����--���
    Vector<int>::iterator t = v.end() - 1;//ע��end()���ص������Ԫ��֮���λ��
    cout << endl;
    for (; t >= v.begin(); t--) {
        cout << *t << " ";
    }

    cout << endl;
    Vector<int>::iterator k = v.begin();
    while (!v.isEnd()) {
        cout << *k << " ";
        k = v.next();
    }

    Vector<int>::iterator m = v.begin() + 6;
    //m = v.erase(m);//��ȷ�÷�
    v.erase(m); //�����Ǵ���ģ���ʹ��ǰ������mʧЧ�����뷵���µĵ�������������������
    cout << "\nerase:" << *m << endl;

    for (m = v.begin(); m != v.end(); ) {
        cout << *m << " ";
        m = v.next();
    }

    Vector<int>::iterator mm = v.begin() + 2;
    mm = v.insert(mm, 5);
    cout << endl;
    for (; mm != v.end(); ++mm) {
        cout << *mm << " ";
    }

    return 0;
}