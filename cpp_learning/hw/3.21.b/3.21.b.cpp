#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

void testPair()
{
    Stack<string> stack;
    string s(""), expected("");
    while (s != "e" && s != "E")
    {
        cout << "Enter symbols to test, e to end: /n";
        cin >> s;

        if (s == expected)
        {
            stack.pop();
            if (!stack.empty())
            {
                string temp = stack.top();
                if (temp == "(")
                {
                    expected = ")";
                }
                else if (temp == "[")
                {
                    expected = "]";
                }
                else if (temp == "{")
                {
                    expected = "}";
                }
                else if (temp == "/*")
                {
                    expected = "*/";
                }
            }
        }
        else if (s != "e" && s != "E")
        {
            if (s == "(")
            {
                stack.push(s);
                expected = ")";
            }
            else if (s == "[")
            {
                stack.push(s);
                expected = "]";
            }
            else if (s == "{")
            {
                stack.push(s);
                expected = "}";
            }
            else if (s == "/*")
            {
                stack.push(s);
                expected = "*/";
            }
            else
            {
                expected = "";
            }
        }
        else
            break;
    }

    if (stack.empty())
    {
        cout << "You entered symbol form pairs/n";
    }
    else
    {
        cout << "The symbols you entered do not form pairs/n";
    }
}

int main()
{
    while (true)
        testPair();

    return 0;
}