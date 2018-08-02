#include <iostream>
#include "checkBalanceSymbol.h"

void checklang(std::ifstream &ifile)
{
    if (ifile)
    {
        std::stack<char> check;
        //避免空栈导致抛出异常
        check.push('!');
        //string testall("()[]{}*/");
        std::string pushin("([{*");
        std::string popout(")]}/");
        char prev = '\0';
        char curr;
        ifile >> curr;
        while (!ifile.eof())
        {
            //如果栈首为注释符，则除非出现反注释，否则全部跳过
            if (check.top() == '/')
            {
                if (prev == '*' && curr == '/')
                    check.pop();
            }
            else
            {
                //如果检测到开始标志
                if (pushin.find(curr) != std::string::npos)
                {
                    //如果是单对应符则直接入栈
                    if (curr != '*')
                        check.push(curr);
                    //如果是注释则入栈
                    else if (prev == '/')
                        check.push('/');
                    //否则，必然有curr == '*', 而prev != '/'，不作处理继续运行
                }
                //如果检测到结束标志
                else if (popout.find(curr) != std::string::npos)
                {
                    //如果是三个单对应符号
                    //则可对应即弹出，不可对应则跳出并将报错
                    if (curr == ')')
                    {
                        if (check.top() == '(')
                            check.pop();
                        else
                            break;
                    }
                    else if (curr == ']')
                    {
                        if (check.top() == '[')
                            check.pop();
                        else
                            break;
                    }
                    else if (curr == '}')
                    {
                        if (check.top() == '{')
                            check.pop();
                        else
                            break;
                    }
                    //如果是反注释
                    else if (prev == '*')
                    {
                        if (check.top() == '/')
                            check.pop();
                        else
                            break;
                    }
                    //如果不是反注释则不做任何操作
                }
            }
            //读取下一个字符
            prev = curr;

            ifile >> curr;
        }
        //如果curr未到达文件尾
        //必然是因为错误的单符号对应而跳出循环
        if (!ifile.eof())
        {
            std::cout << curr << " and " << check.top() << std::endl;
            std::cout << "Incorrect pop!" << std::endl;
        }
        //如果到达文件尾后，栈首不是初始的'!'
        //必有后半平衡符缺失
        else if (check.top() != '!')
            std::cout << "Missing ending!" << std::endl;
        else
            std::cout << "Success" << std::endl;
        while (!check.empty())                    //释放空间
            check.pop();
    }
    else
        std::cout << "Cannot find stream!" << std::endl;
}