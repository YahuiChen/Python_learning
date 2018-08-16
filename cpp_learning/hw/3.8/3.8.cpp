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

    //利用操作符--输出
    Vector<int>::iterator t = v.end() - 1;//注意end()返回的是最后元素之后的位置
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
    //m = v.erase(m);//正确用法
    v.erase(m); //这样是错误的，会使当前迭代器m失效，必须返回新的迭代器，像上面那样用
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