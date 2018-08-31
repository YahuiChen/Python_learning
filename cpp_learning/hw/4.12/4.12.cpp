#include "map.h"
//#include <set>
//#include <utility>
#include <iostream>
using namespace std;
//using std::endl;
//using std::string;

void main()
{
    int a;
    /*
     set<pair<int, int> > s;
     s.insert(make_pair(3, 1));
     s.insert(make_pair(3, 2));
     s.insert(make_pair(1, 1));
     s.insert(make_pair(1, 2));
     s.insert(make_pair(2, 5));
     s.insert(make_pair(2, 4));
     set<pair<int, int> > ::iterator it;
     for (it = s.begin(); it != s.end(); it++)
         cout << it->first << ' ' << it->second << "\n";
     it = s.upper_bound(make_pair(2, 4));
     if (it != s.end())
         printf("(2,4)后面接着是%d %d\n", it->first, it->second);*/

    Map<string, int> m;
    m["Jack"] = 98;
    m["Bimi"] = 96;
    m["Kate"] = 97;
    // m.insert(make_pair("back", 1);
    Map<string, int>::iterator it;

    ////先前遍历元素
    //Map<string, int> ::iterator it;
    //for (it = m.begin(); it != m.end(); it++)
    //{
    //    //cout << it->first << " : " << (*it)->second << endl;
    //}
    cout << m["Jack"] << endl;

    //s return 0;
}